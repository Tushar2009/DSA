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
node *reverseList1(node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL) return head;
    node *prev=NULL;
    node *curr=head;
    node *next;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;

}
node *reverseINgroupOFsizeK(node *head,int k)
{
    node *curr=head;
    int count=0;
    node *prev=NULL;
    node *next=NULL;
    while(curr!=NULL && count<k)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL)
    {
        node *rest_head=reverseINgroupOFsizeK(next,k);
        head->next=rest_head;
    }
    return prev;
}
//efficient way
//takes time complexity O(n) and auxilliary space O(1)
//logic: If first pass then set the head as prev after reversing the list
// then also set prev_first as the first element before reversing the list and after reversing the list
// join the prev_first to the prev of other group in this way solution is obtained
node *reverseINgroupOFsizeK2(node *head,int k)
{
    bool firstpass=true;
    node *curr=head,*prevfirst=NULL;
    while(curr!=NULL)
    {
        node *first=curr,*prev=NULL;
        int count=0;
        while(curr!=NULL && count<k)
        {
            node *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(firstpass)
        {
            head=prev;
            firstpass=false;
        }
        else
        {
            prevfirst->next=prev;
        }
        prevfirst=first;
    }
    return head;
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
    head=reverseINgroupOFsizeK2(head,2);
    printlist(head);
    return 0;
}