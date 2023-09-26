#include <stdio.h>

void shell_sort(int *vet, int size){
    int i , j ;
    int h = 1;
    int x;
    
    do{
        h = h*3 + 1; 
    }while (h < size);

    do{
         h /= 3;
        for ( i = h; i < size; i++){
            x = vet[ i ];
            j = i ;
            while (vet[j-h] > x){
                vet[ j ] = vet[j-h];
                j -= h;
                if ( j < h) break;
            }
            vet[ j ] = x;
        }
    }while (h > 0);
}


int main(){
    int S,N;
    int j,cont = 0;
    int k;
    scanf("%d %d\n",&S,&N);

    int *vet = (int*)malloc(S*sizeof(int));
    for(int i=0;i<S;i++){
        if(i==0){
            scanf("%d",&vet[0]);
        }else{
            scanf(" %d",&vet[i]);
        }
    }

    shell_sort(vet,S);
    
    k = S-1;
    
    while(j!=k){
        if(vet[j]+vet[k]<N){
            j++;
        }else if(vet[j]+vet[k]>N){
            k--;
        }else{
            cont++;
            j++;
        }
    }
   
    printf("%d ",cont);
    
}