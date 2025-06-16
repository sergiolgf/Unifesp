#include <stdio.h>
#include <stdlib.h>

int calc_pos(int k,int m, int i){
	int h1 = k%m;
	int h2 = 1+(k%(m-1));
	int pos = (h1+i*h2)%m;
	return pos;
}

void hash(int *vet,int k,int m){
	int i=0;

	while(vet[calc_pos(k,m,i)]!=-1) i++;

	vet[calc_pos(k,m,i)]=k;
	
}

void remove_hash(int *vet, int tam, int r){
	int i=0;
	while((i<tam)&&(vet[calc_pos(r,tam,i)]!=r)) i++;

	if(i>=tam){
		printf("Valor nao encontrado\n");
	}else{
		while(vet[calc_pos(r,tam,i)]==r){
			vet[calc_pos(r,tam,i)]=-2;
			i++;
		}
	}
}

void print_vet(int *vet, int size){
	for(int i=0;i<size;i++){
		if(i!=0){
			if(vet[i]==-1)printf(" \\");//uma barra
			else if(vet[i]==-2)printf(" D");
			else	printf(" %d",vet[i]);
		}else{
			if(vet[i]==-1)printf("\\");
			else if(vet[i]==-2)printf("D");
			else printf("%d",vet[i]);
		}
	}
	printf("\n");
}

int main(){
	int *vet;
	int tam,k;
	int j,r;

	scanf("%d",&tam);
	vet = (int*)malloc(tam*sizeof(int));
	
	for(j=0;j<tam;j++)
		vet[j]=-1;

		
	scanf("%d",&k);
	while(k!=-1){
		hash(vet,k,tam);
		scanf("%d",&k);
	}

	scanf("%d",&r);

	remove_hash(vet,tam,r);
		
	print_vet(vet,tam);

	free(vet);
}



