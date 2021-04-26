class BinaryHeap {

    private: 
        int *arr; 
        int size; 
        int capacity; 
        int parent(int i);  // ok
        int left(int i); // ok
        int right(int i); // ok
        void siftDown(int i); 
        void siftUp(int i); // ok
        int* resize(int *arr); // ok
        
    public:
        BinaryHeap(); // ok
        void extractTop(); // ok;  
        void toArray(); // ok
        void insert(int v); // ok; 
        bool empty(); // ok
        int top(); // ok;  
        

}; 