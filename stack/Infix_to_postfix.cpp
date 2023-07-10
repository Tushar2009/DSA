#include <iostream>
#include <bits/stdc++.h>
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

char *infixToPostfix(char Infix[])
{
    stack<char> st;
    char *postfix;
    int len = length(Infix);
    postfix = new char[len + 2];
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (isOperand(Infix[i]))
        {
            postfix[j++] = Infix[i];
        }
        else if (Infix[i] == '(')
        {
            st.push(Infix[i]);
        }
        else if (Infix[i] == ')')
        {
            while (st.top() != '(')
            {
                postfix[j++] = st.top();
                st.pop();
            } // removes the '(' left parenthesis too
            if (st.top() == '(')
            {
                st.pop();
            }
        }
        else if (isOperand(Infix[i]) == 0)
        {
            if (st.empty())
            {
                st.push(Infix[i]);
                continue;
            }
            if (precedence(Infix[i]) > precedence(st.top()))
            {
                st.push(Infix[i]);
                continue;
            }
            if (precedence(Infix[i]) < precedence(st.top()))
            {
                while (precedence(Infix[i]) < precedence(st.top()))
                {
                    postfix[j++] = st.top();
                    st.pop();
                }
                if(precedence(Infix[i])==precedence(st.top()))
                {
                    postfix[j++]=st.top();
                    st.pop();
                }
                st.push(Infix[i]);
                continue;
                
            }
            if (precedence(Infix[i]) == precedence(st.top()))
            {
                    postfix[j++] = st.top();
                    st.pop();
                    st.push(Infix[i]);
            }
        }
    }
    while (st.empty() == false)
    {
        postfix[j++] = st.top();
        st.pop();
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char infix[] = "a+b*c/d+e";
    char *postfix = infixToPostfix(infix);
    cout << postfix << endl;
    return 0;
}
