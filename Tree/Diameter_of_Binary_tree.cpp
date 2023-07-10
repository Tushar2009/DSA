#include<iostream>
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
        right=left=NULL;
    }

};
int height1(Node *root)
{
    if(root==NULL)return 0;
    else
    {
        return 1+max(height1(root->left), height1(root->right));
    }
}
// Time complexity is O(n^2)
int getDiameter(Node *root)
{
    if(root==NULL)return 0;
    int d1=1+height1(root->left)+height1(root->right);
    int d2=getDiameter(root->left);
    int d3=getDiameter(root->right);
    return max(d1,max(d2,d3));
}




//method2
//Time complexity is O(n)
//Aux space is O(h)
int res=0;
int height(Node *root){
    if(root==NULL)
        return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    res=max(res,1+lh+rh);
    return 1+max(lh,rh);
}
int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(60);
	root->right->left->left=new Node(50);
	root->right->right->right=new Node(70);
	
	cout<<"Height: "<<height(root)<<endl;
	cout<<"Diameter: "<<res;
}