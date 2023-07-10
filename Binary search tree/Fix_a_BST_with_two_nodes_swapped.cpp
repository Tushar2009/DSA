#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node (int x)
    {
        data=x;
        left=right=NULL;
    }
};
void inorder(Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
Node *prevv=NULL,*first=NULL,*second=NULL;
void fixBST(Node *root)
{
    if(root==NULL)return;
    fixBST(root->left);
    if(prevv!=NULL && root->data<prevv->data)
    {
        if(first==NULL)first=prevv;
        second=root;
    }
    prevv=root;
    fixBST(root->right);
}
int main() {
	
	Node *root = new Node(18);  
    root->left = new Node(60);  
    root->right = new Node(70);  
    root->left->left = new Node(4);  
    root->right->left = new Node(8);
    root->right->right = new Node(80);  
    
    inorder(root); 
    cout<<endl;
    fixBST(root);
    int temp=first->data;
    first->data=second->data;
    second->data=temp;
    inorder(root);
          
    return 0;  
	
}