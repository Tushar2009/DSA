#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }
};
void printlist(Node *head)
{
    if(head==NULL) return;
    cout<<head->data<<" ";
    for(Node *p=head->next;p!=head;p=p->next)
    {
        cout<<p->data<<" ";
    }
}
void printlist2(Node *head)
{
    Node *curr=head;
    if(head==NULL) return;
    do
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    } while (curr!=head);
    
}
//time complexity is O(1)
Node *insertEnd2(Node *head,int data)
{
    Node *temp=new Node(data);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    temp->next=head->next;
    head->next=temp;
    //swap
    int t;
    t=head->data;
    head->data=temp->data;
    temp->data=t;
    return temp;
}
Node *delhead(Node *head)
{
    if(head==NULL) return NULL;
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    Node *curr=head;
    while(curr->next!=head)
    {
        curr=curr->next;
    }
    curr->next=head->next;
    delete head;
    return curr->next;
}
//efficient way
//logic : copy the data of next node to head node then after updating the links delete the next next node
Node *delhead2(Node *head)
{
    if(head==NULL) return NULL;
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    head->data=head->next->data;
    Node *temp=head->next;
    head->next=head->next->next;
    delete temp;
    return head;
}
//Delete the kth node from the linked list
Node *deleteKth(Node *head,int k){
    if(head==NULL)return head;
    if(k==1)return delhead2(head);
        Node *curr=head;
    for(int i=0;i<k-2;i++)
        curr=curr->next;
    Node *temp=curr->next;
    curr->next=curr->next->next;
    delete temp;
    return head;
}
int main()
{
    Node *head=NULL;
    head=insertEnd2(head,10);
    head=insertEnd2(head,20);
    head=insertEnd2(head,30);
    printlist2(head);
    cout<<endl;
    // head=delhead2(head);
    // printlist2(head);

    head=deleteKth(head,1);
    printlist2(head);

}
