typedef struct{
    int tamanho;
    int lista[10];
}Tlista;

void inserefim(Tlista *lista,int a){//lista, elemento a ser inserido
    if(lista->tamanho==10){
        printf("Lista de reserva cheia\n");
    }else{
        lista->tamanho++;
        lista->lista[lista->tamanho-1]=a;//indice=tamanho-1
        printf("Sua reserva foi realizada\n");
    }
}