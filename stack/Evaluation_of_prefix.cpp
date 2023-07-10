#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//The isdigit() function in C++ checks if the given character is a digit or not.
int length(char infix[])
{
    int len = 0;
    int i = 0;
    while (infix[i] != '\0')
    {
        len++;
        i++;
    }
    return len;
}
int evaluatePostfix(char* exp)
{
    stack<int> st;
    int len=length(exp);
    int i;
    for (i =len-1 ;i>=0; --i)
    {
        if(exp[i] == ' ')continue;
        else if (isdigit(exp[i]))
        {
            int num=0;
            int j=i;
            while(isdigit(exp[i]))
            {
                i--;
            }
            i++;
            for(int k=i;k<=j;k++)
            {
               num = num * 10 + (int)(exp[k] - '0');
            }
            st.push(num);
        }
        else
        {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            switch (exp[i])
            {
            case '+': st.push(val1 + val2); break;
            case '-': st.push(val1 - val2); break;
            case '*': st.push(val1 * val2); break;
            case '/': st.push(val1/val2); break;
             
            }
        }
    }
    return st.top();
}
int main()
{
    char exp[] = "+ * 10 2 3";
    cout << evaluatePostfix(exp);
    return 0;
}