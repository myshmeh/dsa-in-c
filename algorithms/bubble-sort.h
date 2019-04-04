void bubble_sort(int arr[], int n) {
    int i, j, tmp;

    for(i=0; i<n-1; i++){
        for(j=n-1; j>i; j--){
            if(arr[j-1] > arr[j]){
                tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
        }
    }
}

void bubble_sort2(int arr[], int n) {
    int i, j, tmp;

    for(i=0; i<n-1; i++) {
        for(j=i; j<n-1; j++) {
            if(arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}