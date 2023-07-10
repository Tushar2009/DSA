#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }
};
void printlist(Node *head)
{
    if(head==NULL) return;
    cout<<head->data<<" ";
    for(Node *p=head->next;p!=head;p=p->next)
    {
        cout<<p->data<<" ";
    }
}
void printlist2(Node *head)
{
    Node *curr=head;
    if(head==NULL) return;
    do
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    } while (curr!=head);
    
}
int main()
{
    Node *head=new Node(10);
    Node *temp1=new Node(5);
    Node *temp2=new Node(20);
    Node *temp3=new Node(15);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=head;
    printlist2(head);
    return 0;
}