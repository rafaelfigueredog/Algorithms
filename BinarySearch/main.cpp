#include <iostream>

using namespace std; 

int bsearch(int arr[], int size, int key) {
    int l = 0; 
    int r = size -1; 
    while ( l <= r ) {
        int m = (l + r)/2; 
        if ( arr[m] == key ) return m; 
        else if ( arr[m] > key ) r = m-1; 
        else l = m+1; 
    }
    return -1; 
} 


int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 17, 28,  32, 45, 76, 90, 100};
    int size = 16; 
    int key = 17; 
    cout << "index of: " << key << " is " <<  bsearch(arr, size, key) << endl; 
    return 0; 
}