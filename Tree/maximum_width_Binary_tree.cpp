#include<bits/stdc++.h>
#include<queue>
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
// by using level order traversal line by line
//Time complexity is Theta(n)
//Aux space is Theta(W)
int max_width(Node *root)
{
    if(root==NULL)return 0;
    queue<Node *> q;
    q.push(root);
    int max_W=0;
    int count;
    while(q.empty()==false)
    {
        count=q.size();
        max_W=max(max_W,count);
        for(int i=0;i<count;i++)
        {
           Node *curr=q.front();
           q.pop();
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
    return max_W;

}
int main()
{
    Node *root=new Node(8);
    root->left=new Node(30);
    root->right=new Node(20);
    root->left->left=new Node (90);
    root->left->right=new Node (100);
    root->right->left=new Node (70);
    root->right->right=new Node (300);
    cout<<"Maximum Width of Binary tree is :"<<max_width(root)<<endl;

}
