#include <iostream>
#include <algorithm>

using namespace std; 

int partition( int *arr, int l, int r) {
    int pivot = arr[r]; 
    int i = 0;
    for (int j = 0; j <= r; j++) {
        if ( arr[j] < pivot ) 
            swap(arr[i++], arr[j]);
    } 
    swap(arr[i], arr[r]); 
    return i; 
}



void quickSort(int *arr, int l, int r) {
    if ( r >= l ) {
        int p = partition(arr, l, r); 
        quickSort(arr, p+1, r); 
        quickSort(arr, l, p-1); 
    } 
    return; 
}


int main () {

    int *arr, n;  
    arr = new int[n]; 
    cin >> n;  
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];  

    quickSort(arr, 0, n-1); 
     
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";  

    return 0; 
}