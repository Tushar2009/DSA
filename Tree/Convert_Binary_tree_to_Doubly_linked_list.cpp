#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int x)
    {
        key=x;
        right=left=NULL;
    }

};
//Time complexity is O(n)
// Aux space is O(h) (h=height of binary tree)
Node *temp=new Node(-1);
Node *res=temp;
Node  *convert_tree_to_DLL(Node *root)
{
    if(root==NULL)return root;
    if(root!=NULL)
    {
        convert_tree_to_DLL(root->left);
        temp->right=root;
        root->left=temp;
        temp=root;
        convert_tree_to_DLL(root->right);
    }
   return res->right;
}
void print_linked_list(Node *root)
{
    while(root!=NULL)
    {
        cout<<root->key<<" ";
        root=root->right;
    }
}
int main()
{
    Node *root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(20);
    root->right->left=new Node(30);
    root->right->right=new Node(35);
    Node *result=convert_tree_to_DLL(root);
    print_linked_list(result);
    return 0;
}