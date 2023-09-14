#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorting.c"

#define elements 10

void preenche_vetor(int size, int *vet, FILE *arq){
    for(int i=0;i<size;i++){
        if(i==0){
           fscanf(arq,"%d",&vet[0]); 
        }else{
            fscanf(arq," %d",&vet[i]);
        }
    }
}

void imprime_vetor(int size, int *vet){
    int i;
    printf("\n\n");
    for(i=0;i<size;i++){
        if(i==0){
            printf("%d", vet[i]);
        }else{
            printf(" %d", vet[i]);
        }
    }
    printf("\n\n");
}

int main(int argc,char* argv[]){
	if(argc!=3){
		printf("\nErro parametros %d\n",argc);
		exit(1);
	}
	FILE *arq;
	arq = fopen(argv[1],"r");
	if(arq==NULL){
		printf("\nErro arquivo\n");
		exit(2);
	}

    int *vet;
    vet = (int*)malloc(elements*sizeof(int));

    preenche_vetor(elements,vet,arq);

    imprime_vetor(elements,vet);
    
    
    //sort
    switch(atoi(argv[2])){
        case 1:
            printf("Bubble sort");
            bubble_sort(elements,vet);
            break;
        
        case 2:
            printf("Selection sort");
            selection_sort(elements,vet);
            break;
        
        case 3:
            printf("Insertion sort");
            insertion_sort(elements,vet);
            break;

        case 4:
            printf("Shell sort");
            shell_sort(elements, vet);
            break;

        case 5:
            printf("Merge sort");
            mergeSort(vet, 0, elements);
            break;
        
        default:
            printf("Erro opcao sort");
    }
    

    imprime_vetor(elements,vet);

    free(vet);
}