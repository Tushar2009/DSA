#include <bits/stdc++.h> 
using namespace std; 

//naive way
//Time complexity is O(n^2)
int leftMost(string &str) 
{
    for(int i=0;i<str.length();i++){
        for(int j=i+1;j<str.length();j++){
            if(str[i]==str[j])return i;
        }
    }
    return -1;
}


//better approach
//Here 2 traversals are there
// const int CHAR=256;
// int leftMost2(string &str)
// {
//     int count[CHAR]={0};
//     for(int i=0;i<str.length();i++)
//     {
//         count[str[i]]++;
//     }
//     for(int i=0;i<str.length();i++)
//     {
//         if(count[str[i]]>1)
//         {
//             return i;
//         }
//     }
//     return -1;
// }




//efficient way
//Time complexity is O(n+CHAR)
//space complexity is O(CHAR)
const int CHAR=256;
int leftMost3(string &str) 
{
    bool visited[CHAR];
    fill(visited,visited+CHAR,false);
    int res=-1;
    for(int i=str.length()-1;i>=0;i--){
        if(visited[str[i]])
        res=i;
        else
        visited[str[i]]=true;
    }
    
    return res;
}
 
int main() 
{ 
    string str = "geeksforgeeks";
    cout<<"Index of leftmost repeating character:"<<endl;
    cout<<leftMost3(str)<<endl;  
    
    return 0; 
} 