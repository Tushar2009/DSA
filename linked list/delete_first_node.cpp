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
//time complexity is O(1)
node *deletenode(node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    node *temp=head->next;
    delete head;
    return temp;

}
int main()
{
    node *head=NULL;
    head=insertend(head,10);
    head=insertend(head,20);
    head=insertend(head,30);
    printlist(head);
    cout<<endl;

    //deletion of first node from linked list
    cout<<"After deletion of first node :"<<endl;
    head=deletenode(head);
    printlist(head);
    return 0;
}