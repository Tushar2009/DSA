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
//method1 with time complexity O(n^2)
bool isloop(node *head)
{
    int numberOfNodesPassed = 0;
    node *outerLoopNode = head;
    while (outerLoopNode != NULL)
    {
        numberOfNodesPassed++;
        outerLoopNode = outerLoopNode->next;
        node *innerLoopNode = head;
        int counterForInnerLoop = numberOfNodesPassed;
        while (counterForInnerLoop--)
        {
            if (innerLoopNode == outerLoopNode)
            {
                return true;
            }
            innerLoopNode = innerLoopNode->next;
        }
    }
    return false;
}
// method2
// which destroy the links of linked lists 
// takes O(n) time and O(1) space(auxilliary space)
//logic: here we keep updating the curr->next=temp if curr->next is not equal to temp
// else if curr->next is equal to temp already we return true as that node was already pointing to true

bool isLoop1(node *head)
{
    node *curr=head;
    node *temp=new node(0);
    while(curr!=NULL)
    {
        if(curr->next==NULL)
        {
            return false;
        }
        if(curr->next==temp)
        {
            return true;
        }
        node *next=curr->next;
        curr->next=temp;
        curr=next;
    }
    return false;
}
//method 3
//here auxilliary space of O(n) is used 
bool isLoop2(node *head)
{
    unordered_set<node*> s;
    node *curr=head;
    while(curr!=NULL)
    {
        if(s.find(curr)!=s.end())
        {
            return true;
        }
        s.insert(curr);
    }
    return false;
}
int main()
{
    node *head=new node(15);
	head->next=new node(10);
	head->next->next=new node(12);
	head->next->next->next=new node(20);
	//head->next->next->next->next=head->next;
	if (isloop(head)) 
        cout << "Loop found"; 
    else
        cout << "No Loop"; 
	return 0;
}