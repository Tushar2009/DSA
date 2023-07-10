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
// How to remember :basically we doing the preorder straversal with 2 stacks
void iterative_postorder(Node *root)
{
    stack<Node *> st1;
    stack<Node *> st2;
    st1.push(root);
    while(st1.empty()==false)
    {
        root=st1.top();
        st1.pop();
        st2.push(root);
        if(root->left!=NULL)
        {
            st1.push(root->left);
        }
        if(root->right!=NULL)
        {
            st1.push(root->right);
        }
    }
    while(!st2.empty())
    {
        cout<<st2.top()->key<<" ";
        st2.pop();
    }

}



//using 1 stack only
// logic: here is that go left left and then right right (if we get in between null then print it then go to its right)
void iterative_postorder2(Node *root,vector<int> &res)
{
  Node *curr=root;
  stack<Node *> st;
  while(curr!=NULL || !st.empty())
  {
        if(curr!=NULL)
        {
            st.push(curr);
            curr=curr->left;
        }
        else
        {
            Node *temp=st.top()->right;
            if(temp==NULL)
            {
               temp=st.top();
               st.pop();
               res.push_back(temp->key);
               while(!st.empty() && temp==st.top()->right)
               {
                temp=st.top();
                st.pop();
                res.push_back(temp->key);
               }
            }
            else
            {
                curr=temp;
            }
        }
  }

}
int main()
{
    Node *root=new Node(10);
	root->left=new Node(20);
    root->right=new Node(30);
    // root->left->left=new Node(40);
    // root->left->right=new Node(50);
    // root->right->left=new Node(60);
    // root->right->right=new Node(70);
    // root->left->left->left=new Node(80);
    // root->left->left->right=new Node(90);
    vector<int> res;
    iterative_postorder(root);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}