#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data=x;
        next=prev=NULL;
    }
};
void getpair(Node *head,int x,map<int,int> &m)
{
    Node *last=head;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    Node *first=head;
    while(first!=last && last->next!=first)
    {
        if(first->data+last->data==x)
        {
            m.insert({first->data,last->data});
            first=first->next;
            last=last->prev;
        }
        else
        {
            if(first->data+last->data<x)
            {
                first=first->next;

            }
            else
            {
                last=last->prev;
            }
        }
    }
}
void insert(struct Node** head, int data)
{
    struct Node* temp = new Node(data);
    temp->next = temp->prev = NULL;
    if ((*head) == NULL)
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}
int main()
{
    struct Node* head = NULL;
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
    int x = 7;
    map<int,int> m;
    getpair(head,x,m);
    cout<<"pairs with given sum in doubly linked list:"<<endl;
    for(auto &x:m)
    {
        cout<<"("<<x.second<<","<<x.first<<")"<<endl;
    }
    return 0;
}