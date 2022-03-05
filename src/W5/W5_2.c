#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void tarkistaSyote(int syote)
{
    if (syote < 1)
    {
        printf("Parametri ei ollut positiivinen kokonaisluku.\n");
        exit(0);
    }
    return;
}
int *varaaMuisti(int syote)
{
    int *muisti;
    int muistin_maara = (syote + 1) * sizeof(int);
    if ((muisti = (int *)malloc(muistin_maara)) == NULL)
    {
        perror("Muistinvaraus epäonnistui");
        exit(0);
    }
    printf("Muistin varaus onnistui.\n");
    printf("Taulukossa on tilaa %d alkiolle.\n", syote);
    return muisti;
}
void taytaTaulukko(int *ptr, int lkm)
{
    for (int i = 0; i < lkm; i++)
    {
        printf("Anna %d. luku: ", i + 1);
        scanf("%d", &ptr[i]);
        getchar();
    }
    printf("Taulukko täytetty.\n");
    printf("Taulukossa on luvut: ");
    for (int i = 0; i < lkm; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\nTaulukko tulostettu.\n");
    return;
}
void vapautaMuisti(int *muisti)
{
    free(muisti);
    printf("Muisti vapautettu.\n");
    return;
}
int main(int argc, char *argv[])
{
    int *ptr;
    tarkistaSyote(atoi(argv[1]));
    ptr = varaaMuisti(atoi(argv[1]));
    taytaTaulukko(ptr, atoi(argv[1]));
    vapautaMuisti(ptr);
    printf("Kiitos ohjelman käytöstä.\n");
    return (0);
}