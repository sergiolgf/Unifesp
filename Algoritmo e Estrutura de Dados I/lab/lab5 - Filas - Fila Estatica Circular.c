#include <stdio.h>
 
#include <stdlib.h>
 
 
 
#define tamanhoMAX 100
 
 
 
typedef struct filaCircular {
 
    int primeiro;
 
    int ultimo;
 
    int tamanhofila;
 
    int elementos[tamanhoMAX];
 
}tipoFC;
 
 
 
void inicializaFila (tipoFC *filaAux){
 
    // inicializa a fila
 
    int i;
 
    filaAux->primeiro = -1;
 
    filaAux->ultimo = -1;
 
    for (i=0; i<tamanhoMAX; i++){
 
        filaAux->elementos[i]=0;
 
    }
 
}
 
 
 
int filaVazia(tipoFC *filaAux){
 
    if (filaAux->tamanhofila==0){
 
        return 1; // fila está vazia
 
    }else{
 
        return 0; // fila não está vazia
 
    }
 
}
 
 
 
int filaCheia (tipoFC *filaAux){
 
    if (((filaAux->ultimo + 1) % tamanhoMAX) == filaAux->primeiro){
 
        return 1; // fila está cheia
 
    }else{
 
        return 0; // fila não está cheia
 
    }
 
}
 
 
 
void insereElemento (tipoFC *filaAux, int info){
 
    int i,j;
 
    // se a fila estiver vazia insere o primeiro elemento
 
    if(filaVazia(filaAux)==1){
 
        filaAux->primeiro = 0;
 
        filaAux->ultimo = 0;
 
        filaAux->elementos[ 0 ]=info;
 
        filaAux->tamanhofila++;
 
    }else if(filaCheia(filaAux)==0){
 
        // se a fila não estiver cheia podemos inserir
 
        i = filaAux->ultimo+1;
 
        while(i!=filaAux->primeiro){
 
            filaAux->elementos[i]=filaAux->elementos[i-1];
 
            i--;
 
        }
 
        filaAux->elementos[filaAux->primeiro]=info;
 
        filaAux->ultimo++;
 
        filaAux->tamanhofila++;
 
    }else{
 
        printf("overflow: fila cheia");
 
        
 
    }
 
}
 
 
 
void removeElemento(tipoFC *filaAux){
 
    if(filaVazia(filaAux)==1){
 
        printf("vazia\n");
 
    }else{
 
        
 
        filaAux->tamanhofila--;
 
        filaAux->elementos[filaAux->ultimo]=0;
 
        filaAux->ultimo--;
 
        if(filaVazia(filaAux)==1){
 
            inicializaFila(filaAux);
 
        }
 
    }
 
}
 
 
 
void conclusao(tipoFC *filaAux){
 
    int i;
 
    if(filaVazia(filaAux)==1){
 
        printf("vazia\n");
 
    }else{
 
        i = filaAux->elementos[filaAux->ultimo];
 
        insereElemento(filaAux,i);
 
        filaAux->tamanhofila--;
 
        filaAux->elementos[filaAux->ultimo]=0;
 
        filaAux->ultimo--;
 
    }
 
}
 
 
 
void imprimeFila (tipoFC *filaAUX){
 
    int i,a;
 
    a = filaAUX->primeiro;
 
    printf("%d",filaAUX->elementos[a]);
 
    for(i=filaAUX->primeiro;i!=filaAUX->ultimo;i++){
 
        a++;
 
        printf(" %d",filaAUX->elementos[a]);
 
    }
 
}
 
 
 
int main(){
 
    tipoFC fila;
 
    int op,num, L,i;
 
 
 
    inicializaFila(&fila);
 
 
 
    scanf("%d",&L);
 
    for(i=0;i<L;i++){
 
        scanf("%d",&op);
 
        switch(op){
 
            case 1:
 
                scanf(" %d",&num);
 
                insereElemento(&fila,num);
 
                
 
                break;
 
            case 2:
 
                removeElemento(&fila);
 
                break;
 
            case 3:
 
                conclusao(&fila);
 
                break;
 
        }
 
    }
 
    if(filaVazia(&fila)==0){
 
        imprimeFila(&fila);
 
    }
 
}