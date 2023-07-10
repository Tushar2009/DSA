#include<iostream>
#include<cmath>
using namespace std;
int maxprofit1(int prize[],int start,int end)
{
	if(end<=start)
	{
		return 0;
	}
	int profit=0;
	for(int i=start;i<end;i++)
	{
		for(int j=i+1;j<=end;j++)
		{
			if(prize[j]>prize[i])
			{
				int current_profit=prize[j]-prize[i]+maxprofit1(prize,start,i-1)+maxprofit1(prize,j+1,end);
				profit=max(profit,current_profit);
			}
		}
	}
	return profit;
}
//efficient way and easy to understand
//logic:In this prize is high then sell the stock and if prize is low then buy the stock
int maxprofit2(int prize[],int n)
{
	int profit=0;
	for(int i=1;i<n;i++)
	{
		if(prize[i]>prize[i-1])
		{
			profit+=prize[i]-prize[i-1];
		}
	}
	return profit;
}
int main()
{
	int prize[]={1,5,3,8,12};
	cout<<"The profit is :"<<maxprofit1(prize,0,4);
	return 0;
}
