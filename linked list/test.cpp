// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        int sum1=0;
        int sum2=0;
        while(first!=NULL)
        {
            sum1=sum1+first->data;
            first=first->next;
            
        }
         while(second!=NULL)
        {
            sum2+=second->data;
            second=second->next;
            
        }
        int Total=sum1+sum2;
        stack<int> res;
        while(Total>0)
        {
            int temp=Total%10;
            res.push(temp);
            Total=Total/10;
        }
        Node *temp=NULL;
        while(!res.empty())
        {
            int t=res.top();
            if(temp==NULL)
            {
                temp=new Node(t);
            }
            temp->next=new Node(t);
            temp=temp->next;
            res.pop();
        }
        return temp;
        
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}