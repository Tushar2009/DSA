//Time complexity of binary search tree method is O(nh);
#include<bits/stdc++.h>
using namespace std;
struct Node {
	double data;
	Node *left, *right;
	int lCount;
	Node(double x)
	{
		data = x;
		left = right = NULL;
		lCount = 0;
	}
};
Node *insert(Node *root,int x)
{
    if(root==NULL)return new Node(x);
    if(root->data>x)
    {
        root->left=insert(root->left,x);
        root->lCount++;
    }
    else if(root->data<x)
    {
        root->right=insert(root->right,x);
    }
    return root;
}
Node *kthSmallest(Node *root,int k)
{
    if(root==NULL)return NULL;
    int count=root->lCount+1;
    if(count==k)
    {
        return root;
    }
    else if(count>k)
    {
        return kthSmallest(root->left,k);
    }
    else
    {
        return kthSmallest(root->right,k-count);
    }
}
int main()
{
    Node *root=NULL;
    double keys[]={25, 7, 10, 15, 20};
    int size=0;
    for(double x:keys)
    {
        size++;
        root=insert(root,x);
        double res;
        if(size%2!=0)
        {
            res=(kthSmallest(root,(size)/2+1))->data;
        }
        else
        {
            res=(((kthSmallest(root,(size/2)+1))->data)+((kthSmallest(root,(size/2)))->data))/2;
        }
        cout<<res<<" ";
    }
}