#define elementos 10
#include <stdio.h>

void imprime_vetor(int vetor[]){
    int a;
    for(a=0;a<elementos;a++){
        printf("%d ",vetor[a]);
    }
}

int main(){
    FILE *arquivole;

    int menor,aux;
    int vet[elementos];
    int i,k,l;
    arquivole=fopen("vetornum.txt","r");
    
    for(i=0;i<elementos;i++){
        if(i==0){
           fscanf(arquivole,"%d",&vet[0]); 
        }else{
            fscanf(arquivole," %d",&vet[i]);
        }
    }
    imprime_vetor(vet);
    printf("\n\n");
    
    //selection sort
    for(k=0;k<elementos-1;k++){
        menor = k;
        for(l=k+1;l<elementos;l++){
            if(vet[l]<vet[menor]){
                menor = l;
            }
        }
        if(menor!=k){
            aux = vet[menor];
            vet[menor] = vet[k];
            vet[k] = aux;
        }

    }
    //-------------------------------

    imprime_vetor(vet);

    fclose(arquivole);

    return 0;
}