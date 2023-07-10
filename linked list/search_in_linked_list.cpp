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
// search the position of an element in an linked list
//time complexity is O(n)
int search(node *head,int x)
{
    int pos=1;
    node *curr=head;
    while(curr!=NULL)
    {
        if(curr->data==x)
        {
            return pos;
        }
        pos++;
        curr=curr->next;
    }
    if(curr==NULL)
    {
        return -1;
    }
}
//recursive search in a linked list
//time complexity is O(n)
int rsearch(node *head,int x)
{
    if(head==NULL)
    {
        return -1;
    }
    if(head->data==x)
    {
        return 1;
    }
    else
    {
        int res=rsearch(head->next,x);
        if(res==-1)return -1;
        else return (res+1);
    }
}
int main()
{
    node *head=NULL;
    head=insertend(head,10);
    head=insertend(head,5);
    head=insertend(head,20);
    head=insertend(head,15);
    printlist(head);
    cout<<endl;
    cout<<"element is present at position :"<<rsearch(head,20);
    
    return 0;
}