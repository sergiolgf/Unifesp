#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *arquivo;
    char texto[100];

    arquivo=fopen("arquivocriado.txt","r");
    fgets(texto,100,arquivo);
    printf("Texto lido: %s",texto);
    fclose(arquivo);
}