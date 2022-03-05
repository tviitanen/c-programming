/*************************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Tekijä: Teemu Viitanen
 * Opiskelijanumero: 00456573
 * Päivämäärä: 1.3.2022
 * Palauttamalla tämän työn arvioitavaksi vakuutan, että
 * 1) Olen itse kirjoittanut kaiken tässä tiedostossa olevan koodin
 * 2) En ole antanut tätä koodia kenenkään muun käyttöön
 *
 * Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
 * lähteet ja henkilöt, ja se näkyy koodissa seuraavissa kohdissa:
 * - Stackoverflow: memset & struct tm
 * - 
 */
/*************************************************************************/
/* Tavoitetaso, HTPerusKirjasto.c */

#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "HTPerusKirjasto.h"

LISTA *lueTiedosto(LISTA *pAlku, char *tiedostoNimi){
    char aRivi[3*MAXLEN];

    FILE *tiedosto;
    
    if ((tiedosto = fopen(tiedostoNimi, "r")) == NULL){
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    LISTA *pUusi;
    fgets(aRivi, 3*MAXLEN, tiedosto); // Otsikkorivi pois

    while(fgets(aRivi, 3*MAXLEN, tiedosto) != NULL){ // luetaan tiedosto rivi kerrallaan
        if ((pUusi = (LISTA *)malloc(sizeof(LISTA))) == NULL){ // varataan muisti
            perror("Muistinvaraus epäonnistui.");
            printf("\n");
            exit(0);
        }
        
        // erotellaan tiedot riviltä ja lisätään structiin
        char *aika = strtok(aRivi, ";");
        strcpy(pUusi->pvm, aika);
        pUusi->viikko = atoi(strtok(NULL, ";"));
        pUusi->kulutus = atoi(strtok(NULL, ";"));
        pUusi->aurinko = atoi(strtok(NULL, ";"));
        pUusi->tuuli = atoi(strtok(NULL, ";"));
        pUusi->vesi = atoi(strtok(NULL, ";"));
        pUusi->ydin = atoi(strtok(NULL, ";"));
        pUusi->yht = atoi(strtok(NULL, ";"));
        pUusi->errLampo = atoi(strtok(NULL, ";"));
        pUusi->pSeuraava = NULL;

        // lisätään struct linkitettyyn listaan
        if (pAlku == NULL){
            pAlku = pUusi;
        }
        else{
            LISTA *pTemp = pAlku;
            while (pTemp->pSeuraava != NULL)
                pTemp = pTemp->pSeuraava;
                pTemp->pSeuraava = pUusi;
        }
    }
    fclose(tiedosto);
    printf("Tiedosto '%s' luettu.\n", tiedostoNimi);

    return (pAlku);
}


TULOKSET analysoiTiedot(LISTA *pAlku){
    TULOKSET tulos;
    int i = 0;
    long int kokonaisKulutus = 0;
    char aikaMax[MAXLEN], aikaMin[MAXLEN];
    LISTA *pTemp = pAlku;

    int min = 10000000, max = 0;
    double ka = 0;

    // käydään linkitetty lista läpi
    while (pTemp != NULL){
        if ((pTemp->kulutus) > max){ // selvitetään suurin kulutus & aika
            max = pTemp->kulutus;
            strcpy(aikaMax, pTemp->pvm);            
        }
        if ((pTemp->kulutus) < min){ // selvitetään pienin kulutus & aika
            min = pTemp->kulutus;
            strcpy(aikaMin, pTemp->pvm);
        }
        i++;
        kokonaisKulutus = kokonaisKulutus + pTemp->kulutus;
        pTemp = pTemp->pSeuraava;
    }

    ka = (double)kokonaisKulutus/i; // typecast, että saa desimaalit
    // lisätään saadut tiedot structiin
    tulos.lkm = i;
    tulos.kulutus = kokonaisKulutus;
    tulos.keskiarvo = ka;
    tulos.maxKulutus = max;
    strcpy(tulos.maxAika, aikaMax);
    tulos.minKulutus = min;
    strcpy(tulos.minAika, aikaMin);
    printf("Analysoitu %d mittaustulosta.\n", i);
    printf("Kokonaiskulutus oli yhteensä %ld kWh.\n", kokonaisKulutus);
    
    return(tulos);
}


KKTUOTANTO *kuukausiAnalyysi(LISTA *pAlku){
    long int kuukausiTuotanto = 0;
    char kk[5];
    int i=0;
    KKTUOTANTO *pTaulukko; // Taulukko kk tuotannoille
    struct tm tm; // Tietue ajan käsittelyyn
    LISTA *pTemp = pAlku;
    // Varataan muisti 12 structille
    // huom! calloc alustaa arvot nolliksi
    if ((pTaulukko = (KKTUOTANTO *)calloc(12, sizeof(KKTUOTANTO))) == NULL){
        perror("Muistinvaraus epäonnistui.");
        printf("\n");
        exit(0);
    }

    while (pTemp != NULL){ // käydään linkitetty lista läpi
        // Tunnistetaan kuukausi kk
        memset(&tm, 0, sizeof(tm));
        strptime(pTemp->pvm, "%d.%m.%y %H:%M:%S", &tm);
        strftime(kk, sizeof(kk), "%m", &tm);

        for(i = 0; i<12; i++) { // lasketaan kuukausittaiset tuotannot ja lisätään taulukkoon
            pTaulukko[i].kuukausi = i+1; // kuukausi numerot
            if (atoi(kk) == i+1){
                kuukausiTuotanto = pTaulukko[i].tuotanto + pTemp->yht + pTemp->aurinko + pTemp->errLampo + pTemp->tuuli + pTemp->vesi + pTemp->ydin;
                pTaulukko[i].kuukausi = atoi(kk);
                pTaulukko[i].tuotanto = kuukausiTuotanto;
            }
        }
        pTemp = pTemp->pSeuraava;
    }

    printf("Kuukausittaiset tuotannot analysoitu.\n");
    return pTaulukko;
    }


void tallennaTiedot(TULOKSET tulos, KKTUOTANTO aTaulukko[], char *tiedostoNimi){

    // TULOSTETAAN NÄYTÖLLE
    printf("Tilastotiedot %d mittaustuloksesta:\n", tulos.lkm);
    printf("Kulutus oli yhteensä %ld kWh, ja keskimäärin %.1f kWh.\n", tulos.kulutus, tulos.keskiarvo);
    printf("Suurin kulutus, %d kWh, tapahtui %s.\n", tulos.maxKulutus, tulos.maxAika);
    printf("Pienin kulutus, %d kWh, tapahtui %s.\n\n", tulos.minKulutus, tulos.minAika);
    printf("Pvm;Tuotanto (GWh)\n");
    for (int i=0; i<12;i++) {
        printf("Kk %d;%.2lf\n", aTaulukko[i].kuukausi, (float)aTaulukko[i].tuotanto / 1000000);
    }

    FILE *tiedosto;
    if ((tiedosto = fopen(tiedostoNimi, "w")) == NULL){
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }        
    // TULOSTETAAN TIEDOSTOON
    fprintf(tiedosto, "Tilastotiedot %d mittaustuloksesta:\n", tulos.lkm);
    fprintf(tiedosto, "Kulutus oli yhteensä %ld kWh, ja keskimäärin %.1f kWh.\n", tulos.kulutus, tulos.keskiarvo);
    fprintf(tiedosto, "Suurin kulutus, %d kWh, tapahtui %s.\n", tulos.maxKulutus, tulos.maxAika);
    fprintf(tiedosto, "Pienin kulutus, %d kWh, tapahtui %s.\n\n", tulos.minKulutus, tulos.minAika);
    fprintf(tiedosto, "Pvm;Tuotanto (GWh)\n");

    for (int i=0; i<12;i++) { // tulostetaan kk analyysi
        fprintf(tiedosto, "Kk %d;%.2lf\n", aTaulukko[i].kuukausi, (float)aTaulukko[i].tuotanto / 1000000);
    }

    printf("Tiedosto '%s' kirjoitettu.\n", tiedostoNimi);
    fclose(tiedosto);

    return;
}


LISTA *vapautaMuisti(LISTA *pAlku){
    LISTA *ptr = pAlku;
    while (ptr != NULL){
        pAlku = ptr->pSeuraava;
        free(ptr);
        ptr = pAlku;
    }

    return (pAlku);
}

/* eof */
