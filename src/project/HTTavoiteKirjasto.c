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
 * - 
 * - 
 */
/*************************************************************************/
/* Tavoitetaso, HTTavoiteKirjasto.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "HTPerusKirjasto.h"

VKTUOTANTO *viikkoAnalyysi(LISTA *pAlku){
    int i, viikko, viikkoMax = 0, aurinko, vesi, tuuli, ydin, lampo, yhteensa;
    
    LISTA *pTemp = pAlku;
    VKTUOTANTO *pTaulukko = NULL;

    while (pTemp != NULL){ // selvitetään suurin viikko
        if (pTemp->viikko > viikkoMax){
            viikkoMax = pTemp->viikko;
        }
        pTemp = pTemp->pSeuraava;
    }
    // Varataan muisti suurimman viikon mukaiselle määrälle structeja
    // huom! calloc alustaa arvot nolliksi
    if ((pTaulukko = (VKTUOTANTO *)calloc(viikkoMax, sizeof(VKTUOTANTO))) == NULL){
        perror("Muistinvaraus epäonnistui.");
        printf("\n");
        exit(0);
    }
    pTemp = pAlku; // osoitin takaisin alkuun

    while (pTemp != NULL){
        viikko = pTemp->viikko;
        for (i = 0; i < viikkoMax; i++){ // lasketaan viikottaiset tuotannot/laji ja lisätään listaan
            pTaulukko[i].viikko = i + 1;
            if (viikko == i + 1){

                aurinko = pTaulukko[i].aurinko + pTemp->aurinko;
                tuuli = pTaulukko[i].tuuli + pTemp->tuuli;
                vesi = pTaulukko[i].vesi + pTemp->vesi;
                ydin = pTaulukko[i].ydin + pTemp->ydin;
                yhteensa = pTaulukko[i].yht + pTemp->yht;
                lampo = pTaulukko[i].lampo + pTemp->errLampo;
                pTaulukko[i].aurinko = aurinko;
                pTaulukko[i].tuuli = tuuli;
                pTaulukko[i].vesi = vesi;
                pTaulukko[i].ydin = ydin;
                pTaulukko[i].yht = yhteensa;
                pTaulukko[i].lampo = lampo;
            }
        }
        pTemp = pTemp->pSeuraava;
    }
    pTaulukko[i].viikko = NULL; // asetetaan NULL viimeiseksi
    printf("Viikoittaiset tuotannot analysoitu.\n");
    return pTaulukko;
}

void tallennaViikko(VKTUOTANTO *pMatriisi, char *tiedostoNimi){
    FILE *tiedosto;
    VKTUOTANTO *ptr = pMatriisi;

    if ((tiedosto = fopen(tiedostoNimi, "w")) == NULL){
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    fprintf(tiedosto, "Viikko;Aurinkovoima;Tuulivoima;Vesivoima;Ydinvoima;Yhteistuotanto;Lämpövoima\n");
    while(ptr->viikko != NULL) {
        fprintf(tiedosto, "Vko %d;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f\n", ptr->viikko, (float)(ptr->aurinko) / 1000000, (float)(ptr->tuuli) / 1000000, (float)(ptr->vesi) / 1000000, (float)(ptr->ydin) / 1000000, (float)(ptr->yht) / 1000000, (float)(ptr->lampo)/1000000);
        ptr++;
    }
    printf("Tiedosto '%s' kirjoitettu.\n", tiedostoNimi);
    fclose(tiedosto);

    return;
}

/* eof */
