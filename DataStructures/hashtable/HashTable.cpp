#include "HashTable.hpp"
#include <iostream>
#include <utility>


HashTable::HashTable( int capacity ) {
    table = new list<item>[capacity];
    this->tablesize = capacity; 
}

int HashTable::hashFunction( string key ) {
    int index = 0; 
    for ( int i = 0; i < (int) key.size(); i++ ) 
        index += ((int) key[i]) + i;


    // debug hash
    cout << key << " hash value: " <<  index << endl; 
    return index % tablesize;  
}

void HashTable::insert(item v) {
    int index = hashFunction( v.first );
    table[index].push_front(v);   
}

bool HashTable::search(string key, item* result) {
    
    int i = hashFunction( key ); 

    for ( auto it = table[i].begin() ; it != table[i].end(); it++ ) {
        if ( it->first == key ) {
           result->first = it->first; 
           result->second = it->second;  
           return true; 
        } 
    }
    return false; 
}



void HashTable::showHashTable() {
    for (int i = 0; i < tablesize; i++) {
         
        if (table[i].empty()) {
            cout << i << endl; 
            continue; 
        }
        cout << i << " ";
        unsigned long k = 0; 
        for ( auto it = table[i].begin(); it != table[i].end(); it++) {
            printf("(%s - %d)", it->first.c_str(), it->second ); 
            if ( k == table[i].size() - 1 ) cout << endl; 
            else cout << " -> ";
            k++; 
        }
    }
} 

void HashTable::remove(string key) {

    int i = hashFunction( key );
    
    list<item>::iterator todelete;  
    for ( auto it = table[i].begin(); it != table[i].end(); it++) {
        if ( it->first == key ) {
            todelete = it; 
        } 
    }

    table[i].erase(todelete); 
    return;
}