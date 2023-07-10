#include<bits/stdc++.h>
using namespace std;
//efficient way
//Time complexity is O(n*CHAR)
//aux space is O(CHAR)
int fact(int n) 
{ 
    return (n <= 1) ? 1 : n * fact(n - 1); 
} 
const int CHAR=256;
int lexRank(string &str)
{
    int res=1;
    int n=str.length();
    int count[CHAR]={0};
    int mul=fact(n);
    for(int i=0;i<n;i++)
    {
       count[str[i]]++;
    }
    for(int i=1;i<CHAR;i++)
    {
        count[i]+=count[i-1];
    }
    for(int i=0;i<n-1;i++)
    {
        mul=mul/(n-i);
        res=res+count[str[i]-1]*mul;
        for(int j=str[i];j<CHAR;j++)
        {
            count[j]--;
        }

    }
    return res;
}
int main() 
{ 
    string str = "STRING"; 
    cout << lexRank(str); 
    return 0; 
}