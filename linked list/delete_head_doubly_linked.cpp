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
//time complexity is O(1)
Node *deletehead(Node *head)
{
    Node *curr=head;
    if(head==NULL) return NULL;
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    curr=curr->next;
    curr->prev=NULL;
    delete head;
    return curr;
}
Node *delLast(Node *head){
    if(head==NULL)return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    }    
    Node *curr=head;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->prev->next=NULL;
    delete curr;
    return head;
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
    head=delLast(head);
    cout<<"After deletion of first node in doubly linked list :"<<endl;
    printlist(head);
    return 0;
}