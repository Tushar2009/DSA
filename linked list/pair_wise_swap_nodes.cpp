#include<iostream>
#include<bits/stdc++.h>
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
node *pairWiseSwap(node *head)
{
    node *curr=head;
    int temp;
    while(curr!=NULL)
    {
        if(curr->next!=NULL){
        temp=curr->data;
        curr->data=curr->next->data;
        curr->next->data=temp;
        curr=curr->next->next;
        }
        else
        {
           curr=curr->next;
        }
    }
    return head;

}
//method 2
//logic:update the links of head first then other nodes 
node *pairWiseSwap2(node *head)
{
    if(head==NULL || head->next==NULL) return head;
    node *curr=head->next->next;
    node *prev=head;
    head=head->next;
    head->next=prev;
    while(curr!=NULL && curr->next!=NULL)
    {
        prev->next=curr->next;
        // prev=curr;
        node *next=curr->next->next;
        curr->next->next=curr;
        prev=curr;
        curr=next;
    }
    prev->next=curr;
    return head;
}
int main()
{
    node *head=new node(15);
	head->next=new node(10);
	head->next->next=new node(12);
	head->next->next->next=new node(20);
	head->next->next->next->next=new node(30);
	// head->next->next->next->next->next=new node(40);
    printlist(head);
    cout<<endl;
    head=pairWiseSwap2(head);
    printlist(head);
    return 0;
}