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


//Recursive
bool search1(Node *root,int x)
{
    if(root==NULL) return false;
    if(root->key==x) return true;
    else if(root->key>x)
    {
        return search1(root->left,x);
    }
    else
    {
        return search1(root->right,x);
    }
}


//Iterative
bool search2(Node *root,int x)
{
    while(root!=NULL)
    {
        if(root->key==x) return true;
        if(root->key>x)
        {
            root=root->left;
        }
        else if(root->key<x)
        {
            root=root->right;
        }
    }
    return false;
}
int main() {
	
	Node *root=new Node(15);
	root->left=new Node(5);
	root->left->left=new Node(3);
	root->right=new Node(20);
	root->right->left=new Node(18);
	root->right->left->left=new Node(16);
	root->right->right=new Node(80);
	int x=16;
	
	if(search2(root,x))
	    cout<<"Found";
	else
	    cout<<"Not Found";
}