#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node (int x)
    {
        data=x;
        left=right=NULL;
    }
};
// Time complexity is O(nlog(hd)) hd= Total no. of possible horizontal distances.
void vertical_sum(Node *root,int h,map<int,int> &m)
{
    if(root!=NULL)
    {
        vertical_sum(root->left,h-1,m);
        m[h]+=root->data;
        vertical_sum(root->right,h+1,m);
    }
}
int main()
{
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(5);
    root->left->right=new Node(15);
    map<int,int> m;
    vertical_sum(root,0,m);
    for(auto &x:m)
    {
        cout<<x.second<<" ";
    }

    return 0;
}