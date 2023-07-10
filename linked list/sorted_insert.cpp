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
node *insertSorted(node *head,int x)
{
    node *temp=new node(x);
    if(head==NULL)
    {
        return temp;
    }
    node *curr=head;
    if(x<curr->data)
    {
        temp->next=head;
        return temp;
    }
    while(curr->next!=NULL && curr->next->data<x )
    {
        curr=curr->next;
    }
    temp->next=curr->next;
    curr->next=temp;
    return head;
}
int main()
{
    node *head=NULL;
    head=insertend(head,10);
    head=insertend(head,20);
    head=insertend(head,30);
    printlist(head);
    cout<<endl;
    head=insertSorted(head,35);
    printlist(head);
    return 0;
}