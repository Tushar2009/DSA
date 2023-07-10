#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')' || x=='^')
    {
        return 0;
    }
    return 1;
}
int precedence(char x)
{
    if (x == '*' || x == '/')
    {
        return 3;
    }
    else if (x == '+' || x == '-')
    {
        return 2;
    }
    else if (x == '^')
    {
        return 4;
    }
    else if (x == '(')
    {
        return 1;
    }
    return 0;
}
string infixToPostfix(string Infix)
{
    Infix = '(' + Infix + ')';
    stack<char> st;
    string postfix;
    int len = Infix.size();
    for (int i = 0; i < len; i++)
    {
        if (isOperand(Infix[i]))
        {
            postfix += Infix[i];
        }
        else if (Infix[i] == '(')
        {
            st.push(Infix[i]);
        }
        else if (Infix[i] == ')')
        {
            while (st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            } 
            // removes the '(' left parenthesis too
            st.pop();
        }
        else if (isOperand(Infix[i]) == 0)
        {
            if (st.empty())
            {
                st.push(Infix[i]);
                cout<<st.top()<<endl;
                continue;
            }
            if (precedence(Infix[i]) > precedence(st.top()))
            {
                st.push(Infix[i]);
                continue;
            }
            if (precedence(Infix[i]) <= precedence(st.top()))
            {
                while (precedence(Infix[i]) < precedence(st.top()))
                {
                    postfix += st.top();
                    st.pop();
                }
                if(Infix[i]=='^')
                {
                    postfix +=st.top();
                    st.pop();
                }
                st.push(Infix[i]);
            }
        }
    }
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}
string infixToPrefix(string infix)
{
    int l = infix.size();
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < l; i++) {
 
        if (infix[i] == '(') {
            infix[i] = ')';
            i++;
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
            i++;
        }
    }
    string prefix = infixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}
int main()
{
    string s = ("x+y*z/w+u");
    cout << infixToPrefix(s) << std::endl;
    return 0;
}