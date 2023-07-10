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
//takes time complexity O(m+n) aux space O(1)
node *sortedMerge(node *a,node *b)
{
    if(a==NULL)return b;
    if(b==NULL)return a;
    node *head=NULL,*tail=NULL;
    if(a->data<=b->data){
        head=tail=a;
        a=a->next;
    }
    else{
        head=tail=b;
        b=b->next;
    }
    while(a!=NULL&&b!=NULL){
        if(a->data<=b->data){
            tail->next=a;
            tail=a;
            a=a->next;
        }
        else{
            tail->next=b;
            tail=b;
            b=b->next;
        }
    }
    if(a==NULL){tail->next=b;}
    else{
        tail->next=a;
    }
    return head;

}
int main()
{
    
	node *a=new node(10);
	a->next=new node(20);
	a->next->next=new node(30);
	node *b=new node(5);
	b->next=new node(35);  
    printlist(sortedMerge(a,b));
}