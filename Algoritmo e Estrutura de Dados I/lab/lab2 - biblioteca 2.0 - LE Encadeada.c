#include <stdio.h>
#define N 10
 
typedef struct{
    int ra;
    int prox;
}TAluno;
 
typedef struct{
    int tamanho;
    int primeiro;
    int ultimo;
    int poslivre[N];
    TAluno lista[N];
}TLEE;
 
void inicialista(TLEE *listaaux){
    int i;
    listaaux->ultimo=-1;
    listaaux->tamanho=0;
    listaaux->primeiro=-1;
    for(i=0;i<N;i++){
        listaaux->poslivre[i]=1;
        listaaux->lista[i].ra=0;
        listaaux->lista[i].prox=-1;
    }
}
 
int insere(TLEE *listaaux, int ra, int plivre){
    int i,j=0;
    if(listaaux->tamanho==0){
        listaaux->primeiro=plivre;
        listaaux->ultimo=plivre;
    }else if(plivre==-1){
        printf("lista cheia\n");
        return 1;
    }else if(listaaux->lista[listaaux->primeiro].ra>ra){
        //insercao no comeco
        listaaux->lista[plivre].prox=listaaux->primeiro;
        listaaux->primeiro=plivre;
    }else if(listaaux->lista[listaaux->ultimo].ra<ra){
        //insercao no fim
        listaaux->lista[listaaux->ultimo].prox=plivre;
        listaaux->ultimo=plivre;
    }else{
        //insercao no meio
        for(i=listaaux->primeiro;ra>listaaux->lista[i].ra;i=listaaux->lista[i].prox){
            j=i; //guarda posicao anterior
        }
        listaaux->lista[j].prox=plivre;
        listaaux->lista[plivre].prox=i;
    }
    listaaux->lista[plivre].ra=ra;
    listaaux->poslivre[plivre]=0;
    listaaux->tamanho+=1;
    return 0;
}
 
int retira(TLEE *listaaux,int ra){
    int i,j=0;
    for(i=listaaux->primeiro;i!=-1;i=listaaux->lista[i].prox){
        if(listaaux->lista[i].ra==ra){
            if(i==listaaux->primeiro){
                listaaux->poslivre[listaaux->primeiro]=1;
                listaaux->primeiro=listaaux->lista[i].prox;
            }else if(i==listaaux->ultimo){
                listaaux->poslivre[listaaux->ultimo]=1;
                listaaux->ultimo=j;
                listaaux->lista[j].prox=-1;
            }else{
                listaaux->poslivre[i]=1;
                listaaux->lista[j].prox=listaaux->lista[i].prox;
            }
            listaaux->tamanho-=1;
            if(listaaux->tamanho==0){
                inicialista(listaaux);
            }
            return 0;
        }
        j=i;
    }
    printf("nao existe\n");
    return 1;
}
 
int proxlivre(TLEE *listaaux){
    int i;
    for(i=0;i<N;i++){
        if(listaaux->poslivre[i]==1){
            return i;
        }
    }
    return -1;
}
 
void imprimelista(TLEE listaaux){
    int i=listaaux.primeiro;
    if(listaaux.tamanho!=0){
        printf("%d",listaaux.lista[i].ra);
        i=listaaux.lista[i].prox;
        while(i!=-1){
            printf(" %d",listaaux.lista[i].ra);
            i=listaaux.lista[i].prox;
        }
    }
    printf("\n");
    
}
 
int descobreano(int ra){
    int id;
    id=ra/1000;
    switch(id){
        case 66:
            return 2011;
            break;
        case 76:
            return 2012;
            break;
        case 86:
            return 2013;
            break;
        case 96:
            return 2014;
            break;
        case 106:
            return 2015;
            break;
        case 116:
            return 2016;
            break;
        case 126:
            return 2017;
            break;
        case 136:
            return 2018;
            break;
    }
}
 
 
int main(){
    int L=0,i=0,op=0,auxra=0;
    int c2011=0,c2012=0,c2013=0,c2014=0,c2015=0,c2016=0,c2017=0,c2018=0;
    TLEE lista;
 
    inicialista(&lista);
 
    scanf("%d",&L);
    for(i=0;i<L;i++){
        scanf("%d %d",&op,&auxra);
        switch(op){
            case 1:
                //reserva
                if(!insere(&lista,auxra,proxlivre(&lista))){
                    switch(descobreano(auxra)){
                        case 2011:
                            c2011+=1;
                            break;
                        case 2012:
                            c2012+=1;
                            break;
                        case 2013:
                            c2013+=1;
                            break;
                        case 2014:
                            c2014+=1;
                            break;
                        case 2015:
                            c2015+=1;
                            break;
                        case 2016:
                            c2016+=1;
                            break;
                        case 2017:
                            c2017+=1;
                            break;
                        case 2018:
                            c2018+=1;
                            break;
                    }
                }
                break;
            case 2:
                //retira
                retira(&lista,auxra);
                break;
        }
        imprimelista(lista);
    }
    
    printf("2011: %d\n",c2011);
    printf("2012: %d\n",c2012);
    printf("2013: %d\n",c2013);
    printf("2014: %d\n",c2014);
    printf("2015: %d\n",c2015);
    printf("2016: %d\n",c2016);
    printf("2017: %d\n",c2017);
    printf("2018: %d\n",c2018);
 
 
}