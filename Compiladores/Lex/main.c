#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"
#include "funcs.c"


int main(int argc,char* argv[]){
	if(argc!=2){
		printf("\nErro parametros\n");
		exit(1);
	}
	FILE *arq;
	arq = fopen(argv[1],"r");
	if(arq==NULL){
		printf("\nErro arquivo\n");
		exit(2);
	}
	
	
	buffer *b;
	b = allocate_buffer(arq);
	
	char *c;
	c = allocate_char();
	
	c = fgets(b->buff,256,arq);
	while(c!=NULL){
		b->atual = 0;
		for(int i=0;i<strlen(b->buff);i++){
			printf("%c",get_next_char(b));
		}
		c = fgets(b->buff,256,arq);
	}
	
	fclose(arq);
	deallocate(b);
	deallocate(c);
	
	return 0;	
}
	
	
