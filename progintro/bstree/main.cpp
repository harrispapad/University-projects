#include <iostream>
using namespace std;

struct node {
    int info;
    node *left, *right;
} *root;

int max_num(int x, int y){
    if (x>y)
        return x;
    else
        return y;
}

class bstree {
public:
    bstree();
    int height(node *root);
    void insert (int key);
    int search (int x);
    int min ();
    int max ();
    void inorder ();
    void preorder ();
    void postorder ();
    void print();
};

bstree::bstree(){
    root = nullptr;
}

int bstree::height(node *root){
    if (root == nullptr)
        return 0;
    if (height(root->left)>height(root->right))
        return 1 + max_num(height(root->left), height(root->right));
}

node *insert_aux(node *t, int key) {
    if (t == nullptr) {
        node *p = new node;
        p->info = key;
        p->left = p->right = nullptr;
        return p;
    }
    if (key < t->info)
        t->left = insert_aux(t->left, key);
    else
        t->right = insert_aux(t->right, key);
    return t;
}

void bstree::insert(int key) {
    root = insert_aux(root, key);
}

void inorder_aux(node *t) {
    if (t != nullptr) {
        inorder_aux(t->left);
        cout<<(t->info)<<" ";
        inorder_aux(t->right);
    }
}

void bstree::print(){
    inorder_aux(root);
    cout<<endl;
}


int main(){
    bstree t;
    for (int i=0; i<10; i++){
        t.insert(i);
        t.print();
    }
    cout<<t.height(root);
}
