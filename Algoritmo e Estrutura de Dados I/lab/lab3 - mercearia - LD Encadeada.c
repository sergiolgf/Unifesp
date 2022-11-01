#include <stdio.h>
#include <stdlib.h>

typedef struct produto{
    int id;
    float lucro;
    float lucrototal;
    int quantidade;
    struct produto *prox;
}Tproduto;

typedef struct{
    Tproduto *primeiro;
    Tproduto *ultimo;
    int tamanho;
}LDE;

void inicialista(LDE *listaaux){
    listaaux->primeiro=NULL;
    listaaux->ultimo=NULL;
    listaaux->tamanho=0;
}

int insert(LDE *listaaux,int idaux, int quantaux, float lucroaux){
    Tproduto *p,*i,*j;
    
    
    
    p=(Tproduto*)malloc(sizeof(Tproduto));
    p->lucro=lucroaux;
    p->id=idaux;
    p->quantidade=quantaux;
    p->lucrototal=0;
    
    
    for(i=listaaux->primeiro;i!=NULL;i=i->prox){
        if(i->id==idaux){
            printf("Ja existe\n");
            return 1;
        }
    }
    
    
    if(listaaux->tamanho==0){
        listaaux->primeiro=p;
        listaaux->ultimo=p;
        p->prox=NULL;
        listaaux->tamanho+=1;
    }else if(p->lucro>listaaux->primeiro->lucro){
        //insere antes do primeiro
        p->prox=listaaux->primeiro;
        listaaux->primeiro=p;
        listaaux->tamanho+=1;
    }else if(p->lucro<listaaux->ultimo->lucro){
        //insere depois do ultimo
        p->prox=NULL;
        listaaux->ultimo->prox=p;
        listaaux->ultimo=p;
        listaaux->tamanho+=1;
    }else{
        //insere meio
        for(i=listaaux->primeiro;i!=NULL;i=i->prox){
            if(p->lucro>=i->lucro){
                //insere antes do i
                j->prox=p;
                p->prox=i;
                listaaux->tamanho+=1;
                return 0;
            }
            j=i;
        }
        return 1;
    }
    return 0;
}

int excluiproduto(LDE *listaaux,int idaux){
    Tproduto *p,*q;
    if(listaaux->tamanho==0){
        printf("lista vazia");
        return 0;
    }
    if(listaaux->primeiro->id==idaux){
        p=listaaux->primeiro->prox;
        free(listaaux->primeiro);
        listaaux->primeiro=p;
        return 0;
    }
    for(p=listaaux->primeiro;p!=NULL;p=p->prox){
        if(p->id==idaux){
            if(p==listaaux->ultimo){
                listaaux->ultimo=q;
                q->prox==NULL;
            }else{
                q->prox=p->prox;
            }
            free(p);
            return 0;
        }
        q=p;
    }
    printf("nao existe\n");
}

int aumenta(LDE *listaaux,int idaux, int quantaux){
    Tproduto *p;
    for(p=listaaux->primeiro;p!=NULL;p=p->prox){
        if(p->id==idaux){
            p->quantidade+=quantaux;
            return 0;
        }
    }
    printf("nao existe\n");
    return 1;
}
int compra(LDE *listaaux, int idaux){
    Tproduto *p;
    for(p=listaaux->primeiro;p!=NULL;p=p->prox){
        if(p->id==idaux){
            if(p->quantidade==0){
                printf("nao existe\n");
            }else{
                p->lucrototal=p->lucrototal+p->lucro;
                p->quantidade-=1;
            }
            return 0;
        }
    }
    printf("nao existe\n");
}

void lucrototal(LDE *listaaux){
    Tproduto *p;
    for(p=listaaux->primeiro;p!=NULL;p=p->prox){
        printf("%d %f\n",p->id,p->lucrototal);
    }
}

void imprime(LDE *listaaux){
    Tproduto *p;
    for(p=listaaux->primeiro;p!=NULL;p=p->prox){
        printf("id: %d\n",p->id);
    }
}



int main(){
    int L,op;
    int i;
    int id,quant;
    float lucro;
    LDE lista;

    inicialista(&lista);

    scanf("%d",&L);
    for(i=0;i<L;i++){
        scanf("%d ",&op);
        switch(op){
            case 1:
                //add produto
                scanf("%d %d %f",&id,&quant,&lucro);
                insert(&lista,id,quant,lucro);
                break;
            case 2:
                //aumenta quantidade
                scanf("%d %d",&id,&quant);
                aumenta(&lista,id,quant);
                break;
            case 3:
                //compra
                scanf("%d",&id);
                compra(&lista,id);
                break;
            case 4:
                //exclui produto
                scanf("%d",&id);
                excluiproduto(&lista,id);
                break;
        }
        
    }
    lucrototal(&lista);
}