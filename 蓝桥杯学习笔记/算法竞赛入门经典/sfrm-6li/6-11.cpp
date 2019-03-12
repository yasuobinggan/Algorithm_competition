/*
	四分树，uva297
		一，递归解决不用标记层数
			用 二维数组+标记 解决问题更清晰 
		二，循环标记层数(标记层数比较复杂)
			需要用栈 
			也可以使用二维数组解决这个问题 
	二维数组相当于标记 
*/ 
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
#define LEN 32
#define maxn 1024+5
int draw1(char str1[],char str2[])//循环解决 
{
	int p1,pe1,p2,pe2;
	p1=p2=0;
	pe1=p1;pe2=p2;
	int cnt=1;
	int area=0;
	while(p1<strlen(str1)&&p2<strlen(str2))
	{
		if(str1[p1]=='p')
		{
			if(str2[p2]=='p')
			{
				
			}
			if(str2[p2]=='f')
			{
				
			}
			if(str2[p2]=='e')
			{
				
			}
		}
		if(str1[p1]='f')
		{
			area+=(LEN/cnt)*(LEN/cnt);
			p1++;p2++;
		}
		if(str1[p1]='e')
		{
			if(str2[p2]=='p')
			{
				
			}
			if(str2[p2]=='f')
			{
				
			}
			if(str2[p2]=='e')
			{
				area+=0;
			}
		}
	}
	return area; 
} 
int main()
{
	int n;
	char str1[maxn],str2[maxn]; 
	cin>>n;//几组数据 
	while(n-- > 0)
	{
		//memset()
		cin>>str1>>str2;
		cout<<draw1(str1,str2)<<endl;
	}
	return 0;
} 
