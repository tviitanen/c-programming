#include <stdio.h>
#include <string.h>
int main(void) {
    char etunimi[15];
    char sukunimi[20];
    int ika;
    float paino;
    printf("Anna etunimesi: ");
    scanf("%s", etunimi);
    getchar();
    printf("Anna sukunimesi: ");
    scanf("%s", sukunimi);
    getchar();
    printf("Anna ikäsi: ");
    scanf("%d", &ika);
    printf("Anna painosi: ");
    scanf("%f", &paino);
    printf("Nimesi on %s %s, ikäsi on %d ja painat %5.1f", etunimi, sukunimi, ika, paino);
    return(0);
}