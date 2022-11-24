#include <stdio.h>
#include <stdlib.h>
 
typedef struct elemento {
    int valor;
    struct elemento *ant;
} TElemento;
 
typedef struct pilha{
    int tamanhoPilha;
    TElemento *topo;
} Tpilha;
 
void iniciaPilha(Tpilha* pilhaaux){
    pilhaaux->topo=NULL;
    pilhaaux->tamanhoPilha=0;
}
 
 
 
void Push(Tpilha* pilhaaux,int num){
    TElemento *novo;

    novo = (TElemento*)malloc(sizeof(TElemento));
    novo->valor=num;
    if(pilhaaux->tamanhoPilha==0){
        pilhaaux->topo=novo;
        novo->ant=NULL;
    }else{
        novo->ant=pilhaaux->topo;
        pilhaaux->topo=novo;
    }
    pilhaaux->tamanhoPilha++;
 
}
 
 
 
int Pop(Tpilha* pilhaaux){
    int num;
    TElemento *p;

    num = pilhaaux->topo->valor;
    p=pilhaaux->topo->ant;
    free(pilhaaux->topo);
    pilhaaux->topo=p;
    pilhaaux->tamanhoPilha--;
    
    return num;
}
 
int pow(int a, int b){
    int i,x;
 
    x=1;
    for(i=0;i<b;i++){
        x*=a;
    }
 
    return x;
}
 
 
 
void dec_bin_Tbin_Tdec(int dec){
    Tpilha pilhadec, pilhabin, pilhaTbin,pilhaTdec, pilhaTdec2;
    int resto;
    int i;
    int Tdec=0;
    int pop,bin=0;
    int flag=0;
 
    iniciaPilha(&pilhadec);
    iniciaPilha(&pilhabin);
    iniciaPilha(&pilhaTbin);
    iniciaPilha(&pilhaTdec);
    iniciaPilha(&pilhaTdec2);

    printf("%d ",dec);
 
    //dectobin
    while (dec!=0){
        resto = dec%2;
        Push(&pilhadec,resto);
        dec=dec/2;
    }
 
    //print bin - bintoTbin
    while(pilhadec.tamanhoPilha!=0){
        pop = Pop(&pilhadec);
        printf("%d",pop);
        Push(&pilhabin,pop);
    }
    iniciaPilha(&pilhadec);
 
    while(pilhabin.tamanhoPilha!=0){
        pop=Pop(&pilhabin);
        if(pop==0){
            Push(&pilhaTbin,1);
        }else{
            Push(&pilhaTbin,0);
        }
    }
    iniciaPilha(&pilhabin);
 
    printf(" ");

    //print Tbin - TbintoTdec2
    while(pilhaTbin.tamanhoPilha!=0){
        pop = Pop(&pilhaTbin);
        printf("%d",pop);
        if(flag==0&&pop==0){
        
        }else if(pop==1){
            Push(&pilhaTdec,1);
            flag=1;
        }else{
            Push(&pilhaTdec,0);
        }
    }
 
    printf(" ");
 
    while(pilhaTdec.tamanhoPilha!=0){
        Push(&pilhaTdec2,Pop(&pilhaTdec));
    }
 
    for(i=pilhaTdec2.tamanhoPilha;i>0;i--){
        pop = Pop(&pilhaTdec2);
        Tdec+=pop*pow(2,i-1);
    }

    printf("%d\n",Tdec);
}
 
 
 
int main(){
    int num;
    int i,L;

    scanf("%d",&L);
    for(i=0;i<L;i++){
        scanf("%d",&num);
        dec_bin_Tbin_Tdec(num);
    }
    return 0;
}