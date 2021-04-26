#include <iostream>
#include "BinaryHeap.hpp"

using namespace std; 

int main() {

    BinaryHeap heap = BinaryHeap(); 

    heap.insert(10);
    heap.insert(12);
    heap.insert(16);
    heap.insert(14);
    heap.insert(13);
    heap.insert(18); 


    heap.toArray(); 

    /* 
                     18
                    /  \
                   /    \
                 14      16
                /  \     / 
               10  13   12
     */

    while ( !heap.empty() ) {
        cout << heap.top() << endl; 
        heap.extractTop(); 
    }

    return 0; 
}