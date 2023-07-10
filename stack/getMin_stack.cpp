#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class  MyStack
{
    stack<int> ms; // main stack
    stack<int> as; // auxiliary stack
    public:
       void push(int x)
       {
          if(ms.empty())
          {
            ms.push(x);
            as.push(x);
            return;
          }
          ms.push(x);
          if(ms.top()<=as.top())
          {
            as.push(x);
          }
       }
       void pop()
       {
          if(ms.top()==as.top())
          {
             as.pop();
          }
          ms.pop();
       }
       int top() {
          return ms.top();
       }
 
       int getMin() {
        return as.top();
      }

};
int main()
{
    MyStack s;
    s.push(4);
    s.push(5);
    s.push(8);
    s.push(1);
    s.pop();
 
    cout<<" Minimum Element from Stack: " <<s.getMin();
    return 0;
}