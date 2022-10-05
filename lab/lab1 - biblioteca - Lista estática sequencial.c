/*A biblioteca do ICT permite que os usuários reservem livros que não estão disponíveis.
Assim, quando o livro ficar disponível, o usuário poderá retirá-lo. Portanto, torna
se necessário a utilização de um sistema que gerencie as reservas realizadas pelos usuários.

TAREFA A
Desenvolva um algoritmo em linguagem C utilizando lista estática sequencial
que reproduza as atividades executadas pelo sistema de gerenciamento de reservas
da biblioteca. Nessa tarefa, vamos assumir que o seu programa será utilizado para
gerenciar as reservas de apenas um usuário. Além disso, são permitidas no máximo
10 reservas por usuário.
O programa deverá imprimir uma mensagem sempre que uma nova reserva for soli-
citada ou um livro for retirado. Se uma nova reserva for solicitada e a lista de reservas
estiver cheia, o programa deverá imprimir esta informação. Quando a reserva for
concluída, o programa deverá imprimir quantas reservas aquele usuário já realizou.
Quando um livro for retirado, a mensagem deverá incluir quantos livros aquele usuário
já retirou. Note que as inclusões de novas reservas ocorrem sempre ao final da lista.

ENTRADA
A entrada contém um único conjunto de teste, que deve ser lido do dispositivo de
entrada padrão (normalmente o teclado). O conjunto de teste é composto por L + 1
linhas, 1 ≤ L ≤ 100.
1. A primeira linha contém um valor inteiro L, 1 ≤ L ≤ 100, que representa a
quantidade de movimentações (reservas e retiradas) serão realizadas.
2. Em cada uma das L linhas seguintes são dadas as informações. Cada linha
contém um valor inteiro - ’1’ para reservar ou ’2’ para retirar seguida de um
espaço e o número do livro (N), 1 ≤ N ≤ 100.
Para as operações de entrada, considere a sintaxe:
scanf("%d",&variavel);
scanf("%d %d",&variavel1, &variavel2);

SAÍDA
Como saída padrão, seu programa deve imprimir as seguintes informações:
1. Reserva concluída com sucesso: "Sua reserva foi realizada".
2. Se a lista de reservas estiver cheia: "Lista de reserva cheia".
3. Se você tentar retirar um livro, mas não possuir reserva: "Voce nao possui
reserva desse livro".
4. Se você retirar um livro com sucesso: "O livro foi retirado com sucesso"
Ao final da execução, você deverá imprimir quantas reservas e quantas retiradas foram
feitas ao todo.
Para as operações de saída, considere a sintaxe:
printf("Instrucao de saida\n");
printf("Voce realizou %d reservas e %d retiradas\n", reservas, retidas); */

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

void inserefim(Tlista *lista,int a){
    lista->tamanho++;
    lista->lista[lista->tamanho-1]=a;
}

Tlista removeel(Tlista *lista, int a){
    int i,j;
    for(i=0;i<lista->tamanho;i++){
        if(lista->lista[i]==a){
            lista->lista[i]=0;
            lista->tamanho--;
            for(j=i;j<lista->tamanho;j++){
                lista->lista[j]=lista->lista[j+1];
            }
            return *lista;
        }
    }
}

void imprimelista(Tlista *lista){
    int i;
    for(i=0;i<lista->tamanho;i++){
        printf("%d ",lista->lista[i]);
    }
}

int main(){
    Tlista lista;
    int a=10,b=20,c=30;

    inicialista(&lista);
    inserefim(&lista,a);
    inserefim(&lista,c);
    inserefim(&lista,b);
    removeel(&lista,20);

    imprimelista(&lista);
    
    return 0;
}