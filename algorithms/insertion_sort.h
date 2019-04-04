void insertion_sort(int arr[], int n) {
    int i, j, tmp;
    
    for(i=1; i<n; i++){
        j = i;
        while(j >= 1 && arr[j-1] > arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = tmp;
            j--;
        }
    }
}