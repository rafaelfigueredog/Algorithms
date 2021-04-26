#include "BinaryHeap.hpp"
#include <cstdlib>
#include <algorithm>
#include <stdexcept>
#include <iostream>

#define STARTSIZE 8
using namespace std; 

int BinaryHeap::parent(int i) { return (i - 1)/2; }  
int BinaryHeap::left(int i) { return 2*i + 1; }
int BinaryHeap::right(int i) { return 2*i + 2; } 

BinaryHeap::BinaryHeap() {
    arr = new int[STARTSIZE];
    capacity = STARTSIZE; 
    size = 0; 
}


void BinaryHeap::siftDown(int i) {

    int l = left(i); 
    int r = right(i); 
    int largest = i; 

    if ( l < size && arr[l] > arr[i] )
        largest = l; 

    if ( r < size && arr[r] > arr[largest] )
        largest = r;    

    if ( largest != i ) {
        swap(arr[i], arr[largest]); 
        siftDown(largest); 
    }
} 
void BinaryHeap::siftUp(int i) {
    int p = parent(i); 
    // first check if "i" is greater than 0. 
    if ( i && arr[p] < arr[i] ) {
        swap(arr[i], arr[p]); 
        siftUp(p); 
    }
} 

int* BinaryHeap::resize(int *arr) {
    this->capacity = capacity * 2; 
    return (int*) realloc(arr, capacity); 
}



void BinaryHeap::insert( int v ) {
    if (size == capacity)
        arr = resize(arr); 

    arr[size++] = v; 
    siftUp(size-1); 
}

void BinaryHeap::extractTop() {

    try {

        if ( size == 0 ) {
            throw out_of_range("Error : Empty BinaryHeap!"); 
        }
        
        swap(arr[0], arr[size-1]); size--; 
        siftDown(0); 
    } 
    
    catch (const out_of_range &err) {
        cout << err.what() << endl; 
    }

}

int BinaryHeap::top() {
     try {

        if ( size == 0 ) {
            throw out_of_range("Error : Empty BinaryHeap!"); 
        }
        
        return arr[0]; 
    } 
    
    catch (const out_of_range &err) {
        cout << err.what() << endl;
    }

    return -1; 
}

void BinaryHeap::toArray() {
    cout << "["; 
    for (int i = 0; i < size; i++)
        if (i != size-1) cout << arr[i] << " "; 
    cout << arr[size-1] << "]" << endl;  
}

bool BinaryHeap::empty(){
    return size == 0; 
}