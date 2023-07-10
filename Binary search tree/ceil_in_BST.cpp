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
//Time complexity is O(h)
//Aux space is O(1)
Node *ceil(Node *root,int x)
{
    Node *res=NULL;
    while(root!=NULL)
    {
        if(root->key==x)
        {
            return root;
        }
        else if(root->key<x)
        {
            root=root->right;
        }
        else if(root->key>x)
        {
            res=root;
            root=root->left;
        }
    }
    return res;
}
int main() {
	
	Node *root=new Node(15);
	root->left=new Node(5);
	root->left->left=new Node(3);
	root->right=new Node(20);
	root->right->left=new Node(18);
	root->right->left->left=new Node(16);
	root->right->right=new Node(80);
	int x=17;
	
	cout<<"Ceil: "<<(ceil(root,17)->key);
}