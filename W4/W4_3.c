#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){
    if (argc < 2) {
        printf("Et antanut syötteitä.\n");
		printf("Kiitos ohjelman käytöstä.\n");
        exit(0);
    }
    else if (strcmp(argv[2],"+") == 0) {
        printf("%s + %s = ", argv[1], argv[3]);
        printf("%.2f\n", atof(argv[1])+atof(argv[3]));
    }
    else if (strcmp(argv[2],"-") == 0) {
        printf("%s - %s = ", argv[1], argv[3]);
        printf("%.2f\n", atof(argv[1])-atof(argv[3]));
    }
    else if (strcmp(argv[2],"x") == 0) {
        printf("%s x %s = ", argv[1], argv[3]);
        printf("%.2f\n", atof(argv[1])*atof(argv[3]));
    }
    else if (strcmp(argv[2],"/") == 0) {
        printf("%s / %s = ", argv[1], argv[3]);
        printf("%.2f\n", atof(argv[1])/atof(argv[3]));
    }
    else{
        printf("Virheellinen syöte.\n");
    }
	printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}