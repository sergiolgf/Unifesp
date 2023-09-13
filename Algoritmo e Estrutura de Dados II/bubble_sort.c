void bubble_sort(int size, int *vet){
    int k,l,i;
    int aux;
    for(k=size-1;k>0;k--){
        for(l=0;l<k;l++){
            if(vet[l]>vet[l+1]){
                aux = vet[l+1];
                vet[l+1] = vet[l];
                vet[l] = aux;
            }
        }
    }
}