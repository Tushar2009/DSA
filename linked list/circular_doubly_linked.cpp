#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node (int x)
    {
        data=x;
        next=prev=NULL;
    }
};
void printlist(Node *head)
{
     if(head==NULL)return;
    Node *p=head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
}
Node *insertBegin(Node *head,int x)
{
    Node *temp=new Node(x);
    if(head==NULL)
    {
        temp->next=temp;
        temp->prev=temp;
        return temp;
    }
    temp->next=head;
    temp->prev=head->prev;
    head->prev=temp;
    head->prev->next=temp;
    return temp;
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
    printlist(head);
    head=insertBegin(head,3);
    printlist(head);
    return 0;
}