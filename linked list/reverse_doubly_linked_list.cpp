#include<iostream>
using namespace std;
struct Node 
{
    int data;
    Node *prev;
    Node *next;
    Node(int x)
    {
       data=x;
       prev=NULL;
       next=NULL;
    }
};
void printlist(Node *head)
{
    Node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}
Node *insertEnd(Node *head,int data)
{
    Node *temp=new Node(data);
    if(head==NULL)
    {
        return temp;
    }
    Node *curr=head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=temp;
    temp->prev=curr;
    return head;
}
//reverse of doubly linked list
Node *reverseList(Node *head)
{
    Node *curr=head;
    Node *temp=NULL;
    if(head==NULL || head->next==NULL) return head;
    while(curr!=NULL)
    {
        //swapping of pointers in doubly linked list
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
    }
    return temp->prev; // bascically new head 
}
int main()
{
    Node *head=NULL;
    head=insertEnd(head,10);
    head=insertEnd(head,20);
    head=insertEnd(head,30);
    head=insertEnd(head,40);
    printlist(head);
    cout<<endl;
    head=reverseList(head);
    cout<<"After reverse of doubly linked list :"<<endl;
    printlist(head);
    return 0;
}