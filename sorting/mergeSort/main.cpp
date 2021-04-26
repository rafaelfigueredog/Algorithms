// Problem: implement a mergesort algorithm;

#include <iostream>
#include <algorithm>

using namespace std; 

void merge(int *arr, int* helper, int l, int m, int r) {

    // [ 2 3 4 5 ]
    
    for (int i = l; i <= r; i++) 
        helper[i] = arr[i]; 

    int i = l;
    int j = m + 1; 
    int k = l;  

    while ( i <= m && j <= r) {
        if ( helper[i] < helper[j] ) {
            arr[k] = helper[i];
            i++; 
        }
        else {
            arr[k] = helper[j]; 
            j++; 
        }
        k++;
    }

    // the second part finished first 
    while (i <= m) {
        arr[k] = helper[i]; 
        i++; 
        k++; 
    }

    // the first part finiched first 
    while (j <= r) {
        arr[k] = helper[j]; 
        j++; 
        k++; 
    }

    return; 
} 


void mergeSort(int *arr, int *helper,  int l, int r) {

    if ( l >= r ) 
        return;   

    int m = (l + r)/2; 
    mergeSort(arr, helper, l, m); 
    mergeSort(arr, helper, m+1, r); 
    merge(arr, helper, l, m, r); 
}


void mergeSort(int * arr, int size ) {
    int *helper = new int[size];  
    return mergeSort(arr, helper, 0, size-1); 
}

int main () {

    int *arr, n; 
    cin >> n; 
    arr = new int[n]; 

    for (int i = 0; i < n; i++) 
        cin >> arr[i]; 

    mergeSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " "; 


    return 0; 
}