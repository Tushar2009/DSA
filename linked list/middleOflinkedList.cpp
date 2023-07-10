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
void midElement(node *head)
{
    if(head==NULL) return;
    node *curr=head;
    int count=0;
    while(curr!=NULL)
    {
        count++;
        curr=curr->next;
    }
    curr=head;
    for(int i=0;i<count/2;i++)
    {
        curr=curr->next;

    }
    cout<<curr->data<<endl;
}
//efficient way
//logic : is that the slow and fast point to head and slow moves 1 step ahead while fast moves 2 steps ahead
//even:when fast becomes null then the data to which slow is pointing is the middle element
//odd: when fast is at last node then the data to which slow is pointing is the middle element
void midElement2(node *head)
{
    if(head==NULL) return;
    node *slow=head;
    node *fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data<<endl;
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
    cout<<"Middle element is :";
    midElement2(head);
    return 0;
}