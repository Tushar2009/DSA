#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
//Summary : Only a game of Idhar sa udhar
// step 1: Queue -> stack (n/2 data )
// step 2: stack -> Queue
// step 3: Queue -> Queue (n/2 data)
// step 4: Queue -> stack (n/2 data)
// step 5: Then push 1 element from stack and 1 from Queue front and push it into the Queue.

void interLeaveQueue(queue<int> &q)
{
    stack<int> st;
    int half=q.size()/2;
    for(int i=0;i<half;i++)
    {
        st.push(q.front());
        q.pop();
    }


    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    for(int i=0;i<half;i++)
    {
        int x=q.front();
        q.pop();
        q.push(x);
    }

    for(int i=0;i<half;i++)
    {
        st.push(q.front());
        q.pop();
    }
    while(st.empty()==false)
    {
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
}
int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    interLeaveQueue(q);
    int length = q.size();
    for (int i = 0; i < length; i++) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
