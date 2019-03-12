#include<stdio.h>
void sort(int a[],int length)
{
	int i,j;
	int temp;
	for(i=0;i<length-1;i++)
	{
		for(j=i;j<length-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void f(int M,int i,int j)
{
	
 } 
void mode(int a[],int &M,int &max,int left,int right)//left最左端坐标,right最右端坐标 
{
	int M1,max1;//众数,重数 
	int i,j;//分别向左右寻找中位数 
	M1=a[(right+left)/2];
	
	i=j=(right+left)/2;
	while(a[--i]==M1&&i>=left);
	while(a[++j]==M1&&j<=right); 
	//！问题所在while (i--&&a[i] == M);
	//！问题所在while (j++&&a[j] == M);
	max1=((j-1)-(i+1)+1);
	printf("标记重数%d", max1);
	if(left<right)
	{
		if(max1>max)
		{
			M=M1;
			max=max1;
		}
		if((i-left+1)>((j-1)-(i+1)+1))
		{
			mode(a,M,max,left,i);
		}
		if((right-j+1)>((j-1)-(i+1)+1))
		{
			mode(a,M,max,j,right);
		}
		//
	}
	//return M;	 
}
int main()
{
	int a[10]={1,2,3,4,5,6,7,7,8,8};
	sort(a,10);
	int M=0,max=0;//M众数,max重数
	
	mode(a,M,max,0,9);
	printf("众数:%d",M);
	printf(",重数:%d",max); 
	 
	/*
	printf("\nint众数:%d",mode(a,M,max,0,9));
	printf("\nint重数:%d",max);
	*/
	return 0;
}
