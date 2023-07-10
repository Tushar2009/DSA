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
//efficient way (time complexity = O(n))
//logic is we are changing the links by iterating
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
//naive way
node *reverseList2(node *head)
{
    vector<int> arr;
    for(node *curr=head; curr!=NULL;curr=curr->next)
    {
        arr.push_back(curr->data);
    }
    for(node *curr=head; curr!=NULL;curr=curr->next)
    {
        curr->data=arr.back();
        arr.pop_back();
    }
    return head;
}

//recursive method 1 to reverse a linked list
node *reverseRecursive(node *head)
{
   if(head==NULL||head->next==NULL)return head;
    node *rest_head=reverseRecursive(head->next);
    node *rest_tail=head->next;
    rest_tail->next=head;
    head->next=NULL;
    return rest_head;
}
//recursive method 2 to reverse a linked list
// same aproach as iterative method(efficient way)
node *reverseRecursive2(node *curr,node *prev)
{
    if(curr==NULL) return prev;
    // if(curr->next==NULL) return curr;
    node *next=curr->next;
    curr->next=prev;
    return reverseRecursive2(next,curr);
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
    head=reverseRecursive2(head,NULL);
    printlist(head);
    return 0;
}