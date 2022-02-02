#include <stdio.h>
#include <string.h>
#define maxChars 50

int main(void){

    struct Kirja {
    char nimi[maxChars];
    int vuosi;
    int hylly;
    } kirja;
    printf("Anna kirjan nimi: ");
    gets(kirja.nimi);
    printf("Anna kirjan painovuosi: ");
    scanf("%d", &kirja.vuosi);
    printf("Anna kirjan hyllypaikka: ");
    scanf("%d", &kirja.hylly);
    printf("Kirjan nimi on '%s', painovuosi %d ja hyllypaikka %d.\n", kirja.nimi, kirja.vuosi, kirja.hylly);
    printf("Kiitos ohjelman käytöstä.\n");
}