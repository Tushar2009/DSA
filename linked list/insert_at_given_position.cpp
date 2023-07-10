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
//insertion of node at given position
node *insertPos(node *head,int pos,int data)
{
    node *curr=head;
    node *temp=new node(data);
    if(pos==1)
    {
        temp->next=head;
        return temp;
    }
    for(int i=1;i<=pos-2 && curr!=NULL;i++)
    {
       curr=curr->next;
    }
    if(curr==NULL)
    {
        return head;
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
    head=insertend(head,40);
    head=insertend(head,50);
    printlist(head);
    cout<<endl;
    head=insertPos(head,4,35);
    printlist(head);
    return 0;
}