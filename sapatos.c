/* Roberswaldo ganha a vida vendendo produtos importados
comprados em suas viagens trimestrais para Miami. Na sua próxima viagem,
pretende trazer algumas encomendas de pares de sapatos feitas por antigos
clientes. Para que Roberswaldo possa comprar os sapatos,
cada cliente passa uma lista contendo a quantidade de sapatos para
determinada numeração no sistema brasileiro e gênero
(masculino / feminino). Devido ao elevado número de encomendas,
Roberswaldo precisa da sua ajuda para fazer um algoritmo que converta
as numerações para o sistema de numeração americana e diga quanto
de cada numeração e gênero comprar.

TAREFA
Desenvolva um algoritmo em linguagem C que receba um valor inteiro
L, 1 ≤ L ≤ 100, relativo à quantidade de encomendas de sapatos,
e L pares (N, G) com dois valores inteiros correspondentes à numeração
no sistema brasileiro (N) e o gênero (masculino / feminino) (G).
O algoritmo deve retornar, para cada gênero, a quantidade de sapatos
encomendada para cada numeração americana. A numeração de cada sapato
no sistema americano pode ser encontrada de acordo com o gênero e o
comprimento do pé em milímetros. Considere que cada unidade da numeração
no sistema brasileiro é equivalente a um pé de 6,67 mm. Para mulheres,
a conversão da numeração (CVm) pode ser realizada da seguinte maneira:
CVm = [( (comprimento em (mm) + 19) / 25, 4) × 3] − 23
enquanto que, para os homens a conversão (CVh)
pode ser determinada pela fórmula:
CVh = [( (comprimento em (mm) + 19) / 25, 4) × 3] − 24 (1.2)

ENTRADA
A entrada contém um único conjunto de teste, que deve ser lido
do dispositivo de entrada padrão (normalmente o teclado).
O conjunto de teste é composto por L + 1 linhas, , 1 ≤ L ≤ 100.
1. A primeira linha contém um valor inteiro L, 1 ≤ L ≤ 100,
que representa a quantidade de sapatos encomendada.
2. Em cada uma das L linhas seguintes é dado um par (N, G)
de valores inteiros. O par indica a numeração no sistema brasileiro N,
35 ≤ N ≤ 45, que deve ser comprada para o gênero G, em que G recebe 0
para se referir ao gênero masculino e 1 para feminino.

SAÍDA
Seu programa deve imprimir, na saída padrão, no mínimo uma e no
máximo duas strings com as seguintes informações:
• Gênero que pode ser masculino “M” ou feminino “F”.
Se houverem encomendas para os dois gêneros a saída deverá conter
duas strings, sendo a primeira para o gênero feminino e a segunda
para o masculino, caso contrário, apenas uma;
• Numeração no sistema americano com arredondamento de uma casa decimal.
Seja vd a parte decimal de CVm (CVh), o sistema de arredondamento deve
satisfazer as seguintes condições:
CV = ⌊CV ⌋ , se 0, 0 ≤ vd < 0, 4;
CV = ⌊CV ⌋ + 0, 5 , se 0, 4 ≤ vd < 0, 8
CV = ⌈CV ⌉ , se vd ≥ 0, 8.
O exemplo abaixo mostra como deve ser a saída do programa e qual a
sintaxe em C utilizada para exibi-lá.

F 5.0-(6) 6.5-(2) 7.0-(5) 9.0-(1)
M 6.0-(3) 8.0-(1) 9.0-(1)

printf(“F %.1f-(%d) %.1f-(%d) %.1f-(%d) %.1f-(%d)\n, numUSA_F[0], qtd_F[0],
numUSA_F[1], qtd_F[1], numUSA_F[2], qtd_F[2], numUSA_F[3], qtd_F[3]);
printf(M %.1f-(%d) %.1f-(%d) %.1f-(%d)”, numUSA_M[0], qtd_M[0], numUSA_M[1],
qtd_M[1], numUSA_M[2], qtd_M[2]);

Insira apenas um espaço antes de cada numeração. Após a numeração deve ser
inserido um traço “-” e entre parênteses a quantidade encomendada para esse tipo de
sapato. Note que numerações não encomendadas não entram na string de saída. */

#include <stdio.h>
#include <stdlib.h>
 
int main(){
    int L; //quantidade de sapatos
    int j=0,i=0; //loop
    float N;
    int inteiro;
    float resto;
    float compara; //elimina duplicados no vetor
    int G;
    int quant=1;
    int contM=0,contF=0;
    float *vetorM,*vetorF;
 
 
    scanf("%d",&L);
 
    vetorM = (float*)malloc(L*sizeof(float));
    vetorF = (float*)malloc(L*sizeof(float));
 
    //leitura e conversao para USA
    for(i=0;i<L;i++){
        scanf("%f %d",&N,&G);
        if(G==0){
            //masculino
            
            N= (N*6.67+19)/25.4*3-24;
            
            //arredonda
            //9.465
            inteiro = N;//9
            resto = N-inteiro;//0.465
            if (resto < 0.4){
                N=inteiro;
            }
            else if (resto >= 0.4 && resto < 0.8){
                N = N-resto+0.5;
            }
            else{
                N=N-resto+1;
            }
            
            
            vetorM[contM] = N;
            contM++;
        
 
        }else{
            //feminino
            N= (N*6.67+19)/25.4*3-23;
 
            //arredonda
            //9.465
            inteiro = N;//9
            resto = N-inteiro;//0.465
            if (resto < 0.4){
                N=inteiro;
            }
            else if (resto >= 0.4 && resto < 0.8){
                N = N-resto+0.5;
            }
            else{
                N=N-resto+1;
            }
 
 
            vetorF[contF]=N;
            contF++;
        }
    }
 
 
    //coloca ordem
    for (i = 0; i < contM; ++i){
        for (j = i + 1; j < contM; ++j){
            if (vetorM[i] > vetorM[j]){
                compara =  vetorM[i];
                vetorM[i] = vetorM[j];
                vetorM[j] = compara;
            }
        }
    }
    for (i = 0; i < contF; ++i){
        for (j = i + 1; j < contF; ++j){
            if (vetorF[i] > vetorF[j]){
                compara =  vetorF[i];
                vetorF[i] = vetorF[j];
                vetorF[j] = compara;
            }
        }
    }
    
 
 
 
    
    //imprime feminino
    if(contF>0){
        quant=1;
        printf("F");
        for(j=0;j<contF;){
            printf(" %.1f",vetorF[j]);
            for(i=j+1;vetorF[i]==vetorF[j];i++){
               quant++;
            }
            printf("-(%d)",quant);
            quant=1;
            j=i;
        }
        printf("\n");
    }
 
    //imprime masculino
    if(contM>0){
        quant=1;
        printf("M");
        for(j=0;j<contM;){
            printf(" %.1f",vetorM[j]);
            for(i=j+1;vetorM[i]==vetorM[j];i++){
               quant++;
            }
            printf("-(%d)",quant);
            quant=1;
            j=i;
        }
        printf("\n");
    }
    free(vetorM);
    free(vetorF);
 
    return 0;
}