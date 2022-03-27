/*************************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Tekijä: Teemu Viitanen
 * Opiskelijanumero: 00456573
 * Päivämäärä: 26.3.2022
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
/* Tavoitetaso, HTTavoitetaso.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HTPerusKirjasto.h"

int valikko()
{
    int valinta = 0;
    printf("Valitse haluamasi toiminto:\n"
           "1) Lue tiedosto\n"
           "2) Analysoi tiedot\n"
           "3) Kirjoita tulokset\n"
           "4) Laske viikoittaiset tulokset\n"
           "0) Lopeta\n");

    printf("Anna valintasi: ");
    scanf("%d", &valinta);

    return valinta;
}

char *kysyTiedosto(char *tiedostoNimi, char *kehote)
{
    printf("%s", kehote);
    scanf("%s", tiedostoNimi);

    return tiedostoNimi;
}

int main(void)
{
    int valinta = 1;
    char tiedostoNimi[MAXLEN], kehote[MAXLEN];

    LISTA *pAlku = NULL;
    TULOKSET tulos;
    KKTUOTANTO *pTaulukko = NULL;
    VKTUOTANTO *pMatriisi = NULL;

    do
    {
        valinta = valikko();

        if (valinta == 1)
        {
            if (pAlku != NULL)
            {
                pAlku = vapautaMuisti(pAlku);
            }
            strcpy(kehote, "Anna luettavan tiedoston nimi: ");
            strcpy(tiedostoNimi, kysyTiedosto(tiedostoNimi, kehote));
            pAlku = lueTiedosto(pAlku, tiedostoNimi);
        }
        else if (valinta == 2)
        {
            if (pAlku != NULL)
            {
                free(pTaulukko);
                tulos = analysoiTiedot(pAlku);
                pTaulukko = kuukausiAnalyysi(pAlku);
            }
            else
            {
                printf("Ei analysoitavaa, lue tiedosto ennen analyysiä.\n");
            }
        }
        else if (valinta == 3)
        {
            if (pTaulukko != NULL)
            {
                strcpy(kehote, "Anna kirjoitettavan tiedoston nimi: ");
                strcpy(tiedostoNimi, kysyTiedosto(tiedostoNimi, kehote));
                tallennaTiedot(tulos, pTaulukko, tiedostoNimi);
            }
            else
            {
                printf("Ei kirjoitettavia tietoja, analysoi tiedot ennen tallennusta.\n");
            }
        }
        else if (valinta == 4)
        {
            if (pAlku != NULL)
            {
                free(pMatriisi);
                strcpy(kehote, "Anna kirjoitettavan tiedoston nimi: ");
                strcpy(tiedostoNimi, kysyTiedosto(tiedostoNimi, kehote));
                pMatriisi = viikkoAnalyysi(pAlku);
                tallennaViikko(pMatriisi, tiedostoNimi);
            }
            else
            {
                printf("Ei analysoitavaa, lue tiedosto ennen analyysiä.\n");
            }
        }
        else if (valinta == 0)
        {
            free(pMatriisi);
            free(pTaulukko);
            pAlku = vapautaMuisti(pAlku); // linkitetyn listan tyhjennys
            printf("\nKiitos ohjelman käytöstä.");
        }
        else
        {
            printf("Tuntematon valinta, yritä uudestaan.\n");
        }
        printf("\n");
    } while (valinta != 0);

    return (0);
}

/* eof */
