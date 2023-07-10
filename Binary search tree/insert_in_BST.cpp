#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *right;
    Node *left;
    Node(int x)
    {
        key=x;
        left=right=NULL;
    }
};
//Recursive way
Node * insert1(Node *root,int x)
{
    if(root==NULL)
    {
        return new Node(x);
    }
    else if(x<root->key)
    {
       root->left=insert1(root->left,x);
    }
    else if(root->key<x)
    {
       root->right=insert1(root->right,x);
    }
    return root;
}


//Iterative way
Node * insert2(Node *root,int x)
{
    Node *temp=new Node(x);
    Node *parent=NULL,*curr=root;
    while(curr!=NULL)
    {
        parent=curr;
        if(curr->key<x)
        {
            curr=curr->right;
        }
        else if(curr->key>x)
        {
            curr=curr->left;
        }
        else
        {
            return root;
        }
    }
    if(parent==NULL)
    {
        return temp;
    }
    if(parent->key<x)
    {
        parent->right=temp;
    }
    else
    {
        parent->left=temp;
    }
    return root;
}
void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);    
    }
} 
int main() {
	
	Node *root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(15);
	root->right->left=new Node(12);
	root->right->right=new Node(18);
	int x=20;
	
	root=insert2(root,x);
	inorder(root);
}