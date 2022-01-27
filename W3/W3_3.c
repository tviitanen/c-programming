#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compareInteger(int luku1, int luku2){
    if (luku1 == luku2){
        printf("Luvut %d ja %d ovat yhtä suuria.\n", luku1, luku2);
    }    
    else if (luku1 < luku2) {
        printf("Luku %d on suurempi ja %d pienempi.\n", luku2, luku1);
    }
    else{
        printf("Luku %d on suurempi ja %d pienempi.\n", luku1, luku2);
    }
    return;
}
void compareFloat(float luku1, float luku2) {
    if (luku1 == luku2){
        printf("Luvut %.2f ja %.2f ovat yhtä suuria.\n", luku1, luku2);
    }
    else if (luku1 < luku2) {
        printf("Luku %.2f on suurempi ja  %.2f pienempi.\n", luku2, luku1);
    }
    else{
        printf("Luku %.2f on suurempi ja %.2f pienempi.\n", luku1, luku2);
    }
    return;
}
void compareName(char *nimi1, char *nimi2) {
    if (*nimi1 == *nimi2){
        printf("Merkkijonona '%s' ja '%s' ovat yhtä suuria.\n", nimi1, nimi2);
    }
    else if (strlen(nimi1) < strlen(nimi2)) {
        printf("Merkkijonona '%s' on suurempi ja '%s' pienempi.\n", nimi2, nimi1);
    }
    else{
        printf("Merkkijonona '%s' on suurempi ja '%s' pienempi.\n", nimi1, nimi2);
    }

    return;
}

int main(void) {
    // kokonaisluku
    int luku1, luku2; 
    float dluku1, dluku2;
    char nimi1[10], nimi2[10];
    printf("Anna kaksi kokonaislukua:\n");
    printf("Luku 1: ");
    scanf("%d", &luku1);
    printf("Luku 2: ");
    scanf("%d", &luku2);
    compareInteger(luku1, luku2);
    // desimaaliluku
    printf("Anna kaksi desimaalilukua:\n");
    printf("Luku 1: ");
    scanf("%f", &dluku1);
    printf("Luku 2: ");
    scanf("%f", &dluku2);
    compareFloat(dluku1, dluku2);
    // nimet
    printf("Anna kaksi nimeä:\n");
    printf("Nimi 1: ");
    scanf("%s", nimi1);
    printf("Nimi 2: ");
    scanf("%s", nimi2);
    compareName(nimi1, nimi2);
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}