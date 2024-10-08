#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define elements 1000

void preenche_vetor(int *vet, FILE *arq){
    for(int i=0;i<elements;i++){
        if(i==0){
           fscanf(arq,"%d",&vet[0]); 
        }else{
            fscanf(arq," %d",&vet[i]);
        }
    }
}

int primoREC(int num, int div){
    if(num<=1){
        return 0;
    }else if(num==div){
        return 1;
    }else if(num%div==0){
        return 0;
    }else return primoREC(num,div+1);
}

int primoITE(int num){
    int i=2;
    for(i=2;i<num;i++){
        if(num%i==0)
            return 0;
    }
    return 1;
}

void main(int argc, char *argv[]){
    int maior = 0;
    int *vet;

    time_t ini,fim;

    FILE *arq;
	arq = fopen("vet.txt","r");
	if(arq==NULL){
		printf("\nErro arquivo\n");
		exit(2);
	}

    
    vet = (int*)malloc(elements*sizeof(int));

    preenche_vetor(vet,arq);

    ini = time(&ini);

    for(int i = 0;i<elements;i++){
        switch ((int)argv[1])
        {
        case 0:
            if(primoREC(vet[i],2) && vet[i]>maior)
                maior = vet[i];
            break;
        
        default:
            if(primoITE(vet[i]) && vet[i]>maior)
                maior = vet[i];
            break;
        }
        
        
    }

    fim = time(&fim);

    //printf("%d",ini-fim);

    free(vet);
}