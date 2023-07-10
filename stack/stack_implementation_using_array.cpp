#include<iostream>
using namespace std;
class mystack
{
    int *arr;
    int top;
    int cap;
    public:
      mystack(int c)
      {
          cap=c;
          arr=new int[cap];
          top=-1;
      }
      void push(int element)
      {
          if(top==cap-1)
          {
              cout<<"stack overflow "<<endl;
          }
         top++;
         arr[top]=element;
      }
      int pop()
      {
          if(top==-1)
          {
              cout<<"stack underflow "<<endl;
          }
         int res=arr[top];
         top--;
         return res;
      }
      int peek()
      {
          if(top==-1)
          {
              cout<<"stack underflow "<<endl;
          }
          return arr[top];
      }
      int size()
      {
          return top+1;
      }
      bool isEmpty()
      {
          if(top==-1)
          {
              return true;
          }
          return false;
      }
};
int main()
{
   mystack s(10);
   s.push(5);
   s.push(10);
   s.push(20);
   cout<<s.pop()<<endl;
   cout<<s.size()<<endl;
   cout<<s.peek()<<endl;
   cout<<s.isEmpty()<<endl;
   return 0;
}