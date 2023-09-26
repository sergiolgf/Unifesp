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
//---------------------------------------------------
//***************************************************
void selection_sort(int size, int *vet){
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
//***************************************************
//---------------------------------------------------

void insertion_sort(int size, int *vet){
    int i,j,aux;
    for(i=1;i<size;i++){
        aux = vet[i];
        j=i-1;
        while (j >= 0 && vet[j] > aux)
        {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = aux;
    }
}
//---------------------------------------------------
//---------------------------------------------------
//***************************************************

void shell_sort(int size, int *vet){
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
//***************************************************


//-------------------------------------------------------------------------
void merge(int arr[], int esq, int m, int dir)
{
    int i, j, k;
    int n1 = m - esq + 1;
    int n2 = dir - m;
 
    int ESQ[n1], DIR[n2];
 
    for (i = 0; i < n1; i++)
        ESQ[i] = arr[esq + i];
    for (j = 0; j < n2; j++)
        DIR[j] = arr[m + 1 + j];
 

    i = 0;
    j = 0;
    k = esq;
    while (i < n1 && j < n2) {
        if (ESQ[i] <= DIR[j]) {
            arr[k] = ESQ[i];
            i++;
        }
        else {
            arr[k] = DIR[j];
            j++;
        }
        k++;
    }
 
     while (i < n1) {
        arr[k] = ESQ[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = DIR[j];
        j++;
        k++;
    }
}
 

void mergeSort(int *arr, int esq, int dir)
{
    if (esq < dir) {
        int m = esq + (dir - esq) / 2; //meio
 
        // Sort first and second halves
        mergeSort(arr, esq, m);
        mergeSort(arr, m + 1, dir);
 
        merge(arr, esq, m, dir);
    }
}

//----------------------------------------------------------------------------