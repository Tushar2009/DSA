#include<bits/stdc++.h>
using namespace std;
//Naive way by reversing the string we are comparing
//Time is O(n)
//space is O(n)
bool check(string &str)
{
    string rev=str;
    reverse(rev.begin(),rev.end());
    return (rev==str);
}


//efficient way
//Time complexity is O(n)
//aux space is O(1)
bool check2(string &str)
{
    int begin=0;
    int end=str.length()-1;
    while(begin<end)
    {
        if(str[begin]!=str[end])
        {
            return false;
        }
        begin++;
        end--;
    }
    return true;
}

int main()
{
    string S = "ABCDCBA";
    cout <<check2(S);
 
    return 0;
}