void selection_sort(int arr[], int n) {
    int i, j, tmp;
    int lowestIndex, lowestValue;

    for(i=0; i<n-1; i++){
        lowestIndex = i;
        lowestValue = arr[i];
        for(j=i+1; j<n; j++){
            if(arr[j] < lowestValue) {
                lowestIndex = j;
                lowestValue = arr[j];
            }
        }
        tmp = arr[i];
        arr[i] = arr[lowestIndex];
        arr[lowestIndex] = tmp;
    }
}