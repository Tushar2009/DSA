#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// class  MyStack
// {
//     stack<int> ms; // main stack
//     int Min;
//     public:
//        void push(int x)
//        {
//           if(ms.empty())
//           {
//             ms.push(x);
//             Min=x;
//             return;
//           }
//           else if(x<=Min)
//           {
//             ms.push(x-Min);
//             Min=x;
//             return;
//           }
//           ms.push(x);
//        }
//        void pop()
//        {
//           int x=ms.top();
//           if(x<=0)
//           {
//              Min=Min-x;
//           }
//           ms.pop();
//        }
//        int top() {
//           if(ms.top()<=0)
//           {
//              return Min-ms.top();
//           }
//           return ms.top();
//        }
 
//        int getMin() {
//         return Min;
//       }

// };











class  MyStack
{
    stack<int> ms; // main stack
    int Min;
    public:
       void push(int x)
       {
          if(ms.empty())
          {
            ms.push(x);
            Min=x;
            return;
          }
          else if(x<=Min)
          {
            ms.push(2*x-Min);
            Min=x;
            return;
          }
          ms.push(x);
       }
       void pop()
       {
          int x=ms.top();
          if(x<=Min)
          {
             Min=2*Min-x;
          }
          ms.pop();
       }
       int top() {
         int x=ms.top();
          if(x<=Min)
          {
             return 2*Min-x;
          }
          return ms.top();
       }
 
       int getMin() {
        return Min;
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