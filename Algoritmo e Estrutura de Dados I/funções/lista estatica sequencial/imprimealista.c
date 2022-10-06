typedef struct{
    int tamanho;
    int lista[10];
}Tlista;

void imprimelista(Tlista *lista){
    int i;
    for(i=0;i<lista->tamanho;i++){//percorre a lista ate ultima posicao ocupada
        printf("%d ",lista->lista[i]);//imprime conteudo na posicao do indice
    }
}