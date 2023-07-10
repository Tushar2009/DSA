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
        left=right=NULL;
    }
};
//time complexity is O(n)
//time complexity is O(h)
void iterative_preorder(Node *root)
{
    if(root==NULL) return;
    stack<Node *> st;
    Node *curr=root;
    while(curr!=NULL || !st.empty())
    {
        while(curr!=NULL)
        {
            cout<<curr->key<<" ";
            if(curr->right!=NULL)
            {
              st.push(curr->right);
            }
            curr=curr->left;
        }
        if(!st.empty())
        {
          curr=st.top();
          st.pop();
        }
    }
}
void iterative_preorder2(Node *root)
{
    if(root==NULL)return;
    stack<Node *> s;
    s.push(root);
    while(!s.empty())
    {
        Node *curr=s.top();
        s.pop();
        cout<<curr->key<<" ";
        if(curr->right!=NULL)
        {
            s.push(curr->right);
        }
        if(curr->left!=NULL)
        {
            s.push(curr->left);
        }
    }
}
int main()
{
    Node *root=new Node(10);
	root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->left=new Node(60);
    root->right->right=new Node(70);
    root->left->left->left=new Node(80);
    root->left->left->right=new Node(90);
    iterative_preorder(root);
    return 0;
}