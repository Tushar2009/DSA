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

//Time complexity is O(n)
// Aux spac is O(W)
void left_view(Node *root)
{
    if(root==NULL)return;
    queue<Node *> q;
    q.push(root);
    while(q.empty()==false)
    {
        int count=q.size();
        for(int i=0;i<count;i++)
        {
            Node *curr=q.front();
            q.pop();
            // prints only first node of every level
            if(i==0)
            {
              cout<<curr->key<<" ";
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
    }
}


//Recursive way by using preorder traversal method 
//which prints the first node at each level
int max_level=0;
void printlevel(Node *root,int level)
{
    if(root==NULL)return;
    if(max_level<level)
    {
        cout<<root->key<<" ";
        max_level=level;
    }
    printlevel(root->left,level+1);
    printlevel(root->right,level+1);
}
void left_view_2(Node *root)
{
    printlevel(root,1);
}
int main()
{
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
    left_view_2(root);
    return 0;
}