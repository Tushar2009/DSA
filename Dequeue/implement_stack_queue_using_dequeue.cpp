#include<bits/stdc++.h>
using namespace std;
struct dequeueNode
{
   int data;
   dequeueNode *next;
   dequeueNode *prev;
   dequeueNode(int x)
   {
      data=x;
      next=prev=NULL;
   }
};
class Deque
{
   private:
   dequeueNode *head;
   dequeueNode *tail;
   public:
   Deque() 
   {
      head=tail=NULL;
   }
   bool isEmpty()
   {
      if(head==NULL)return true;
      return false;
   }
   int size()
   {
      if(!isEmpty())
      {
         dequeueNode *temp=head;
         int len=0;
         while(temp!=NULL)
         {
            len++;
            temp=temp->next;
         }
         return len;
      }
      return 0;
   }
   void insert_first(int x)
   {
      dequeueNode *temp=new dequeueNode(x);
      if(head==NULL)
      {
         head=temp;
         tail=temp;
         temp->next=NULL;
         temp->prev=NULL;
      }
      else
      {
         head->prev=temp;
         temp->next=head;
         temp->prev=NULL;
         head=temp;
      }
   }
   void insert_last(int x)
   {
      dequeueNode *temp=new dequeueNode(x);
      if(head==NULL)
      {
         head=tail=temp;
         temp->prev=temp->next=NULL;
      }
      else
      {
         tail->next=temp;
         temp->prev=tail;
         temp->next=NULL;
         tail=temp;
      }
   }
   void remove_first()
   {
      if(isEmpty())return;
      dequeueNode *temp=head;
      head=head->next;
      if(head)head->prev=NULL;
      delete temp;
      if(head==NULL)tail==NULL;
   }
   void remove_last()
   {
      if(isEmpty())return;
      dequeueNode *temp=tail;
      tail=tail->prev;
      if(tail)tail->next=NULL;
      delete temp;
      if(tail==NULL)head=NULL;
   }
   void display()
    {
        // if list is not empty
        if (!isEmpty()) {
            dequeueNode* temp = head;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
            return;
        }
        cout << "List is Empty" << endl;
    }

};
class Stack : public Deque
{
   public:
   void push(int element)
   {
     insert_last(element);
   }
   void pop()
   {
      remove_last();
   }

};
class Queue:public Deque
{
   public:
   void enqueue(int element)
   {
      insert_last(element);
   }
   void dequeue()
   {
      remove_first();
   }

};
int main()
{
    // object of Stack
    Stack stk;
 
    // push 7 and 8 at top of stack
    stk.push(7);
    stk.push(8);
    cout << "Stack: ";
    stk.display();
 
    // pop an element
    stk.pop();
    cout << "Stack: ";
    stk.display();
 
    // object of Queue
    Queue que;
 
    // insert 12 and 13 in queue
    que.enqueue(12);
    que.enqueue(13);
    cout << "Queue: ";
    que.display();
 
    // delete an element from queue
    que.dequeue();
    cout << "Queue: ";
    que.display();
 
    cout << "Size of Stack is " << stk.size() << endl;
    cout << "Size of Queue is " << que.size() << endl;
    return 0;
}