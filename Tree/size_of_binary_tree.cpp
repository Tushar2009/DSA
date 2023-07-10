#include<bits/stdc++.h>
#include<queue>
using namespace std;
struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key=k;
        left=right=NULL;
    }
};
// Time complexity is O(n)
// Auxilliary space complexity is O(h)
int getsize(Node *root)
{
    if(root==NULL) return 0;
    else
    {
        return 1+getsize(root->left)+getsize(root->right);
    }
}
int main()
{
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->right->right=new Node(6);
    root->left->left=new Node(8);
    root->left->right=new Node(7);
    root->left->right->left=new Node(9);
    root->left->right->right=new Node(15);
    cout<<"size of Binary tree is :"<<getsize(root)<<endl;
    return 0;
}