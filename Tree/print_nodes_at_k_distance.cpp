#include<iostream>
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
//time complexity=O(n)
//aux space complexity=O(h)
void printNodesAtKDistance(Node *root,int k)
{
    if(root==NULL)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->key<<" ";
    }
    else
    {
        printNodesAtKDistance(root->left,k-1);
        printNodesAtKDistance(root->right,k-1);
    }
}
int main()
{
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
    printNodesAtKDistance(root,2);
    return 0;

}