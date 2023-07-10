#include<bits/stdc++.h>
using namespace std;
//logic is start entering elements of stack1 from starting of a array
// and elements of stack2 from ending of array
class two_stacks
{
    int *arr;
    int cap;
    int top1;
    int top2;
    public:
    two_stacks(int n)
    {
        arr=new int[n];
        cap=n;
        top1=-1;
        top2=cap;
    }
    void push1(int data)
    {
        if(top1<top2-1)
        {
            top1++;
            arr[top1]=data;
        }
    }
     void push2(int data)
    {
        if(top1<top2-1)
        {
            top2--;
            arr[top2]=data;
        }
    }
    int pop1()
    {
        int res=-1;
        if(top1>=0)
        {
            res=arr[top1];
            top1--;
        }
        return res;
    }
    int pop2()
    {
        int res=-1;
        if(top2<cap)
        {
            res=arr[top2];
            top2++;
        }
        return res;
    }
};
int main()
{
    two_stacks ts(5); 
    ts.push1(5); 
    ts.push2(10); 
    ts.push2(15); 
    ts.push1(11); 
    ts.push2(7); 
    cout << "Popped element from stack1 is "<<ts.pop1(); 
    ts.push2(40); 
    cout << "\nPopped element from stack2 is "<< ts.pop2();
    return 0;
}