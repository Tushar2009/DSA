#include <bits/stdc++.h> 
using namespace std;
struct Node {
    int data;
    struct Node* next, *prev;
};
int countpairs(Node * first,Node * second,int val)
{
    int res=0;
    while(first!=NULL && second!=NULL && first!=second && second->next!=first)
    {
        if((first->data+second->data)==val)
        {
            res++;
            first=first->next;
            second=second->prev;
        }
        else if((first->data+second->data)>val)
        {
            second=second->prev;
        }
        else
        {
            first=first->next;
        }

    }
    return res;
}

int countTriplets(Node* head, int x)
{
    // WRITE YOUR CODE HERE
    if(head==NULL)return 0;
    int count=0;
    Node *last,*first,*curr;
    last=head;
    curr=head;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    while(curr!=NULL)
    {
        first=curr->next;
        count+=countpairs(first,last,x-curr->data);
        curr=curr->next;
    }
    return count;
}
void insert(struct Node** head, int data)
{
    struct Node* temp = new Node();
    temp->data = data;
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
    int x = 17;
    cout << "Count = "
         << countTriplets(head, x);
    return 0;
}