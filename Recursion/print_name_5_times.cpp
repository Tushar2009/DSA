#include<iostream>
using namespace std;
int count=0;
void func()
{
    if(count==5)return;
    cout<<"Tushar"<<" ";
    count++;
    func();
}
int main()
{
    func();
    return 0;
}