#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//The isdigit() function in C++ checks if the given character is a digit or not.
int evaluatePostfix(char* exp)
{
    stack<int> st;
    int i;
    for (i = 0; exp[i]; ++i)
    {
        if(exp[i] == ' ')continue;
        else if (isdigit(exp[i]))
        {
            int num=0;
            while(isdigit(exp[i]))
            {
            num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            i--;
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
            case '+': st.push(val2 + val1); break;
            case '-': st.push(val2 - val1); break;
            case '*': st.push(val2 * val1); break;
            case '/': st.push(val2/val1); break;
             
            }
        }
    }
    return st.top();
}
int main()
{
    char exp[] = "10 2 * 3+";
    cout << evaluatePostfix(exp);
    return 0;
}