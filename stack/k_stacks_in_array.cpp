#include<iostream>
using namespace std;
class k_stacks
{
    int *arr,*next,*top,freetop,cap;
    public:
    k_stacks(int size,int k)
    {
        cap = size;
        arr=new int[cap];
        next=new int[cap];
        top=new int[k];
        for(int i=0;i<k;i++)
        {
            top[i]=-1;
        }
        freetop=0;
        for(int i=0;i<cap;i++)
        {
            next[i]=i+1;
        }
        next[cap-1]=-1; // to represent array is full
    }
    void push(int x,int sn) // sn = stack number
    {
        int i=freetop;
        freetop=next[i];
        next[i]=top[sn];
        top[sn]=i; // top array elements store the latest index of top of that particular stack
        arr[i]=x;
    }
    int pop(int sn) // sn = stack number
    {
        int i=top[sn];
        top[sn]=next[i];
        next[i]=freetop;
        freetop=i;
        return arr[i];
    }
};
int main()
{
    k_stacks ks(10,3);
    ks.push(100,0);
    ks.push(200,0);
    ks.push(400,0);

    ks.push(1200,1);
    ks.push(1400,1);
    ks.push(1600,1);

     
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl; 
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl; 
    return 0;
}