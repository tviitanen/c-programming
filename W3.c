#include <stdio.h>

int potenssi(int luku1, int luku2);

int main(void) {
    int luku1, luku2, vastaus;
    printf("Ohjelma laskee luvun potenssin.\n");
    printf("Anna kokonaisluku, jonka haluat korottaa potenssiin: ");
    scanf("%d", &luku1);
    printf("Anna potenssi, jonka haluat laskea: ");
    scanf("%d", &luku2);
    vastaus = potenssi(luku1, luku2);
    printf("%d ^ %d = %d.", luku1, luku2, vastaus);
    printf("\nKiitos ohjelman käytöstä.\n");
    return(0);
}
int potenssi(int luku1, int luku2) {
    int i, tulos = luku1;
    for (i=1; i<luku2; i++) {
        tulos = tulos * luku1;
    }
    return tulos;
}