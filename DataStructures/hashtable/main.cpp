#include <iostream>
#include "HashTable.hpp"

using namespace std; 

int main () {

    // load fator = n / k == 3 / 20 = 0.15 

    HashTable *map = new HashTable(10); 

    map->insert( {"Rafael", 389207 } ); 
    map->insert( {"Carlos", 893022 } ); 
    map->insert( {"João",   893426 } ); 

    // insert testing
    cout << "\nTest #1: inserting items\n"; 
    map->showHashTable(); 
    

    // seaching for items
    cout << "\nTest #2: Seaching for items\n"; 
    item result;
    string key = "Carlos"; 
    if ( map->search(key, &result) ) 
        cout << result.first << " " << result.second << endl; 
    else cout << "Not Found!"; 

    key = "Davi"; 
    if ( map->search(key, &result ) )  
        cout << result.first << " " << result.second << endl; 
    else cout << key <<" not Found\n" ; 


    // seaching for items
    cout << "\nTest #3: Deleting items\n"; 
    map->remove("João"); 
    map->showHashTable(); 
    return 0; 
}