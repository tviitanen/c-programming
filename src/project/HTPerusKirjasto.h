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
/* Tavoitetaso, HTPerusKirjasto.h */

#ifndef HTPerusKirjasto
#define HTPerusKirjasto

#define MAXLEN 50

// Tietue luettaville riveille
typedef struct lista{
    char pvm[MAXLEN];
    int viikko;
    int aurinko;
    int kulutus;
    int tuuli;
    int vesi;
    int ydin;
    int yht;
    int errLampo;
    struct lista *pSeuraava;
} LISTA;

// Tulostietue
typedef struct tulokset{
    int lkm;
    long int kulutus;
    double keskiarvo;
    int maxKulutus;
    char maxAika[MAXLEN];
    int minKulutus;
    char minAika[MAXLEN];
} TULOKSET;

// Kuukausittaiset tuotannot
typedef struct kkTuotanto{
    int kuukausi;
    long int tuotanto;
} KKTUOTANTO;

// Viikottaiset tuotannot
typedef struct vkTuotanto{
    int viikko;
    int aurinko;
    int tuuli;
    int vesi;
    int ydin;
    int yht;
    int lampo;
} VKTUOTANTO;


// HTPerusKirjasto.c:
LISTA *lueTiedosto(LISTA *pAlku, char *tiedostoNimi);
TULOKSET analysoiTiedot(LISTA *pAlku);
KKTUOTANTO *kuukausiAnalyysi(LISTA *pAlku);
void tallennaTiedot(TULOKSET tulos, KKTUOTANTO aTaulukko[], char *tiedostoNimi);
LISTA *vapautaMuisti(LISTA *pAlku);

// HTTavoiteKirjasto.c:
VKTUOTANTO *viikkoAnalyysi(LISTA *pAlku);
void tallennaViikko(VKTUOTANTO *pMatriisi, char *tiedostoNimi);

#endif

    /* eof */
