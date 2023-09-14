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

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergeSort(int *arr, int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}