#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;
bool matching(char a,char b)
{
    if(a=='(' && b==')' || a=='[' && b==']' || a=='{' && b=='}')
    {
        return true;
    }
    return false;
}
bool isBalance(string str)
{
    stack<char> st;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(' || str[i]=='[' || str[i]=='{')
        {
            st.push(str[i]);
        }
        else
        {
            if(st.empty())
            {
                return false;
            }
            if(matching(st.top(),str[i]))
            {
                st.pop();
            }
        }
    }
    if(st.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    string str="{}{(}))}"; //{}{(}))}
    if(isBalance(str))
    {
        cout<<"Balanced parenthesis "<<endl;
    }
    else
    {
        cout<<"Unbalanced parenthesis"<<endl;

    }
    return 0;
}
