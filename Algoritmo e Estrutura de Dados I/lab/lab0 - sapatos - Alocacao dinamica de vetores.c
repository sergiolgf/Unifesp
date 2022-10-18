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