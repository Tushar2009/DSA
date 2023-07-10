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
bool detectLoop(node *head)
{
    node *slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
       slow=slow->next;
       fast=fast->next->next;
       if(slow==fast){
           return true;
       }   
    }
    return false;
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
    if(detectLoop(head))
    {
        cout<<"loop found!!"<<endl;
    }
    else
    {
        cout<<"no loop !!"<<endl;
    }
    return 0;
}