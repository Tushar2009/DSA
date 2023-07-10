#include<bits/stdc++.h>
using namespace std;
void patSearchinng(string &txt, string &pat)
{
    int n=txt.size();
    int m=pat.size();
    for(int i=0; i<=n-m; i++)
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
    }
}


 
int main() 
{ 
    string txt = "ABCABCD";string pat="ABCD";
    cout<<"All index numbers where pattern found:"<<" ";
    patSearchinng(txt,pat);
    
    return 0; 
} 