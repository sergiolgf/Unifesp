#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxTam 256

typedef struct{
	char buffer[maxTam];
	int charAtual;
}TBuffer;

enum estados{
	start,
    end


};

int main(int argc, char **argv){
	
	if(argc!=2){
		printf("Erro parametros");
		exit(1);
	}
	
	FILE *arq=fopen(argv[1],"r");
	
	if(arq==NULL){
		printf("Erro arquivo");
		exit(2);
	}

	TBuffer *buff = (TBuffer*)malloc(sizeof(TBuffer));
	
	int estado=0;

	char storeID[20];
	int IDatual=0;
	int charAtual;

	while(fgets(buff->buffer,maxTam,arq)){
		for(buff->charAtual=0;buff->charAtual<strlen(buff->buffer);buff->charAtual++){
			charAtual=buff->buffer[buff->charAtual];
			switch(estado){
				case start:
					switch(charAtual){

						default:
							printf("%c",charAtual);
					}
					break;
				case 1:
					break;
				case 2:
					break;
				default:
					break;
			}
			
		}
	}

	fclose(arq);
	free(buff);
}
