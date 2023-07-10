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
void inorder(Node *root,vector<int> &v)
{
    if(root!=NULL)
    {
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
}
//Time compexity is theta(n)
//aux space is O(n+h)
//2 pointer approach
bool  isPairPresent(Node *root,int x)
{
    vector<int> v2;
    inorder(root,v2);
    int start=0;
    int end=v2.size()-1;
    while(start<=end)
    {
        if(v2[start]+v2[end]==x)
        {
            cout<<"pair found : "<<v2[start]<<" + "<<v2[end]<<" = "<<x<<endl;
            return true;
        }
        else if(v2[start]+v2[end]<x)
        {
            start++;
        }
        else if(v2[start]+v2[end]>x)
        {
            end--;
        }
    }
    return false; 
}
int main() {
	
	Node *root = new Node(10);  
    root->left = new Node(8);  
    root->right = new Node(20);  
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(30);  
    root->right->right->left = new Node(25);
        
    int sum=33;
        
    isPairPresent(root,sum);
          
    return 0;  
	
}