// Example program
#include <iostream>
#include <string>
using namespace std;

struct bst{
    int info;
    bst* left;
    bst* right;
};

bst* getnewnode(int val){
    bst* newnode = new bst;
    newnode->info = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

bst* insert(bst* root, int val){
    if(root == NULL){
        bst* newnode = getnewnode(val);
        return newnode;
    }
    else if(val < root->info)
        root->left = insert(root->left,val);
    
    else
        root->right = insert(root->right,val);
        
    return root;    
}

bool search(bst* root, int val){
    if(root == NULL)
        return false;
    if(root->info == val){
        return true;
    }
    else if(root->info < val){
        search(root->right,val);
    }
    else
        search(root->left,val);
}

int main()
{
  bst* root = NULL;
  root = insert(root,15);
  root = insert(root,10);
  root = insert(root,20);
  root = insert(root,5);
  root = insert(root,12);
  root = insert(root,18);
  root = insert(root,22);
  
  bool check;
  check = search(root,22);
  if(check == true)
    cout<<"found"<<endl;
}
