#include <stdio.h>
#define TRUE 1
#define FALSE 0

int main(void) {
    int valikko, i=0, jatka = 1, pituus = 0;
    char merkki, *ptr;
    char merkkijono[200];
while (jatka == TRUE) {
    printf("\nValikko\n");
    printf("1) Lisää uusi merkki\n");
    printf("2) Tyhjennä merkkijono\n");
    printf("3) Tulosta merkkijono\n");
    printf("0) Lopeta\n");
    printf("Valintasi: ");
    scanf("%d", &valikko);

        switch (valikko) {
            case 1:
                if (pituus <=200) {
                    printf("\nAnna jokin merkki: ");
                    scanf(" %c", &merkki);
                    merkkijono[pituus] = merkki;
                    pituus++;
                    }
                else {
                    printf("\nMerkkijonoon ei mahdu enempää merkkejä.\n");
                }
                break;
            case 2:
                if (merkkijono[0] == ' ') {
                    printf("\nMerkkijono on tyhjä.\n");
                }
                else {
                    for (i=0; i<=pituus; i++) {
                        merkkijono[i]= ' ';
                    }
                    pituus = 0;
                    printf("\nMerkkijono on tyhjennetty.\n");
                }
                break;
            case 3:
                if (merkkijono[0] == ' ') {
                    printf("\nMerkkijono on tyhjä.\n");
                }
                else {
                    printf("\nMerkkijono: ");
                    for (i=0; i<pituus; i++) {
                        printf("%c", merkkijono[i]);
                    }
                    printf("\n");
                }
                break;
            case 0:
                jatka = FALSE;
                printf("\nOhjelman lopetus.\n");
                break;
            default:
                printf("\nTuntematon valinta.\n");
                break;
        }
    }
	return(0);
}