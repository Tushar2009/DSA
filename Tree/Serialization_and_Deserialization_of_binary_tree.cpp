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
void serialize(Node *root,vector<int> &v)
{
    if(root==NULL)
    {
        v.push_back(-1);
        return;
    }
    v.push_back(root->key);
    serialize(root->left,v);
    serialize(root->right,v);
}






Node *Deserialize(vector<int> &vec,int &index)
{
    if(index==vec.size())return NULL;
    int val=vec[index++];
    if(val==-1)return NULL;
    Node *root=new Node(val);
    root->left=Deserialize(vec,index);
    root->right=Deserialize(vec,index);
    return root;
}


int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);
	
	vector<int> arr;
	serialize(root,arr);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int index=0;
    Node *root_tree=Deserialize(arr,index);
    // vector<int> arr2;
    // serialize(root_tree,arr2);
    // for(int i=0;i<arr2.size();i++)
    // {
    //     cout<<arr2[i]<<" ";
    // }
    return 0;
}