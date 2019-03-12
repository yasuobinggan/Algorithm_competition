#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int N,A1,A2,A3,A5;
double A4;
int cnt[1000];
int main()
{
	scanf("%d",&N);
	A1=A2=A3=A4=A5=0;
	int i;
	int flag2=0,flag4=0;
	for(i=0;i<N;i++)
	{
		scanf("%d",&cnt[i]);
		if((cnt[i]%5==0)&&(cnt[i]%2==0))
			A1+=cnt[i];
		if(cnt[i]%5==1)
		{
			if(flag2==0)
			{
				A2+=cnt[i];
				flag2=1;
			}
			else
			{
				A2-=cnt[i];
				flag2=0;
				}	
		}
		if(cnt[i]%5==2)
		{
			A3++;
		}
		if(cnt[i]%5==3)
		{
			A4+=cnt[i];
			flag4++;
		}
		if(cnt[i]%5==4&&cnt[i]>A5)
		{
			A5=cnt[i];
		}
	}
	A4/=flag4;
	if(A1)printf("%d ",A1);
	else printf("N ");
	if(A2)printf("%d ",A2);
	else printf("N ");
	if(A3)printf("%d ",A3);
	else printf("N ");
	if(A4>0)printf("%.1f ",A4);
	else printf("N ");
	if(A5)printf("%d",A5);
	else printf("N");
	return 0;
}
