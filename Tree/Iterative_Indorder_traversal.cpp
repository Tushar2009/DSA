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
void iterative_inorder(Node *root)
{
    stack<Node *> st;
    Node *curr=root;
    while(curr!=NULL || !st.empty())
    {
        while(curr!=NULL)
        {
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        cout<<curr->key<<" ";
        curr=curr->right;
    }
}
int main()
{
    Node *root=new Node(10);
	root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);
    iterative_inorder(root);
    return 0;
}