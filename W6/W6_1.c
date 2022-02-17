#include <stdio.h>
#include <stdlib.h>

// Minimaalinen tietue listalle
typedef struct lista{
    int iNumero;
    struct lista *pSeuraava;
} LISTA;

int main(void){
    LISTA *pAlku = NULL, *pLoppu = NULL; // Osoittimia listan käyttöön
    LISTA *pUusi, *ptr; // Apuosoitin muistin varaukseen ja liukuri
    int luku, lkm;
    // Kysytään käyttäjältä luvut
    printf("Anna listan luvut.\n");
    do{
        printf("Anna positiivinen kokonaisluku, 0 lopettaa: ");
        scanf("%d", &luku);
        lkm++;
        if (luku == 0){
            break;
        }
        // Muistin varaus
        if ((pUusi = (LISTA *)malloc(sizeof(LISTA))) == NULL){
            perror("Muistin varaus epäonnistui");
            exit(0);
        }
        // Uuden alkion jäsenmuuttujien arvojen asettaminen
        pUusi->iNumero = luku;
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

    }while (luku != 0);

    // Listan läpikäynti
    ptr = pAlku;
    printf("Listassa on seuraavat luvut: ");
    while (ptr != NULL){
        printf("%d ", ptr->iNumero);
        ptr = ptr->pSeuraava;
    }
    // Muistin vapauttaminen
    ptr = pAlku;
    while (ptr != NULL){
        pAlku = ptr->pSeuraava;
        free(ptr);
        ptr = pAlku;
    }
    printf("\nKiitos ohjelman käytöstä.\n");
    return (0);
}