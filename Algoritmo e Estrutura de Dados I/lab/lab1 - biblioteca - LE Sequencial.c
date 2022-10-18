#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct{
    int tamanho;
    int lista[N];
}Tlista;

void inicialista(Tlista *lista){
    int i;
    lista->tamanho=0;
    for(i=0;i<N;i++){
        lista->lista[i]=0;
    }
}

void inserefim(Tlista *lista,int a,int *nres){
    if(lista->tamanho==N){
        printf("Lista de reserva cheia\n");
    }else{
        lista->tamanho++;
        lista->lista[lista->tamanho-1]=a;
        printf("Sua reserva foi realizada\n");
        *nres+=1;
    }
    
}

int removeel(Tlista *lista, int a, int *nret){
    int i,j;
    for(i=0;i<lista->tamanho;i++){
        if(lista->lista[i]==a){
            lista->lista[i]=0;
            lista->tamanho--;
            for(j=i;j<lista->tamanho;j++){
                lista->lista[j]=lista->lista[j+1];
            }
            printf("O livro foi retirado com sucesso\n");
            *nret+=1;
            return 0;
        }
    }
    printf("Voce nao possui reserva desse livro\n");
}

void imprimelista(Tlista *lista){
    int i;
    for(i=0;i<lista->tamanho;i++){
        printf("%d ",lista->lista[i]);
    }
}

int main(){
    Tlista lista;
    int L,i,op,num;
    int nres=0,nret=0;

    inicialista(&lista);

    scanf("%d",&L);
    for(i=0;i<L;i++){
        scanf("%d %d",&op, &num);
        switch(op){
            case 1:
                //reserva
                inserefim(&lista,num,&nres);
                break;
            case 2:
                //retira
                removeel(&lista,num,&nret);
                break;
        }
    }

    printf("Voce realizou %d reservas e %d retiradas\n", nres, nret);
    
    
    return 0;
}