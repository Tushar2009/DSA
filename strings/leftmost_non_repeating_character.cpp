#include<bits/stdc++.h>
using namespace std;
//naive way
//Time complexity is O(n^2)
int NonRep(string &s)
{
    for(int i = 0; i < s.length();i++)
    {
        bool flag=false;
        for(int j=0; j < s.length();j++)
        {
            if(i!=j && s[i]==s[j])
            {
                flag=true;
                break;
            }
        }
        if(flag==false)return i;
    }
    return -1;
}


//better way
//Time complexity is O(n)
//requres the two traversals that's why not efficient
const int Char=256;
int nonRep(string &s)
{
    int count[Char]={0};
    for(int i=0; i < s.length();i++)
    {
         count[s[i]]++;
    }
    for(int i=0; i < s.length();i++)
    {
        if(count[s[i]]==1)
        {
            return i;
        }
    }
    return -1;
}






//efficient way
//Time complexity is O(n+Char)
//aux space is O(char)
int NonRep2(string &s)
{
    int fi[Char];
    fill(fi,fi+Char,-1);
    for(int i=0; i < s.length();i++)
    {
        if(fi[s[i]]==-1)
        {
            fi[s[i]]=i;
        }
        else
        {
            fi[s[i]]=-2;
        }
    }
    int res=INT_MAX;
    for(int i=0; i < Char;i++)
    {
        if(fi[i]>=0)
        {
            res=min(res,fi[i]);
        }
    }
    return (res==INT_MAX)? -1:res;
    

}




int main() 
{ 
    string str = "geeksforgeeks";
    cout<<"Index of leftmost non-repeating element:"<<endl;
    cout<<NonRep2(str)<<endl;  
    
    return 0; 
}