//matrix:矩阵
//此题使用刷表法:注意选择方法 
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define ml 1005
int R,C;
int matrix[ml][ml],cnt[ml][ml];//martix滑雪矩阵；cnt 
int max_n=-1;
//int tar[ml*ml];
//int max=-1;
void shua(int x,int y)
{
	for(int i=-1;i<=1;i++)
	{
		for(int j=-1;j<=1;j++)
		{
			//if(i!=j)
			if(abs(i-j)==1) 
			{
				if((0<=x+i)&&(x+i<R)&&(0<=y+j)&&(y+j<C))
				{
					if(matrix[x+i][y+j]>matrix[x][y])
					{
						cnt[x+i][y+j]=max(cnt[x+i][y+j],cnt[x][y]+1);
						shua(x+i,y+j);					
					} 
					 
				} 
								
			} 
		}
	}
 } 
void dp()
{
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			shua(i,j);
		}
	}
 } 
int main()
{
		cin>>R>>C;
		//memset(cnt,1,sizeof(cnt));//不能赋1 
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				cnt[i][j]=1;
			}
		}
		
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				cin>>matrix[i][j];
			}
		}
		
		dp();
		
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				max_n=max(max_n,cnt[i][j]);
			}
		 } 
		 cout<<max_n<<endl;
	return 0;
}
/*
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
*/
