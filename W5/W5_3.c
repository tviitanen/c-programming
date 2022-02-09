#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct henkilo {
char nimi[30];
int ika;
};
typedef struct henkilo HENKILO;


void kopioi(HENKILO *pHlo){
    for (int i = 0; i < 2; i++){
        pHlo[1] = pHlo[0];
        pHlo[1] = pHlo[0];
    }

    return;
}

int main(void){
    HENKILO *pHlo;
    if ((pHlo = (HENKILO*)malloc(sizeof(HENKILO))) == NULL ){
        perror("Muistin varaus epäonnistui");
        exit(0);
    }
    printf("Anna ensimmäisen henkilön etunimi: ");
    scanf("%s", pHlo[1].nimi);
    getchar();
    printf("Anna ensimmäisen henkilön ikä: ");
    scanf("%d", &pHlo[1].ika);
    getchar();
    printf("Anna toisen henkilön etunimi: ");
    scanf("%s", pHlo[0].nimi);
    getchar();
    printf("Anna toisen henkilön ikä: ");
    scanf("%d", &pHlo[0].ika);
    getchar();

    if ((pHlo[1].nimi != pHlo[0].nimi) && (pHlo[1].ika != pHlo[0].ika)){
        printf("Annetut tiedot eivät ole samoja.\n");
    }
    else
    {
        printf("Annetut tiedot ovat samoja.\n");
    }
    kopioi(pHlo);
    if ((pHlo[1].nimi != pHlo[0].nimi) && (pHlo[1].ika != pHlo[0].ika)) {
        printf("Kopioinnin jälkeen tietueiden tiedot eivät ole samoja.\n");
    }
    else{
        printf("Kopioinnin jälkeen tietueiden tiedot ovat samoja.\n");
    }
    if ((&pHlo[1].nimi != &pHlo[0].nimi) && (&pHlo[1].ika != &pHlo[0].ika))
    {
        printf("Kopioinnin jälkeen tietueiden osoitteet eivät ole samoja.\n");
    }
    else
    {
        printf("Kopioinnin jälkeen tietueiden osoitteet ovat samoja.\n");
    }
    free(&pHlo);
    printf("Muisti vapautettu.\n");
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}