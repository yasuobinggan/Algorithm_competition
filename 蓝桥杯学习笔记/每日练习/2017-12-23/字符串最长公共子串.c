#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define max 10005
void get_maxlength(int a[],int start,int end,int &maxlength,int &max_s,int &max_e)
{
	int mid,i,j;
	int length1;
	mid=(start+end)/2;
	i=j=mid;
	while(a[++i]==a[mid]&&i<=end);
	while(a[--j]==a[mid]&&j>=start);
	length1=((i-1)-(j+1)+1);
	if(start<end)
	{
		if(length1>maxlength)
		{
			max_s=j+1; 
			max_e=i-1;
			maxlength=length1;	
		}
		if((j-start+1)>length1)
			get_maxlength(a,start,j,maxlength,max_s,max_e);
		if((end-i+1)>length1)
			get_maxlength(a,i,end,maxlength,max_s,max_e);	
	}
	
}
/*
int get_maxlength1(int a[],int start,int end,int maxlength,int &max_s,int &max_e)
{
	int mid,i,j;
	int length1;
	mid=(start+end)/2;
	i=j=mid;
	while(a[++i]==a[mid]&&i<=end);
	while(a[--j]==a[mid]&&j>=start);
	length1=((i-1)-(j+1)+1);
	if(start<end)
	{
		if(length1>maxlength)
		{
			max_s=j+1; 
			max_e=i-1;
			maxlength=length1;	
		}
		if((j-start+1)>length1)
			get_maxlength(a,start,j,maxlength,max_s,max_e);
		if((end-i+1)>length1)
			get_maxlength(a,i,end,maxlength,max_s,max_e);	
	}
	return maxlength;		
}
*/
int main()
{
	int n,a[max],i;
	int mid,start,end;
	int maxlength=0,max_s=0,max_e=0;
	printf("输入字符串长度:\n");
	scanf("%d",&n);
	/*
	printf("输入字符串:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	*/
	srand((int)time(0));
	for(i=0;i<n;i++)
        a[i]=(int)(rand()%10);
	start=0;end=n-1;//mid=(start+end)/2;
	
	get_maxlength(a,start,end,maxlength,max_s,max_e);
	printf("最长子串:\n");
	for(i=max_s;i<=max_e;i++)
		printf("%d ",a[i]);
	printf("最长子串长度:%d\n",maxlength);
	
	//get_maxlength1(a,start,end,maxlength,max_s,max_e);
	return 0;
}