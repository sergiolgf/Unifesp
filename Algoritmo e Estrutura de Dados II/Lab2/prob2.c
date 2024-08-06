#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int Tam;
    int inicio;
    int *vet;
}TColuna;

typedef struct{
    int NColunas;
    TColuna *colunas;
}Ttabela;

void alocaTabela(Ttabela *dados, int K, int I){
    dados->NColunas = K;
    dados->colunas = (TColuna*)malloc(K*sizeof(TColuna));
}

void preencheTabela(Ttabela *dados){
    int i,j,TamAux;
    
    for(i=0;i<dados->NColunas;i++){
        scanf("%d",&TamAux);
        dados->colunas[i].vet=(int*)malloc(TamAux*sizeof(int));
        dados->colunas[i].inicio=0;
        dados->colunas[i].Tam=TamAux;
        for(j=0;j<TamAux;j++){
            scanf(" %d",&dados->colunas[i].vet[j]);
        }
    }
    
}

void printDados(Ttabela dados){
    int i,j;
    for(i=0;i<dados.NColunas;i++){
        for(j=dados.colunas[i].inicio;j<dados.colunas[i].Tam;j++){
            printf("%d ",dados.colunas[i].vet[j]);
        }
        printf("\n");
    }
}

int buscaMenor(Ttabela dados){
    int i,j;
    int menorNum=9999999;
    int menorIndice;

    for(i=0;i<dados.NColunas;i++){
        if(dados.colunas[i].inicio<dados.colunas[i].Tam&&dados.colunas[i].vet[dados.colunas[i].inicio]<menorNum){
            menorIndice=i;
            menorNum = dados.colunas[i].vet[dados.colunas[i].inicio];
        }
    }


    return menorIndice;
}

void removeMenor(Ttabela *dados){
    int menorIndice = buscaMenor(*dados);
    //printf("\nremovendo %d do vetor %d\n\n",dados->colunas[menorIndice].vet[dados->colunas[menorIndice].inicio],menorIndice);
    dados->colunas[menorIndice].inicio++;
}

int* recebeMenores(Ttabela *dados, int *TamMenores){
    int *menores;
    int contMenores;
    int menorNum;
    int menorIndice;
    menorIndice = buscaMenor(*dados);
    menorNum=dados->colunas[menorIndice].vet[dados->colunas[menorIndice].inicio];
    dados->colunas[menorIndice].vet[dados->colunas[menorIndice].inicio]=9999999;
    while(menorNum!=9999999){
        contMenores++;
        menores=(int*)realloc(menores,contMenores*sizeof(int));
        menores[contMenores-1]=menorNum;
        menorIndice = buscaMenor(*dados);
        menorNum=dados->colunas[menorIndice].vet[dados->colunas[menorIndice].inicio];
        dados->colunas[menorIndice].vet[dados->colunas[menorIndice].inicio]=9999999;

    }
    *TamMenores=contMenores;

    return menores;
    
}

void insertion_sort(int size, int *vet){
    int i,j,aux;
    for(i=1;i<size;i++){
        aux = vet[i];
        j=i-1;
        while (j >= 0 && vet[j] > aux)
        {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = aux;
    }
}

void imprime_vetor(int *vet, int size){
    int i;
    //printf("\n\n");
    for(i=0;i<size;i++){
        if(i==0){
            printf("%d", vet[i]);
        }else{
            printf(" %d", vet[i]);
        }
    }
    //printf("\n\n");
}

int main(){
    int K,I;
    int i,j,num;
    Ttabela dados;
    int *menores;
    int TamMenores;

    scanf("%d %d",&K,&I);

    alocaTabela(&dados,K,I);
    
    preencheTabela(&dados);
    
    //printDados(dados);
    
    for(i=0;i<I-1;i++)
        removeMenor(&dados);

    printDados(dados);
    
    menores=recebeMenores(&dados,&TamMenores);

    //imprime_vetor(menores,TamMenores);

    insertion_sort(TamMenores,menores);

    //imprime_vetor(menores,TamMenores);
    
    return 0;
}