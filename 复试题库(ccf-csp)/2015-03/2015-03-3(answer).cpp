#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
bool is_year(int n) //判断闰年
{
	return n%400==0||n%4==0&&n%100!=0;
}
int main()
{
	int a,b,c,y1,y2;
	scanf("%d%d%d%d%d",&a,&b,&c,&y1,&y2);
	int t=2;
	c%=7; //0代表周日
	for(int i=1850;i<=y2;i++)
	{
		if(i>=y1) //进入指定的年份
		for(int j=0;j<12;j++)
		{
			if(j==a-1) //是指定的月份
			{
				int v=(c+7-t)%7+1;
				v+=(b-1)*7; //计算是几号
				if(v>month[j]+(j==1&&is_year(i))?1:0) printf("none\n"); //不存在
				else printf("%04d/%02d/%02d\n",i,j+1,v);
			}
			t+=month[j];
			if(j==1&&is_year(i)) t++;
			t%=7;
		}
		else
		{
			t+=365;
			if(is_year(i))
                t++;
			t%=7;
		}
	}
	return 0;
}
