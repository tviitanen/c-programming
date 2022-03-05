#include <stdio.h>
#define maxStringLenght 30 

int stringLenght(char *merkkijono){
    char *ptr;
    int pituus = 0;
    ptr = merkkijono;
    while (*ptr != '\0'){
        pituus++;
        ptr++;
    }
    return pituus;
}
void stringCopy(char merkkijono1[], char merkkijono2[], int pituus){
    int i=0;
    for (i=0; i<=pituus; i++) {
        merkkijono2[i] = merkkijono1[i];
    }
    return;
}
int main(void) {
    char merkkijono1[maxStringLenght];
    char merkkijono2[maxStringLenght];
    int pituus;
    printf("Anna kopioitava merkkijono: ");
    fgets(merkkijono1, 30, stdin);
    pituus = stringLenght(merkkijono1);
    merkkijono1[pituus-1] = '\0';
    stringCopy(merkkijono1, &merkkijono2, pituus);
    printf("Merkkijono 1 on '%s'.\n", merkkijono1);
    printf("Merkkijono 2 on '%s'.\n", merkkijono1);
    printf("Kiitos ohjelman käytöstä.\n");
return(0);
}
