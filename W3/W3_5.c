#include <stdio.h>

void randIntGen(char *fileName, int startValue){
    int i, num;
    srand(startValue);
    FILE *tiedosto;
    if ((tiedosto = fopen(fileName, "wb")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    for (i=0; i<20; i++){
        num = rand()%1000;
        fwrite(&num, sizeof(num), 1, tiedosto);
    }
    fclose(tiedosto);
    return;
}
void readFile(char *fileName){
    char rivi[100];
    int luku, i;
    FILE *tiedosto;
    if ((tiedosto = fopen(fileName, "rb")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    printf("Tiedostossa on seuraavat luvut:\n");
    for (i=0; i < 20; i++) {
        fread(&luku, sizeof(luku), 1, tiedosto);
        printf("%d ", luku);
    }
    fclose(tiedosto);
    return;
}
int main(void){
    char fileName[50];
    int startValue;

    printf("Anna käsiteltävän tiedoston nimi: ");
    scanf("%s", fileName);
    printf("Anna satunnaisluvuille lähtöarvo: ");
    scanf("%d", &startValue);
    randIntGen(fileName, startValue);
    printf("Tiedoston kirjoitus onnistui.\n");
    readFile(fileName);
    printf("\nTiedoston lukeminen onnistui.\n");
    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}