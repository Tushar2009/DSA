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
// Auxilliary space complexity is O(W)
//good for skewed tree 
int Maximum(Node *root)
{
    if(root==NULL)return INT_MIN;
    queue<Node *> q;
    q.push(root);
    int max=INT_MIN;
    while(!q.empty())
    {
        Node *curr=q.front();
        q.pop();
        if(curr->key>max)
        {
            max=curr->key;
        }
        if(curr->left!=NULL)
        {
            q.push(curr->left);
        }
        if(curr->right!=NULL)
        {
            q.push(curr->right);
        }
    }
    return max;
}



//recursive way
// Time complexity is O(n)
// Auxilliary space complexity is O(h)
int getMax(Node *root){
    if(root==NULL)
        return INT_MIN;
    else
        return max(root->key,max(getMax(root->left),getMax(root->right)));
} 
int main()
{
    Node *root=new Node(20);
	root->left=new Node(80);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
    cout<<"maximum of Binary tree is :"<<Maximum(root)<<endl;
    return 0;
}