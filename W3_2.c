#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int valikko() {
    int valinta;
    printf("Valitse alla olevista valinnoista\n");
    printf("1) Lisää uusi nimi\n");
    printf("2) Tulosta nimet\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf("%d", &valinta);
    getchar();
    return valinta;
}

void lisaaNimi(char *tiedosto_nimi) {
    char nimi[50];
    printf("Anna lisättävä nimi: ");
    scanf("%s", nimi);
    FILE *tiedosto;
    if ((tiedosto = fopen(tiedosto_nimi, "a")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    fprintf(tiedosto, "%s\n", nimi );
    fclose(tiedosto);
    printf("Nimi lisätty tiedostoon.\n\n");
    return(0);
}

void lueNimet(char *tiedosto_nimi) {
    char rivi[52];
    FILE *tiedosto;
    if ((tiedosto = fopen(tiedosto_nimi, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    printf("Tiedostossa olevat nimet:\n");
    while (fgets(rivi, 52, tiedosto) != NULL) {
        printf("%s", rivi);
    }
    fclose(tiedosto);
    printf("Tiedosto luettu ja tulostettu.\n\n");
    return(0);
}
int main(void) {
    char tiedosto_nimi[50];
    int jatka = 1, valinta;

    printf("Tämä ohjelma lisää nimiä tiedostoon ja lukee ne.\n");
    printf("Anna käsiteltävän tiedoston nimi: ");
    scanf("%s", tiedosto_nimi);

    do {
        valinta = valikko();
        if (valinta == 1) {
            lisaaNimi(tiedosto_nimi);
        }
        else if (valinta == 2) {
            lueNimet(tiedosto_nimi);
        }
        else if (valinta == 0) {
            printf("Kiitos ohjelman käytöstä.\n");
        }
        else {
            printf("\nTuntematon valinta.\n");    
        }
    } while (valinta != 0);
    return(0);
}
