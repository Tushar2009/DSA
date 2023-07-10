//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
  public:
  void inorder(vector<int> &arr,vector<int> &res,int n,int index)
  {
      if(index>=n)return;
      inorder(arr,res,n,2*index +1);
      res.push_back(arr[index]);
      inorder(arr,res,n,2*index +2);
  }
  int minswap(vector<int>&nums)
{
    // Code here
    
    vector<pair<int, int> > v; 
    
    for( int i = 0 ; i < nums.size() ;i++){
        v.push_back(make_pair(nums[i], i)); // storing its index and its value 
    }
    
    sort( v.begin() , v.end() );
    int count = 0 ;
   
    for(int i = 0 ; i < nums.size() ;i++)
    {
       if( nums[i] == v[i].first) continue ;
       else {
           
           count++;
           swap(v[v[i].second] , v[i]);
           i--;
       }
    }
    return count;
}
    int minSwaps(vector<int>&A, int n){
        //Write your code here
        vector<int> res;
        inorder(A,res,n,0);
        int ans=minswap(res);
        return ans;
    }
    
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>A(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> A[i];
	    }
	    Solution ob;
	    int ans = ob.minSwaps(A, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends