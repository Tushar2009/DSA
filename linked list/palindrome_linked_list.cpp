#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node 
{
    char data;
    node *next;
    node(char x)
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
//method 1 with aux space O(n)
bool ispalindrome(node *head)
{
    stack<char> st;
    node *curr=head;
    while(curr!=NULL)
    {
        st.push(curr->data);
        curr=curr->next;
    }
    curr=head;
    while(curr!=NULL)
    {
        if(curr->data!=st.top())
        {
            return false;
        }
        st.pop();
        curr=curr->next;
    }
    return true;

}
node *reverseList(node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL) return head;
    node *prev=NULL;
    node *curr=head;
    while(curr!=NULL)
    {
        node *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
// method 2
//logic: In this firstly we find the middle of a linked list then reverse the linked list after middle
//then we compare the data from first node of linked with slow->next->data after reversing
//if it is same unitil rev!=NULL then linked is palindrome else not a palindrome
bool ispalindrome2(node *head)
{
    if(head==NULL) return true;
    node *slow=head,*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

    }
    node *rev=reverseList(slow->next);
    node *curr=head;
    while(rev!=NULL)
    {
        if(curr->data!=rev->data)
        {
            return false;
        }
        rev=rev->next;
        curr=curr->next;
    }
    return true;
}
int main()
{
    node *head=NULL;
    head=insertend(head,'g');
    head=insertend(head,'f');
    head=insertend(head,'g');
    printlist(head);
    cout<<endl;
    if(ispalindrome2(head))
    {
        cout<<"palindrome"<<endl;
    }
    else
    {
        cout<<"not a palindrome "<<endl;
    }
}