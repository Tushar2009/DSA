#include<bits/stdc++.h>
using namespace std;

//Super Naive way
// just copy all the elements of all the k arrays and sort them
vector<int> mergeKArrays(vector<vector<int> > arr) 
{ 
    vector<int> res; 
      
    for(vector<int> v: arr) 
    { 
        for(int x:v) 
            res.push_back(x); 
    } 
      
    
    sort(res.begin(),res.end());

    return res;
}


//efficient way
//Time complexity is O(nk log(nk))
struct Triplet
{
    int val,aPos,vPos;
    Triplet(int v,int ap,int vp)
    {
        val=v;
        aPos=ap;
        vPos=vp;
    }
};
struct mycmp
{
    bool operator()(Triplet &t1,Triplet &t2)
    {
        return t1.val>t2.val;
    }
};
vector<int> mergekSortedarray(vector<vector<int>> &arr)
{
    vector<int> res;
    priority_queue<Triplet,vector<Triplet>,mycmp> pq;
    for(int i=0;i<arr.size();i++)
    {
        Triplet t(arr[i][0],i,0);
        pq.push(t);
    }
    while(pq.empty()==false)
    {
        Triplet curr=pq.top();
        pq.pop();
        res.push_back(curr.val);
        int ap=curr.aPos,vp=curr.vPos;
        if(vp+1<arr[ap].size())
        {
            Triplet t(arr[ap][vp+1],ap,vp+1);
            pq.push(t);
        }
    }
    return res;
}
int main()
{

	vector<vector<int> > arr{ { 10, 20, 30 }, 
                              { 5, 15 }, 
                              { 1, 9, 11, 18 } }; 
  
    vector<int> res=mergekSortedarray(arr);  
    cout << "Merged array is " << endl; 
    for (auto x : res) 
        cout << x << " "; 
  
    return 0; 
}