#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *random;
    Node(int x)
    {
        data=x;
        next=random=NULL;
    }
};
void printlist(Node *head)
{
    Node *curr=head;
    while(curr!=NULL)
    {
        cout<<"Data :"<<curr->data<<" , Random :"<<curr->random->data<<endl;
    }
}
//method1
//time complexity O(n) and aux space O(n)
//here unordered map stores the pointers of both next and random of current value
Node *clone(Node *head)
{
    unordered_map<Node *,Node *> hm;
    Node *curr=head;
    while(curr!=NULL)
    {
        hm[curr]=new Node(curr->data);
        curr=curr->next;
    }
    curr=head;
    while(curr!=NULL)
    {
        Node *clone_curr=hm[curr];
        clone_curr->next=hm[curr->next];
        clone_curr->random=hm[curr->random];
    }
    Node *head2=hm[head];
    return head2;
}
//method2
//time complexity O(n) and aux space O(1)
Node* clone2(Node *head) 
{ 
    Node *next,*temp;
    for(Node *curr=head;curr!=NULL;){
        next=curr->next;
        curr->next=new Node(curr->data);
        curr->next->next=next;
        curr=next;
    }
    for(Node *curr=head;curr!=NULL;curr=curr->next->next){
        curr->next->random=(curr->random!=NULL)?(curr->random->next):NULL;
    }
    
     Node* original = head, *copy = head->next; 
  
    temp = copy; 
  
    while (original && copy) 
    { 
        original->next = 
         original->next? original->next->next : original->next; 
  
        copy->next = copy->next?copy->next->next:copy->next; 
        original = original->next; 
        copy = copy->next; 
    } 
  
    return temp;   
}

int main() 
{ 
	Node* head = new Node(10); 
    head->next = new Node(5); 
    head->next->next = new Node(20); 
    head->next->next->next = new Node(15); 
    head->next->next->next->next = new Node(20); 
    
    head->random = head->next->next;
    head->next->random=head->next->next->next;
    head->next->next->random=head;
    head->next->next->next->random=head->next->next;
    head->next->next->next->next->random=head->next->next->next;
    
    cout << "Original list : \n"; 
    //printlist(head); 
  
    cout << "\nCloned list : \n"; 
    Node *cloned_list = clone(head); 
    //printlist(cloned_list); 
  
    return 0; 
}