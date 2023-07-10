#include <bits/stdc++.h>
using namespace std;
// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).
int myAtoi(string s)
{
    int flag = 0;
    int i = 0;
    while (i < s.size())
    {
        if (s[i] == ' ')
            i++;
        else
            break;
    }
    if (s[i] == '-')
    {
        i++;
        flag = 1;
    }
    else if (s[i] == '+')
    {
        i++;
    }
    long num = 0;
    for (int j = i; j < s.size(); j++)
    {
        if (s[j] >= '0' && s[j] <= '9')
        {
            num = num * 10 + (s[j] - '0');
            if (num >= INT_MAX)
                break;
        }
        else
        {
            break;
        }
    }
    if (flag)
        num *= -1;
    if (num <= INT_MIN)
        return INT_MIN;
    else if (num >= INT_MAX)
        return INT_MAX;
    return num;
}