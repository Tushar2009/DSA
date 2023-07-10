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
//logic is: we maintain 2 list of even and odd,then we join both the lists
node *segregate(node *head)
{
    node *curr=head;
    node *eS=NULL;
    node *eE=NULL;
    node *oS=NULL;
    node *oE=NULL;
    while(curr!=NULL)
    {
        int x=curr->data;
        if(x%2==0)
        {
            if(eS==NULL)
            {
                eS=curr;
                eE=eS;
            }
            else
            {
                eE->next=curr;
                eE=eE->next;
            }
        }
        else
        {
            if(oS==NULL)
            {
                oS=curr;
                oE=oS;
            }
            else
            {
                oE->next=curr;
                oE=oE->next;
            }
        }
        curr=curr->next;
    }
    if(oS==NULL || eS==NULL)
    {
        return head;
    }
    eE->next=oS;
    oE->next=NULL;
    return eS;
}
int main()
{
    node *head=new node(17);
	head->next=new node(15);
	head->next->next=new node(8);
	head->next->next->next=new node(12);
	head->next->next->next->next=new node(10);
	head->next->next->next->next->next=new node(5);
	head->next->next->next->next->next->next=new node(4);
    printlist(head);
    cout<<endl;
    head=segregate(head);
	printlist(head);
    return 0;
}