#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxLenght 50

typedef struct henkilo {
    char tunnus[maxLenght];
    char salasana[maxLenght];
    int ID;
    } HENKILO;

int valikko() {
    int valinta;
    printf("Valitse haluamasi toiminto:\n");
    printf("1) Lisää uusi tunnus\n");
    printf("2) Tulosta tunnukset\n");
    printf("0) Lopeta\n");
    printf("Valintasi: ");
    scanf("%d", &valinta);
    getchar();
    return valinta;
}

int main(void) {
    HENKILO hlot[maxLenght];
    HENKILO *pHlo = hlot;
    int i, valinta, lkm=0;
    printf("Käyttäjätunnusten hallinta.\n");
    do {
        valinta = valikko();
        if (valinta == 1) {
            printf("\nAnna käyttäjätunnus: ");
            scanf("%s", pHlo->tunnus);
            getchar();
            printf("Anna salasana: ");
            scanf("%s", pHlo->salasana);
            pHlo->ID = lkm;
            lkm++,
            getchar();
            printf("Tunnus '%s' lisättiin listaan.\n\n", hlot[lkm-1].tunnus); pHlo++;
        
        }
        else if (valinta == 2) {
            printf("\nListalla olevat tunnukset:\n");
            for (i=0; i<lkm; i++){
                printf("%d. tunnus '%s', salasana '%s', ID '%d'.\n", i+1, hlot[i].tunnus, hlot[i].salasana, hlot[i].ID);
            }
            printf("\n");
        }
        else if (valinta == 0) {
            printf("\nKiitos ohjelman käytöstä.\n");
        }
        else {
            printf("\nTuntematon valinta.\n");    
        }
    } while (valinta != 0);
    return(0);
}