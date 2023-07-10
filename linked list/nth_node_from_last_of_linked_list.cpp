#include<iostream>
using namespace std;
struct node 
{
    int data;
    node *next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};
void printlist(node *head)
{
    node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}
node *insertend(node *head,int x)
{
    node *p=head;
    node *temp=new node(x);
    if(head==NULL)
    {
       return temp;
    }
    //we should have a hold of last node
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=temp;
    return head;
} 
void nthnode(node *head,int n)
{
    node *curr=head;
    int len=0;
    while(curr!=NULL)
    {
        len++;
        curr=curr->next;
    }
    if(len<n)
    {
        return;
    }
    curr=head;
    for(int i=0;i<len-n;i++)
    {
       curr=curr->next;
    }
    cout<<curr->data<<endl;
}
//efficient way
//logic: is initially the first points to node n postion ahead from head and 
// second points to the head then both first and second move until first is NULL
// then second->data is the nth node from last of linked list
void nthnode2(node *head,int n)
{
    if(head==NULL)return;
    node *first=head;
    node *second=head;
    for(int i=0;i<n;i++)
    {
        if(first==NULL) return;// condition for less then n nodes
        first=first->next;
    }
    while(first!=NULL)
    {
        second=second->next;
        first=first->next;
    }
    cout<<second->data<<endl;


}
int main()
{
    node *head=NULL;
    head=insertend(head,10);
    head=insertend(head,20);
    head=insertend(head,30);
    head=insertend(head,40);
    printlist(head);
    cout<<endl;
    cout<<"nth element from last of linked list is :";
    nthnode2(head,2);
    return 0;
}