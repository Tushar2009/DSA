#include<bits/stdc++.h>
using namespace std;
//Time complexity is theta(n) because we are using the idea that where the mismatch occurs we shift by that much elements
//it makes the overall time complexity theta(n)
void patSearchinng(string &txt, string &pat)
{
    int n=txt.size();
    int m=pat.size();
    for(int i=0; i<=n-m;)
    {
        int j;
        for(j=0; j<m; j++)
        {
            if(pat[j]!=txt[j+i])
            {
               break;
            }
        }
        if(j==m)
        {
            cout<<i<<" ";
        }
        if(j==0)
        {
            i++;
        }
        else
        {
            i=i+j;
        }
    }
}

int main() 
{ 
    string txt = "ABCABCD";string pat="ABCD";
    cout<<"All index numbers where pattern found:"<<" ";
    patSearchinng(txt,pat);
    
    return 0; 
} 