#include<bits/stdc++.h>
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
int height(Node *root)
{
    if(root==NULL)return 0;
    else
    {
        return 1+max(height(root->left), height(root->right));
    }
}
// Naive solution takes O(n^2) time
// as it calls the height function is O(n) operation
// and traversing the n elments so it is O(n^2) 
bool isBalanced(Node *root)
{
    if(root==NULL)return true;
    int lh=height(root->left);
    int rh=height(root->right);
    return (abs(lh - rh)<=1 && isBalanced(root->left) && isBalanced(root->right));
}





//efficient solution
// takes O(n) time 
int isBalanced2(Node *root)
{
    if(root==NULL)return 0;
    int lh=isBalanced2(root->left);
    if(lh==-1)return -1; // -1 means left subtree is not balanced 
    int rh=isBalanced2(root->right);
    if(rh==-1)return -1;
    if(abs(lh-rh)>1)return -1;
    else
    {
        return max(lh,rh)+1;
    }
}
int main() {
	Node *root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(30);
	root->right->left=new Node(15);
	root->right->right=new Node(20);
	if(isBalanced2(root))
    {
        cout<<"Balanced";
    }
    else
    {
        cout<<"Not Balanced";
    }
}