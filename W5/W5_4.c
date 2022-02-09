#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int valikko(){
    int valinta;
    printf("1) Tulosta taulukon alkiot\n");
    printf("2) Muuta taulukon kokoa\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf("%d", &valinta);
    getchar();
    return valinta;
}
int *varaaMuisti(int *muisti, int koko){
    if ((muisti = (int *)realloc(muisti, koko * sizeof(int))) == NULL){
        perror("Muistinvaraus epäonnistui");
        exit(0);
    }
    for (int i = 0; i < koko; i++){
        muisti[i] = i;
        }
    return muisti;
    }
void tulostaTaulukko(int *muisti, int koko){
    if ((muisti==NULL) | (koko == 0)){
        printf("Taulukko on tyhjä.\n");
    }
    else{
        printf("Taulukon alkiot ovat: ");
        for (int i=0; i<koko; i++){
            printf("%d ", muisti[i]);
        }
        printf("\n");
    }
    return;
}
int main(void){
    int *muisti = NULL;
    int valinta, tkoko=0, koko=0;
    do{
        valinta = valikko();
        if (valinta == 1){
            tulostaTaulukko(muisti, koko);
        }
        else if (valinta == 2){
            printf("Anna taulukon uusi koko: ");
            scanf("%d", &tkoko);
            getchar();
            if (tkoko < 0){
                printf("Taulukon koko ei voi olla negatiivinen.\n");
            }
            else{
                koko = tkoko;
                muisti = varaaMuisti(muisti, koko);
            }
            }
        else if (valinta == 0){
            free(muisti);
            printf("Muisti vapautettu.\n");
            printf("Kiitos ohjelman käytöstä.\n");
        }
        else{
            printf("\nTuntematon valinta, yritä uudestaan.\n");
        }
    }
    while (valinta != 0);
    return (0);
}