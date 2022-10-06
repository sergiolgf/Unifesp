typedef struct{
    int tamanho;
    int lista[10];
}Tlista;

int removeel(Tlista *lista, int a){//lista,elemento a ser procurado e removido
    int i,j;
    for(i=0;i<lista->tamanho;i++){//roda a lista inteira procurando a
        if(lista->lista[i]==a){
            lista->lista[i]=0;//a vira 0
            lista->tamanho--;//diminui tamanho da lista
            for(j=i;j<lista->tamanho;j++){//a partir da posicao de a, ate o fim da lista
                lista->lista[j]=lista->lista[j+1];//posicao atual recebe o valor da proxima
            }
            printf("Remocao com sucesso\n");
            return 0;//saida da funcao
        }
    }
    printf("Elemento nao encontrado\n");
}