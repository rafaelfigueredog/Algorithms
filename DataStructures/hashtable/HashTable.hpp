#include <list>
#include <utility>
#include <string>

using namespace std; 

typedef pair<string, int> item; 


class HashTable {
    private:
        list<item> *table; 
        int tablesize;  

        // That's a simple hash function.
        int hashFunction( string key );

    public: 

        void insert(item v); 
        bool search(string key, item* result); 
        void remove(string key);

        HashTable( int capacity ); 
        void showHashTable(); 

}; 