#include <stdio.h>

int fibonacci(int luku){
    if(luku == 0){
      return 0;
   } else if(luku == 1) {
      return 1;
   } else {
      return (fibonacci(luku-1) + fibonacci(luku-2));
   }
}

int main(void) {
    int luku;

    printf("Anna luku, jolle lasketaan Fibonaccin luku: ");
    scanf("%d", &luku);
    printf("Luvun %d Fibonaccin luku on %d.\n", luku, fibonacci(luku));
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}