#include <iostream>
#include <algorithm>

using namespace std;

template<class T> class Node {
    public:
        T key; 
        Node* left; 
        Node* right; 
        int height; 
        Node(T key);  
}; 

template<class T> class BinaryTree {
    public:
        Node<T>* root; 
        BinaryTree(); 
        void insert(Node<T>* newNode);
        

    private:
        Node<T>* insertHelper(Node<T>* root, Node<T>* newNode);
        int height(Node<T>* root);  
        int getBalance(Node<T>* root);  
        Node<T>* leftRotate(Node<T>* x); 
        Node<T>* rightRotate(Node<T>* y); 

}; 

template<typename T>
Node<T>::Node(T key) {   
    this->key = key; 
    left = nullptr;
    right = nullptr; 
    height = 1; 
}

template<typename T>
int BinaryTree<T>::height( Node<T>* root) {
    if ( !root ) return 0; 
    return root->height; 
}

template<typename T>
int BinaryTree<T>::getBalance( Node<T>* root) {
    if (!root) return 0; 
    return height(root->left) - height(root->right); 
}

template<typename T> 
BinaryTree<T>::BinaryTree() {
    this->root = nullptr; 
}

template<typename T>
Node<T>* BinaryTree<T>::rightRotate(Node<T>* y)
{
    Node<T> *x = y->left;
    Node<T> *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;
 
    // Return new root
    return x;
}


template<typename T>
Node<T>* BinaryTree<T>::leftRotate( Node<T>* x ) {

    Node<T>* y = x->right;
    Node<T>* t2 = y->left; 
    
    y->left = x;
    x->right = t2;
 
    // Update heights
    x->height = max(height(x->left),   
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;
 
    // Return new root
    return y; 
}  


template<typename T> 
Node<T>* BinaryTree<T>::insertHelper(Node<T>* root, Node<T>* newNode) {

    if ( !root ) return newNode; 

    if ( newNode->key < root->key )
        root->left = insertHelper(root->left, newNode); 
    
    else if (newNode->key > root->key )
        root->right = insertHelper(root->right, newNode); 

    else 
        return root; // equal elements is not allowed

    root->height = 1 + max( height(root->left),  height(root->right));

    int balance = getBalance(root); 

    // Left Left Case
    if (balance > 1 && newNode->key < root->left->key)
        return rightRotate(root);
 
    // Right Right Case
    if (balance < -1 && newNode->key > root->right->key)
        return leftRotate(root);
 
    // Left Right Case
    if (balance > 1 && newNode->key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Left Case
    if (balance < -1 && newNode->key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 

    return root; 
}

template<typename T> 
void BinaryTree<T>::insert(Node<T> *newNode) {
    this->root =  BinaryTree<T>::insertHelper(this->root, newNode);
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

    BinaryTree<int>* bst = new BinaryTree<int>(); 
    
    bst->insert(new Node<int>(18));
    bst->insert(new Node<int>(14));
    bst->insert(new Node<int>(19));
    bst->insert(new Node<int>(13));
    bst->insert(new Node<int>(15));
    bst->insert(new Node<int>(10)); 

    // Inorder( bst->root ); 
    preorder( bst->root ); 

    return 0; 
}