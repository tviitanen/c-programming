#include <stdio.h>
#define RIVI 2
#define SARAKE 2

int main(void){
    int i, j, R1A1, R1A2, R2A1, R2A2;
    printf("Anna arvot yhteenlaskettaville matriiseille:\n");
    printf("Matriisin 1 alkiot:\n");
    printf("Rivi 1 alkio 1: ");
    scanf("%d", &R1A1);
    printf("Rivi 1 alkio 2: ");
    scanf("%d", &R1A2);
    printf("Rivi 2 alkio 1: ");
    scanf("%d", &R2A1);
    printf("Rivi 2 alkio 2: ");
    scanf("%d", &R2A2);
    int matriisi1[RIVI][SARAKE] = {{R1A1,R1A2}, {R2A1,R2A2}};
    printf("\nMatriisi 1:");
    for (i=0; i < RIVI; i++) {
        printf("\n");
        for (j=0; j < SARAKE; j++) {
            printf("%4d ", matriisi1[i][j]);
        }
    }
    printf("\n\nMatriisin 2 alkiot:\n");
    printf("Rivi 1 alkio 1: ");
    scanf("%d", &R1A1);
    printf("Rivi 1 alkio 2: ");
    scanf("%d", &R1A2);
    printf("Rivi 2 alkio 1: ");
    scanf("%d", &R2A1);
    printf("Rivi 2 alkio 2: ");
    scanf("%d", &R2A2);
    int matriisi2[RIVI][SARAKE] = {{R1A1,R1A2}, {R2A1,R2A2}};
    printf("\nMatriisi 2:");
    for (i=0; i < RIVI; i++) {
        printf("\n");
        for (j=0; j < SARAKE; j++) {
            printf("%4d ", matriisi2[i][j]);
        }
    }
    // summa matriisi:
    printf("\n\nSummamatriisi:");
    int summamatriisi[RIVI][SARAKE];
    for (i = 0; i < RIVI; ++i){
        for (j = 0; j < SARAKE; ++j) {
            summamatriisi[i][j] = matriisi1[i][j] + matriisi2[i][j];
        }
    }
    for (i=0; i < RIVI; i++) {
        printf("\n");
        for (j=0; j < SARAKE; j++) {
            printf("%4d ", summamatriisi[i][j]);
        }
    }
    printf("\n\nKiitos ohjelman käytöstä.\n");
    return 0;
}