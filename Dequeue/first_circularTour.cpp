#include<bits/stdc++.h>
#include<deque>
using namespace std;
int firstPetrolPump(int petrol[],int dist[],int n)
{
    for(int start=0;start<n;start++)
    {
       int curr_petrol=0;
       int end=start;
       while(true)
       {
          curr_petrol+=petrol[end]-dist[end];
          if(curr_petrol<0)
          {
            break;
          }
          end=(end+1)%n;
          if(end==start)
          {
            return start+1;
          }

       }

    }
    return -1;
}





//better way with time_complexity=O(n) and auxillary space O(n)
int firstPetrolPump2(int petrol[],int dist[],int n)
{
    deque<int> dq;
    int curr_petrol=0;
    int count=0;
    int start=0;
    int i=0;
    while(count<=n)
    {
        curr_petrol+=petrol[i]-dist[i];
        if(curr_petrol>0)
        {
            dq.push_back(i);
            count++;
        }
        while(!dq.empty() && curr_petrol<=0)
        {
            curr_petrol-=petrol[dq.front()]-dist[dq.front()];
            dq.pop_front();
            count--;
            start=i;
        }
        if(count==n)
        {
            return start+2;
        }
        i=(i+1)%n;
    }
    return -1;
}







//efficient way with time_complexity=O(n) and auxillary space O(1)
int firstPetrolPump3(int petrol[],int dist[],int n)
{
    int start=0;
    int prev_petrol=0;
    int curr_petrol=0;
    for(int i=0;i<n;i++)
    {
        curr_petrol+=petrol[i]-dist[i];
        if(curr_petrol<0)
        {
            start=i+1;
            prev_petrol+=curr_petrol;
            curr_petrol=0;
        }
    }
    if((curr_petrol+prev_petrol)>=0)
    {
        return start+1;
    }
    return -1;
}
int main()
{
    int petrol[]={50,10,60,100};
    int distance[]={30,20,100,10};
    int result=firstPetrolPump2(petrol,distance,4);
    cout<<"we can start from petrol pump no :"<<result<<endl;
    return 0;
}