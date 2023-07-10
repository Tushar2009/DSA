#include<bits/stdc++.h>
using namespace std;


//Time complexity is O(n^3)
//here we are computing every substring 
bool areDistinct(string str, int i, int j) 
{ 

	vector<bool> visited(256); 

	for (int k = i; k <= j; k++) { 
		if (visited[str[k]] == true) 
			return false; 
		visited[str[k]] = true; 
	} 
	return true; 
} 

int longestDistinct1(string str) 
{ 
	int n = str.length(); 
	int res = 0;
	for (int i = 0; i < n; i++) 
		for (int j = i; j < n; j++) 
			if (areDistinct(str, i, j)) 
				res = max(res, j - i + 1); 
	return res; 
}







//Time complexity is O(n^2)
//logic :here we are considering the every substring and wherever the same character in the substring again appears the that substring will destroy
//      and the next greater substring with distinct characters is searched.
// Here we are computing substring from every character of string.
int longestDistinct2(string str) 
{ 
	int n = str.size(); 
	int res = 0;
	for (int i = 0; i < n; i++){
	    vector<bool> visited(256);
	    for(int j=i;j<n;j++){
	        if(visited[str[j]]==true){
	            break;
	        }
	        else{
	            res=max(res,j-i+1);
	            visited[str[j]]=true;
	        }
	    }
	} 
	return res; 
} 






//efficient way 
//Time complexity is O(n)
//logic: here is that if the new character coming is already present in the string then start the starting index from next character of it.
int longestDistinct3(string &str)
{
    int prev[256]={-1};
    int res=0;
    int i=0;
    for(int j=0;j<str.length();j++)
    {
        //updating the starting index for distinct characters substring
        i=max(i,prev[str[j]]+1);
        int max_end=j-i+1;
        res=max(res,max_end);
        prev[str[j]]=j;
    }
    return res;
}
int main() 
{ 
	string str = "geeksforgeeks"; 
	int len = longestDistinct1(str); 
	cout << "The length of the longest distinct characters substring is "<< len; 
	return 0; 
} 