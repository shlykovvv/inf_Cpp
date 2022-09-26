#include <iostream>
using namespace std;
#include <chrono>
#include <bits/stdc++.h>


// ---------------- обычное дерево -----------------//

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

node * insert (node * root, int val){
    /*if (exists(root, val))  // проверка на совпадение
        return root;*/
    if (root == nullptr)
        return new node(val);
    if (val < root->key)
        root->left = insert(root->left, val);
    if (val > root->key)
        root->right = insert(root->right, val);
    return root;
}

//-------------------------AVL дерево -------------------------------//

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
    /*if (exists_avl(root, key))   // проверка на совпадение
        return root;*/
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

    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    if (balance > 1 && key > root->left->key){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->key){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


//--------------------тесты--------------------//
void shuffle_array(int arr[], int n)
{
    unsigned seed = 0;

    shuffle(arr, arr + n, default_random_engine(seed));
}

void show_time(int A[]){
    int MAX = 15000;
    int STEP = 200;
    for(int i = 1 ; i < MAX; i+= STEP){
        int time = 0;
        int time_avl = 0;
        node* root = nullptr;
        node_avl* root_avl = nullptr;

        auto b1 = std::chrono::steady_clock::now();
        for(int j = 1; j<i; j++){
            root = insert(root, A[j]);
        }
        auto e1 = std::chrono::steady_clock::now();
        auto ans1 = std::chrono::duration_cast<std::chrono::milliseconds>(e1 - b1);
        time = ans1.count();

        auto b2 = std::chrono::steady_clock::now();
        for(int j = 1; j<i; j++){
            root_avl = insert_avl(root_avl, A[j]);
        }
        auto e2 = std::chrono::steady_clock::now();
        auto ans2 = std::chrono::duration_cast<std::chrono::milliseconds>(e2 - b2);
        time_avl = ans2.count();

        cout << i <<"  "<< time <<"    " << time_avl << endl ;
    }
}

int main(){
    const int MAX = 15000;

    int A[MAX];
    for(int i = 1; i < MAX; i++){
        A[i] = i;
    }
    cout << endl << "ORDERED:" << endl;
    cout << "N  " << "BASE  " << "AVL " << endl;
    show_time(A);

    shuffle_array(A, MAX);

    cout << endl << "SHUFFLED:" << endl;
    cout << "N  " << "BASE  " << "AVL " << endl;
    show_time(A);


    return 0;
}


//-----------------------запасные функции---------------------------//

/*bool exists(node * root, int val){
    if(root == nullptr)
        return false;
    if (root-> key == val)
        return true;
    if (val < root->key)
        return exists(root->left, val);
    return exists(root->right, val);
}


bool exists_avl(node_avl * root, int val){
    if(root == nullptr)
        return false;
    if (root-> key == val)
        return true;
    if (val < root->key)
        return exists_avl(root->left, val);
    return exists_avl(root->right, val);
}


void check(){ // проверка на адукватность работы

    node* root = nullptr;
    for(int i = 1; i<100; i++){
        root = insert(root, i);
    }
    cout<< "1-100, normal tree, depth: " << depth(root) << endl;

    node_avl* root_avl = nullptr;
    for(int i = 1; i<100; i++){
        root_avl = insert_avl(root_avl, i);
    }
    cout << "1-100, avl tree, depth: "<< depth_avl(root_avl) << endl;
}


int depth_avl(node_avl * root){
    if (root == nullptr)
        return 0;
    return max(depth_avl(root -> right), depth_avl(root->left)) + 1;
}

int depth(node * root){
    if (root == nullptr)
        return 0;
    return max(depth(root -> right), depth(root->left)) + 1;
}

*/