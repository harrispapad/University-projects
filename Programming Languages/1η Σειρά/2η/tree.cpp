          
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Node {
    int data;
    int min;
    Node* left;
    Node* right;
    Node(int value) : data(value), min(value), left(nullptr), right(nullptr) {} // constructor
};

Node* insert_value(Node* root, const vector<int>& a, int& j) {
    if (j >= static_cast<int>(a.size()) || a[j] == 0) {
        return nullptr;  
    }

    root = new Node(a[j]);  

    if (a[j] != 0) {
        root->left = insert_value(root->left, a, ++j);
    }

    root->right = insert_value(root->right, a, ++j);

    return root;  
}

Node* create_tree(const vector<int>& arr) {
    if (arr.empty()) return nullptr;

    Node* root = nullptr;
    int j = 0;  
    root = insert_value(root, arr, j); 
    return root;
}

void printInorder(Node* node) {
    if (node == nullptr)
        return;

    printInorder(node->left);

    if(node->data != 0)
        cout << node->data << " ";

    printInorder(node->right);
}

void swap(Node* node){
    // If left child is null, create a new node with data 0
    if (node->left == nullptr) {
        node->left = new Node(0);
    }
    // If right child is null, create a new node with data 0
    if (node->right == nullptr) {
        node->right = new Node(0);
    }

    // Swap the children
    Node* tempNode = node->left;
    node->left = node->right;
    node->right = tempNode;
}

void check_lex(Node* node) {
    if (node == nullptr){
        return;
    }
    
    check_lex(node->left);
    check_lex(node->right);

    if(node->left == nullptr && node->right == nullptr){
                return;
    }
    else if (node->left == nullptr) {
        if (node->min > node->right->min) {
            swap(node);
            node->min = node->left->min;
        } 
    } 
    else if (node->right == nullptr) {
        if (node->min < node->left->min) {
            swap(node);
        } else {
            node->min = node->left->min;
        }
    } 
    else {
        if (node->left->min > node->right->min) {
            swap(node);
            node->min = node->left->min;
        } else {
            node->min = node->left->min;
        }
    }
}


int main(int argc, char* argv[]) {
    ifstream inputFile(argv[1]);

    int size;
    inputFile >> size; 

    vector<int> a;
    int value;
    while (inputFile >> value) {
        a.push_back(value);
    }
    inputFile.close();

    Node* root = create_tree(a);




    check_lex(root);
    printInorder(root);
    cout<<endl;
    
    return 0;
}        
