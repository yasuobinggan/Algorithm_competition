/*
À¹½Øµ¼µ¯ 
*/
/*
#include<stdio.h>
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
     int n;
	 while (~scanf("%d",&n))
	 {
		 int i,j,a[100],b[100],m=0;
		 for (i=1;i<=n;i++)
		 {
	      scanf("%d",&a[i]);
		   b[i]=1;
		 }
		 for (i=1;i<=n;i++)
		 {
	       for (j=0;j<i;j++)
		   {
			   if (a[i]>=a[j])
			   {
			      b[i]=max(b[j]+1,b[i]);
                  m=max(b[i],m);
			   }
		   }
		 }
		printf("%d\n",m);
	 }
	 return 0;
}
*/
#include<iostream>
#include<algorithm>
#define maxl 105
using namespace std;
int main()
{
	int n,a[maxl],opt[maxl];
	int i,j;
	while(cin>>n)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			opt[i]=1;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<i;j++)
			{
				if(opt[j]>opt[i&&opt[j]+1>opt[i]])
				{
					opt[i]=opt[j]+1;
				}
			}
		}
	}
	return 0;
}
