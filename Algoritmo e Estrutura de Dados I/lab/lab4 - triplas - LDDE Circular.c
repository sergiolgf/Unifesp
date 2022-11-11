#include <stdio.h>
#include <stdlib.h>
 
typedef struct elemento {
    int info;
    struct elemento *prox;
    struct elemento *ant;
}TElemento;
 
typedef struct estruturaLDDE{
    TElemento *primeiro;
    TElemento *ultimo;
    int tamanho;
}TLDDE;
 
void inicializaLista (TLDDE *listaAux){
    listaAux->primeiro = NULL;
    listaAux->ultimo = NULL;
    listaAux->tamanho=0;
}
 
void insereSequencia(TLDDE *listaAux, int a){
    TElemento *novo;
    novo=(TElemento*)malloc(sizeof(TElemento));
    novo->info=a;
 
    if(listaAux->primeiro==NULL){
        listaAux->primeiro=novo;
        listaAux->ultimo=novo;
        novo->prox=novo;
        novo->ant=novo;
    }else{
        novo->ant=listaAux->ultimo;
        novo->prox=listaAux->primeiro;
        listaAux->primeiro->ant=novo;
        listaAux->ultimo->prox=novo;
        listaAux->ultimo=novo;
    }
    listaAux->tamanho++;
}
 
void imprimeLista(TLDDE *listaAux){
    TElemento *p;
    int i;
 
    p=listaAux->primeiro;
    for(i=0;i<listaAux->tamanho;i++){
        printf("%d ",p->info);
        p=p->prox;
    }
    printf("\n");
 
}
 
void inserePos(TLDDE *listaAux, int num, int pos){
    TElemento *p, *novo;
    int i=0;
 
    //printf("a");
    //imprimeLista(listaAux);
 
    novo=(TElemento*)malloc(sizeof(TElemento));
    novo->info=num;
 
    //printf("a");
    //imprimeLista(listaAux);
 
 
    p=listaAux->primeiro;
    if(pos==0){
 
        listaAux->ultimo->prox=novo;
        listaAux->primeiro->ant=novo;
        novo->ant=listaAux->ultimo;
        novo->prox=listaAux->primeiro;
        listaAux->primeiro=novo;
 
 
    }else{
        for(i=0;i<pos;i++){
            p=p->prox;
        }
        //printf("%d\n",p->info);
        //insere antes de p
        p->ant->prox=novo;
        novo->prox=p;
        novo->ant=p->ant;
        p->ant=novo;
    }
    listaAux->tamanho++;
 
}
 
TElemento* achaTripla(TLDDE *listaAux){
   TElemento *q;
   int i;
 
   q=listaAux->primeiro;
   for(i=0;i<listaAux->tamanho;i++){
    if(q->info+q->ant->info+q->prox->info==10){
        return q;
    }
    q=q->prox;
   }
   return NULL;
 
}
 
void removeTripla(TLDDE *listaAux,TElemento *q){
    listaAux->tamanho-=3;
    if(q==listaAux->primeiro->prox){
        listaAux->primeiro=q->prox->prox;
    }else if(q==listaAux->primeiro){
        listaAux->primeiro=q->prox->prox;
    }else if(q==listaAux->ultimo){
        listaAux->primeiro=q->prox->prox;
    }
    if(q==listaAux->primeiro){
        listaAux->ultimo=listaAux->ultimo->ant;
    }else if(q==listaAux->ultimo){
        listaAux->ultimo=listaAux->ultimo->ant->ant;
    }else if(q==listaAux->ultimo->ant){
        listaAux->ultimo=listaAux->ultimo->ant->ant->ant;
    }
    //printf("%d\n",q->info);
 
    q->ant->ant->prox=q->prox->prox;
    q->prox->prox->ant=q->ant->ant;
    free(q->prox);
    free(q->ant);
    free(q);
 
 
}
 
int main(){
    TLDDE lista;
    TElemento *q;
    int i,num,pos;
 
 
    inicializaLista(&lista);
    for(i=0;i<10;i++){
        scanf("%d ",&num);
        insereSequencia(&lista,num);
    }
    imprimeLista(&lista);
    for(i=0;i<5;i++){
        //printf("b");
        //imprimeLista(&lista);
        if(lista.tamanho!=0){
            scanf("%d %d",&num,&pos);
            inserePos(&lista,num,pos);
            //imprimeLista(&lista);
            if(lista.tamanho>2){
                q=achaTripla(&lista);
                while(q!=NULL){
                    removeTripla(&lista,q);
                    
                    q=achaTripla(&lista);
                }
    
            }
            if(lista.tamanho!=0){
                imprimeLista(&lista);
            }
            //printf("a");
            //imprimeLista(&lista);
        }
 
    
        
        //printf("a");
        //imprimeLista(&lista);
    }
    if(lista.tamanho==0){
        printf("ganhou\n");
    }else{
        printf("perdeu\n");
    }
 
 
 
 
}