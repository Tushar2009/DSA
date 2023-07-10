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
//method 1 takes time complexity O(m+n) and space complexity O(n)
int getIntersection(node* head1, node* head2) 
{ 
    unordered_set<node*> s;
    node* curr=head1;
    while(curr!=NULL){
        s.insert(curr);
        curr=curr->next;
    }
    curr=head2;
    while(curr!=NULL){
        if(s.find(curr)!=s.end())
            return curr->data;
        curr=curr->next;
    }
    return -1;
} 




////method 2 which has time complexity O(m+n) and space complexity O(1)
//logic: first check which linked list is large then move the head for positions
// for which it is large from another linked list then traverse both and where both have same pointer return the data of that node  

int getcount(node* head)
{ 
   node *curr=head;
   int c=0;
   while(curr!=NULL){
       c++;
       curr=curr->next;
  }
  return c;
}
int _getIntersection(int d, node* head1, node* head2) 
{ 
    node* current1 = head1; 
    node* current2 = head2; 
  
    for (int i = 0; i < d; i++) { 
        if (current1 == NULL) { 
            return -1; 
        } 
        current1 = current1->next; 
    } 
  
    while (current1 != NULL && current2 != NULL) { 
        if (current1 == current2) 
            return current1->data; 
  
        current1 = current1->next; 
        current2 = current2->next; 
    } 
  
    return -1; 
}

int getIntersection2(node* head1, node* head2) 
{ 
    int c1 = getcount(head1); 
    int c2 = getcount(head2); 
    int d; 
  
    if (c1 > c2) { 
        d = c1 - c2; 
        return _getIntersection(d, head1, head2); 
    } 
    else { 
        d = c2 - c1; 
        return _getIntersection(d, head2, head1); 
    }
}
int main()
{
   	node* newNode; 

	node* head1 = new node(10); 

	node* head2 = new node(3); 

	newNode = new node(6); 
	head2->next = newNode; 

	newNode = new node(9); 
	head2->next->next = newNode; 

	newNode = new node(15); 
	head1->next = newNode; 
	head2->next->next->next = newNode; 

	newNode = new node(30); 
	head1->next->next = newNode; 

	head1->next->next->next = NULL; 

	cout <<"Intersection node of two linked list :"<<getIntersection2(head1, head2)<<endl; 
}