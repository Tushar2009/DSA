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
//logic:Here firstly we point the both slow and fast pointer to head and then we move the slow with one step ahead
// and fast with 2 steps ahead then they will meet for the first time this shows us that linked list has a loop
// then we shift the slow to head then move both fast and slow with 1 step ahead then they meet 2nd time 
// and we make the previous of fast as NULL to remove the loop
int detectRemoveLoop(node* head) 
{ 
    node *slow = head, *fast = head; 
    int len=0;
  
    while (fast!=NULL && fast->next!=NULL) { 
        slow = slow->next; 
        fast = fast->next->next; 
        if (slow == fast) { 
            break; 
        } 
    } 
    do
    {
        len++;
        fast=fast->next;
    } while (fast!=slow);
    return len;
    

}
int main()
{
    node *head=new node(15);
	head->next=new node(10);
	head->next->next=new node(12);
	head->next->next->next=new node(20);
	head->next->next->next->next=head->next;
    //printlist(head);
    //cout<<endl;
    int lenOfLOOP=detectRemoveLoop(head);
    cout<<"length of loop :"<<lenOfLOOP<<endl;
    return 0;
}