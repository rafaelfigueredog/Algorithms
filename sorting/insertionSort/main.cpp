#include <iostream>
#include <algorithm>

using namespace std; 

void insertionSort( int * arr, int size) {
    int i, j; 
    for (int i = 1; i < size; i++) {
        j = i; 
        while (j > 0 && arr[j] < arr[j-1]) {
            swap(arr[j], arr[j-1]); 
            j--; 
        }
    }
}


int main () {

    int *arr, n;  
    arr = new int[n]; 
    cin >> n;  
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];  

    insertionSort(arr, n); 
     
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";  

    return 0; 
}