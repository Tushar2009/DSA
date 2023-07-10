#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left;
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

//Important question 
//Time complexity is O(n)
// Aux space is O(h)
//basically it is a inorder traversal
//logic: previous element in the inorder traversal should not be greater
int prev_min=INT_MIN;
bool isBST(Node *root)
{
    if(root==NULL)return true;
    if(isBST(root->left)==false)return false;
    if(root->key<=prev_min)return false;
    prev_min=root->key;
    return isBST(root->right);
}


int main() {
	
	Node *root = new Node(4);  
    root->left = new Node(2);  
    root->right = new Node(5);  
    root->left->left = new Node(1);  
    root->left->right = new Node(3);  
      
    if(isBST(root))  
        cout<<"Is BST";  
    else
        cout<<"Not a BST";  
          
    return 0;  
	
}