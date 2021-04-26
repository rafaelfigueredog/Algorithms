#include <iostream>

using namespace std;

template<class T> class Node {
    public:
        T key; 
        Node* left; 
        Node* right; 

        Node(T key); 
}; 

template<typename T>
Node<T>::Node(T key) {   
    this->key = key; 
    left = nullptr;
    right = nullptr; 
}

template<typename T>
void Inorder(Node<T> *root) {
    if ( root == nullptr ) return; 
    Inorder( root->left ); 
    cout << root->key << endl; 
    Inorder( root->right ); 
}

template<typename T>
void preorder(Node<T> *root) {
    if ( root == nullptr ) return; 
    cout << root->key << endl; 
    preorder( root->left ); 
    preorder( root->right );  
}       

template<typename T>
void posOrder(Node<T> *root) {
    if ( root == nullptr ) return; 
    posOrder( root->left ); 
    posOrder( root->right ); 
    cout << root->key << endl;  
}       


int main() {

    Node<int>* root = new Node<int>(16);

    root->left = new Node<int>(10); 
    root->left->left = new Node<int>(5);
    root->left->right = new Node<int>(14);
    root->right = new Node<int>(18); 

    Inorder(root); 
    cout << endl; 

    preorder(root);
    cout << endl; 

    posOrder(root);
    cout << endl; 

    return 0; 
}