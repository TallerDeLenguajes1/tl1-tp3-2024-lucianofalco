#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *Nombre ; 
    char buff[100];

    printf("\n Ingrese Nombre\n");
    scanf("%s" , buff);
    Nombre = (char *) malloc((strlen(buff)+1)*sizeof(char));
    strcpy(Nombre , buff);
    printf("EL nombre es: %s" , Nombre);
    free(Nombre);
    return 0;
}
