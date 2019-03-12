#include<stdio.h>
int place(int &h,int &v,int a[3][4])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		if((i!=0||j!=0)&&(i!=2||j!=3))
		{
			if(((i>h+1&&i<=2)||(i<h-1&&i>=0)||(j>v+1&&j<=3)||(j<v-1&&j>=0))&&(a[i][j]==-1))
			{
				h=i;v=j;
				return 1;
			}
				 
		}	
	}
	return 0;
}

int count(int i,int j,int num,int a[3][4])
{
	int c=0;
	if(num==9)
		c++;
	a[i][j]=num;
	if(place(i,j,a))
		count(i,j,num++,a);
	return c;	
 }

int main()
{
	int a[3][4];
	int i,j;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
			a[i][j]=-1;
	}
	
	
	int num=0;
	int w=0;
	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
			w+=count(i,j,0,a);
	printf("%d\t",w);//Êä³ö½á¹û 
	return 0;
}

/* 
int main()
{
	int a[3][4];
	int i,j;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
			a[i][j]=-1;
	}
	i=j=1;
	printf("%d%d%d",i,j,place(i,j,a));
	return 0;
}
*/ 
