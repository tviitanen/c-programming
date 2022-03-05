#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int laske(int luku) {
    int tulos = luku*luku;

return tulos;
}

int main(int argc, char *argv[] ) {
    if (argc < 2 ) {
        printf("Et antanut lukua!\n");
        printf("Kiitos ohjelman käytöstä.\n");
        exit(0);
    }
    printf("Luku on %s.\n", argv[1]);
    printf("Luvun neliö on %d.\n", laske(atoi(argv[1])));
    printf("Kiitos ohjelman käytöstä.\n");
return(0);
}