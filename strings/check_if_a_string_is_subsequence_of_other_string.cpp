#include <bits/stdc++.h>
using namespace std;
//iterative way
//Time complexity is O(m+n)
//space complexity is O(1)
bool isSubSeq1(string s1, string s2, int n, int m){
    if(n<m) return false;
    int j = 0;
    
    for(int i = 0; i < n && j < m; i++){
        if(s1[i] == s2[j])
        j++;
    }
    
    return j == m;
}



//Recursive way
//Time complexity is O(m+n)
//space complexity is O(m+n)
bool isSubSeq(string s1, string s2, int n, int m){
    if ( m == 0 )
        return true;
        
    if ( n == 0 )
        return false;
    
    if ( s1[n-1] == s2[m-1] )
        return isSubSeq(s1, s2, n-1, m-1);
    
    else
        return isSubSeq(s1, s2, n-1, m);
}

int main() {
	int n=13,m=5;
	string s1="GEEKSFORGEEKS", s2="GRGES";
	cout<<boolalpha<<isSubSeq1(s1, s2, n, m);	
	return 0;
}