typedef struct{
    int tamanho;
    int lista[10];
}Tlista;

void inicialista(Tlista *lista){
    int i;
    lista->tamanho=0;//zera o tamanho
    for(i=0;i<10;i++){
        lista->lista[i]=0;//limpa o vetor
    }
}