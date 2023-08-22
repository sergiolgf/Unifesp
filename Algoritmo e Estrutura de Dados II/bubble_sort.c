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

    int aux;
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

    //bubble sort

    for(k=elementos-1;k>0;k--){
        for(l=0;l<k;l++){
            if(vet[l]>vet[l+1]){
                aux = vet[l+1];
                vet[l+1] = vet[l];
                vet[l] = aux;
            }
        }
    }
    //--------------------------------
    printf("\n\n");
    imprime_vetor(vet);

    fclose(arquivole);
    return 0;
}