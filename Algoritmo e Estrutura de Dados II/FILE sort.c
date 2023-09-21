#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define elements 10

void preenche_vetor(int *vet, int size, FILE *arq){
    for(int i=0;i<size;i++){
        if(i==0){
           fscanf(arq,"%d",&vet[0]); 
        }else{
            fscanf(arq," %d",&vet[i]);
        }
    }
}

void imprime_vetor(int *vet, int size){
    int i;
    printf("\n\n");
    for(i=0;i<size;i++){
        if(i==0){
            printf("%d", vet[i]);
        }else{
            printf(" %d", vet[i]);
        }
    }
    printf("\n\n");
}

void selection_sort(int *vet, int size){
    int i,j,min,aux;
    for(i=0;i<size-1;i++){
        min = i;
        for(j=i+1;j<size;j++){
            if(vet[j]<vet[min]){
                min = j;
            }
        }
        aux = vet[min];
        vet[min] = vet[i];
        vet[i]=aux;

    }
}

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

int acha_max(int array[], int size) 
{  
    int max;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)  
        max = array[i];  
    }
    return max;  
}
 
void bucket_sort(int array[], int size) 
{  
    int max = acha_max(array, size); 

    //nbaldes = maiornum + 1
 
    int bucket[max+1];  
 
    //inicia baldes em 0
    for (int i = 0; i <= max; i++){  
        bucket[i] = 0;  
    }

    // soma 1 na posicao se houver numero
    for (int i = 0; i < size; i++){
        bucket[array[i]]++;
    }
    
    int j=0;   // indice do vetor destino
    //para cada balde
    for (int i = 0; i <= max; i++)  
    { 
        // enquanto tiver elementos no balde (repeticoes)
        while (bucket[i] > 0){

            // coloca cada elemento do balde no novo vetor          
            array[j++] = i;  
 
            // tira um elemento do balde
            bucket[i]--;   
        }  
    }  
}  


int main(int argc,char* argv[]){
	if(argc!=3){// nome programa; nome arquivo vetor; num opcao sort
		printf("\nErro parametros %d\n",argc);
		exit(1);
	}
	FILE *arq;
	arq = fopen(argv[1],"r");
	if(arq==NULL){
		printf("\nErro arquivo\n");
		exit(2);
	}

    int *vet;
    vet = (int*)malloc(elements*sizeof(int));

    preenche_vetor(vet,elements,arq);

    imprime_vetor(vet,elements);
    
    
    //sort
    switch(atoi(argv[2])){
        case 1:
            printf("Selection sort");
            selection_sort(vet,elements);
            break;
 
        case 2:
            printf("Shell sort");
            shell_sort(vet,elements);
            break;

        case 3:
            printf("Bucket sort");
            bucket_sort(vet,elements);
            break;
        
        default:
            printf("Erro opcao sort");
    }
    

    imprime_vetor(vet,elements);

    free(vet);
}