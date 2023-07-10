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
//logic: as floor means the smaller or equal value so the result cannot be find in right side of tree
//so if the right side is NULL completly discard it
//else if not NULL and our floor value is present in right subtree then
// make the result as the root and then move towards right because
// in this case the root is the smaller value then our number whose(floor we want)
Node *floor(Node *root,int x)
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
            res=root;
            root=root->right;
        }
        else if(root->key>x)
        {
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
	
	cout<<"Floor: "<<(floor(root,17)->key);
}