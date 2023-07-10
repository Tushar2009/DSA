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
Node *getSuccessor(Node *root)
{
    Node *curr=root->right;
    while(curr!=NULL && curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}
//Time complexity=O(h)
//Aux space =O(h)
Node *DeleteNode(Node *root,int x)
{
    if(root==NULL)return root;
    if(root->key<x)
    {
        root->right=DeleteNode(root->right,x);
    }
    else if(root->key>x)
    {
        root->left=DeleteNode(root->left,x);
    }
    else
    {
        if(root->left==NULL)
        {
            Node *temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL)
        {
            Node *temp=root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *succ=getSuccessor(root); // inorder getSuccessor means closest greater value
            root->key=succ->key;
            root->right=DeleteNode(root->right,succ->key);
        }
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
	int x=15;
	
	root=DeleteNode(root,x);
	inorder(root);
}