#include <bits/stdc++.h>
using namespace std;
int switchRoman(char c)
{
    int x = 0;
    switch (c)
    {
    case 'I':
        x = 1;
        break;
    case 'V':
        x = 5;
        break;
    case 'X':
        x = 10;
        break;
    case 'L':
        x = 50;
        break;
    case 'C':
        x = 100;
        break;
    case 'D':
        x = 500;
        break;
    case 'M':
        x = 1000;
        break;
    }
    return x;
}
int romanToInt(string s)
{
    int n = s.size();
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        if ((s[i] == 'I') && (s[i + 1] == 'V' || s[i + 1] == 'X'))
        {
            num = num + (switchRoman(s[i + 1]) - switchRoman(s[i]));
            i++;
        }
        else if ((s[i] == 'X') && (s[i + 1] == 'L' || s[i + 1] == 'C'))
        {
            num = num + switchRoman(s[i + 1]) - switchRoman(s[i]);
            i++;
        }
        else if ((s[i] == 'C') && (s[i + 1] == 'D' || s[i + 1] == 'M'))
        {
            num = num + switchRoman(s[i + 1]) - switchRoman(s[i]);
            i++;
        }
        else
        {
            num += switchRoman(s[i]);
        }
    }
    return num;
}

// Integer to Roman
string intToRoman(int num)
{
    string Roman = "";
    vector<pair<int, string>> store = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    for (int i = 0; i < store.size(); i++)
    {
        while (num >= store[i].first)
        {
            Roman += store[i].second;
            num -= store[i].first;
        }
    }
    return Roman;
}