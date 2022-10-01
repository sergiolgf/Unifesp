#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *arquivo;

    char texto[100];
    printf("Digite o texto a ser gravado: ");
    gets(texto);

    arquivo=fopen("arquivocriado.txt","w");//nome do arquivo, modo de escrita texto
    fputs(texto,arquivo);
    fclose(arquivo);

}