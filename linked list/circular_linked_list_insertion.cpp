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
//time complexity is O(n)
Node * insertBegin(Node *head,int data)
{
    Node *temp=new Node(data);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    temp->next=head;
    Node *curr=head;
    while(curr->next!=head)
    {
        curr=curr->next;
    }
    curr->next=temp;
    return temp;
}
//efficient way
// time complexity is O(1)
//logic : Insert the node after head node and swap the data of head and temp
Node * insertBegin2(Node *head,int data)
{
    Node *temp=new Node(data);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else
    {
        temp->next=head->next;
        head->next=temp;
        int t=head->data;
        head->data=temp->data;
        temp->data=t;
        return head;    
    }
}
//time complexity is O(n)
Node *insertEnd(Node *head,int data)
{
    Node *temp=new Node(data);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    Node *curr=head;
    while(curr->next!=head)
    {
        curr=curr->next;
    }
    curr->next=temp;
    temp->next=head;
    return head;
}
//time complexity is O(1)
Node *insertEnd2(Node *head,int data)
{
    Node *temp=new Node(data);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    temp->next=head->next;
    head->next=temp;
    //swap
    int t;
    t=head->data;
    head->data=temp->data;
    temp->data=t;
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
    printlist2(head);
    cout<<endl;
    head=insertBegin2(head,2);
    cout<<"After insertion of node at Begin of circular linked list :"<<endl;
    printlist(head);
    cout<<endl;
    head=insertEnd2(head,30);
    cout<<"After insertion of node at End of circular linked list :"<<endl;
    printlist(head);

    return 0;
}