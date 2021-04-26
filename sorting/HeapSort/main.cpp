#include <iostream>
#include <algorithm>

using namespace std;

void siftDown(int* arr, int size, int i) {

    int left = 2*i + 1;
    int right = 2*i + 2; 
    int largest = i;  

    if ( left < size && arr[left] > arr[largest])
        largest = left; 

    if ( right < size && arr[right] > arr[largest])
        largest = right; 

    if ( largest != i ) {
        swap( arr[i], arr[largest] ); 
        siftDown(arr, size, largest); 
    }
}


// just to training
void siftUp() {
    // adiciona no final do array
    // verifica se arr[i] > arr[p]
    // se sim swap( arr[i], arr[p] )
    // chama recursivamente siftup(p);  
}

void HeapSort(int *arr, int size) {

    for (int i = (size/2)-1; i >= 0; i--) {
        siftDown(arr, size, i); 
    }

    
    for (int i = size-1; i > 0; i--) {
        swap(arr[i], arr[0]); 
        siftDown(arr, i, 0); 
    }
}

int main () {

    int *arr, n;  
    arr = new int[n]; 
    cin >> n;  
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];  

    HeapSort(arr, n); 
     
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";  

    return 0; 
}