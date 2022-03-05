#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Minimaalinen tietue listalle
typedef struct lista{
    char iMerkki;
    char iVuosimalli;
    struct lista *pSeuraava;
} LISTA;

LISTA *createList(char *tiedostoNimi, LISTA *pAlku){
    char aRivi[50];
    printf("Luetaan tiedot tiedostosta %s.\n", tiedostoNimi);
    FILE *tiedosto;
    if ((tiedosto = fopen(tiedostoNimi, "r")) == NULL) {
        perror("Tiedoston avaus epäonnistui.\n");
        exit(0);
    }
    LISTA *pLoppu = NULL; // Osoittimia listan käyttöön
    LISTA *pUusi, *ptr; // Apuosoitin muistin varaukseen ja liukuri
    char merkki;
    char vuosimalli;
    while (fgets(aRivi, 52, tiedosto) != NULL) {
        if ((pUusi = (LISTA *)malloc(sizeof(LISTA))) == NULL){
            perror("Muistinvaraus epäonnistui.\n");
            exit(0);
        }
        merkki = strtok(aRivi, " ");
        vuosimalli = strtok(NULL, " ");
        // Uuden alkion jäsenmuuttujien arvojen asettaminen
        pUusi->iMerkki = merkki;
        pUusi->iVuosimalli = vuosimalli;
        pUusi->pSeuraava = NULL;
        // Uuden alkion lisääminen listaan viimeiseksi alkioksi
        if (pAlku == NULL){ // lista on tyhjä, joten
            pAlku = pUusi; // tehdään ensimmäinen alkio
            pLoppu = pUusi;
            }
        else{ // lista ei ole tyhjä, joten lisätään loppuun
            pLoppu->pSeuraava = pUusi;
            pLoppu = pUusi;
        }
    }
    printf("Tiedot luettu linkitettyyn listaan.\n");
    fclose(tiedosto);
    return(pAlku);
}
LISTA *tulostaTiedot(LISTA *pAlku){
    LISTA *ptr = pAlku;
    int i = 1;
    while (ptr != NULL){
        printf("%d. ajoneuvo: %c vuosimalli %c.\n", i, ptr->iMerkki, ptr->iVuosimalli);
        ptr = ptr->pSeuraava;
        i++;
    }
    return(pAlku);
}
LISTA *vapautaMuisti(LISTA * pAlku){
    LISTA *ptr = pAlku;
    while (ptr != NULL){
        pAlku = ptr->pSeuraava;
        free(ptr);
        ptr = pAlku;
    }
    printf("Muisti vapautettu.\n");
    return(pAlku);
}
int main(int argc, char *argv[]){
    LISTA *pAlku = NULL;
    if (argc < 2) {
        printf("Et antanut tiedoston nimeä.\n");
		printf("Kiitos ohjelman käytöstä.\n");
        exit(0);
    }
    pAlku = createList(argv[1], pAlku);
    pAlku = tulostaTiedot(pAlku);
    pAlku = vapautaMuisti(pAlku);
    printf("Kiitos ohjelman käytöstä.\n");
    return (0);
}