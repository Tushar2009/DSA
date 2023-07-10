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
int height(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return 1+max(height(root->left),height(root->right));
    }
}
void print_at_distance_k(Node *root,int k)
{
    if(root==NULL)return;
    if(k==0)
    {
        cout<<root->key<<" ";
    }
    else
    {
        print_at_distance_k(root->left,k-1);
        print_at_distance_k(root->right,k-1);
    }
}
//Time complexity is O(h*n)
void level_order_traversal_1(Node *root)
{
    int h=height(root);
    for(int k=0;k<h;k++)
    {
        print_at_distance_k(root,k);
    }
}






//time complexity theta(n) using queue
//Aux space is theta(W) where W is width of binary
void level_order_traversal_2(Node *root)
{
    if(root==NULL)return;
    queue<Node *> q;
    q.push(root);
    while(!q.empty())
    {
        Node *curr=q.front();
        q.pop();
        cout<<curr->key<<" ";
        if(curr->left!=NULL)
        {
            q.push(curr->left);
        }
        if(curr->right!=NULL)
        {
            q.push(curr->right);
        }
    }
}








//line by line (level traversal)
//time complexity O(n+h) using queue (h here is because NULL is added for no. of height times) 
//Aux space is theta(W) where W is width of binary
void level_order_traversal_3(Node *root)
{
    if(root==NULL)return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1)
    {
        Node *curr=q.front();
        q.pop();
        if(curr==NULL)
        {
            cout<<endl;
            q.push(NULL);
            continue;
        }
        cout<<curr->key<<" ";
        if(curr->left!=NULL)
        {
            q.push(curr->left);
        }
        if(curr->right!=NULL)
        {
            q.push(curr->right);
        }
    }
}






//line by line (level traversal)
//time complexity O(n) using queue
//Aux space is theta(W) where W is width of binary
void level_order_traversal_4(Node *root)
{
    if(root==NULL)return;
    queue<Node *> q;
    q.push(root);
    while(!q.empty())
    {
        int count=q.size();
        for(int i=0;i<count;i++)
        {
           Node *curr=q.front();
           q.pop();
           cout<<curr->key<<" ";
           if(curr->left!=NULL)
           {
               q.push(curr->left);
           }
           if(curr->right!=NULL)
           {
               q.push(curr->right);
           }
        }
        cout<<endl;
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
    level_order_traversal_4(root);
    return 0;
}