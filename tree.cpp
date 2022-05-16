#include <iostream>
using namespace std;


//обычное дерево

struct node {
    int  key ;
    node * left ;
    node * right ;

    node(int key){
        key = key;
        left = nullptr;
        right = nullptr;
    }
};

bool exists(node * root, int val){
    if(root == nullptr)
        return false;
    if (root-> key == val)
        return true;
    if (val < root->key)
        return exists(root->left, val);
    return exists(root->right, val);
}

int depth(node * root){
    if (root == nullptr)
        return 0;
    return max(depth(root -> right), depth(root->left)) + 1;
}

node * insert (node * root, int val){
    if (exists(root, val))
        return root;
    if (root == nullptr)
        return new node(val);
    if (val < root->key)
        root->left = insert(root->left, val);
    if (val > root->key)
        root->right = insert(root->right, val);
    return root;
}


//AVL дерево

struct node_avl {
    int key ;
    int height ;
    node_avl * left ;
    node_avl * right ;

    node_avl(int key){
        key = key;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

bool exists_avl(node_avl * root, int val){
    if(root == nullptr)
        return false;
    if (root-> key == val)
        return true;
    if (val < root->key)
        return exists_avl(root->left, val);
    return exists_avl(root->right, val);
}

int depth_avl(node_avl * root){
    if (root == nullptr)
        return 0;
    return max(depth_avl(root -> right), depth_avl(root->left)) + 1;
}

int height (node_avl * n) {
    if (n == nullptr)
        return 0;
    return n->height;
}

int bfactor(node_avl *n)
{
    if (n == nullptr)
        return 0;
    return height(n->left) - height(n->right);
}

node_avl *rightRotate(node_avl *y)
{
    node_avl *x = y->left;
    node_avl *T = x->right;

    x->right = y;
    y->left = T;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

node_avl *leftRotate(node_avl *x)
{
    node_avl *y = x->right;
    node_avl *T = y->left;

    y->left = x;
    x->right = T;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

node_avl* insert_avl(node_avl* root, int key)
{
    if (exists_avl(root, key))
        return root;
    if (root == nullptr)
        return new node_avl(key);
    if (key < root->key)
        root->left = insert_avl(root->left, key);
    else if (key > root->key)
        root->right = insert_avl(root->right, key);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = bfactor(root);

    // LL
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // RR
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // LR
    if (balance > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL
    if (balance < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


int main(){
    node* root = nullptr;
    for(int i = 1; i<10; i++){
        root = insert(root, i);
    }
    cout << depth(root) << endl;

    return 0;
}