#include<stdio.h>
/*
void Merage(int a[],int left,int mid,int right)
{
	int i,j;
	int k;
	for(j=mid+1;j<=right;j++)
	{
		for(i=mid;i>=left;i--)
		{
			if(a[j]<=a[i])
			{
				for(k=mid;k>=i;k--)
				{
					a[k+1]=a[k];
				}
				a[i]=a[j];
				
				break;	
			}	
		}	
	}
}
*/
/*
void Merage(int a[], int s, int mid, int e)
{
	int i = 0, j = 0, k;
	int b[9];
	int a_length = 0, b_length = 0;
	for (i = mid + 1; i <= e; i++)
	{
		b[b_length] = a[i];
		b_length++;
	}
	a_length = mid - s + 1;
	while (j <= b_length - 1)//可优化，将第一层if放入第二层循环中
	{
		if (b[j]>a[mid])//？
		{
			a[mid+1] = b[j];
			mid++;
		}
		else
		{
			for (i = s; i <= mid; i++)
			{
				if (b[j] <= a[i])
				{
					for (k = mid; k >= i; k--)
						a[k + 1] = a[k];
					a[i] = b[j];
					mid++;
					break;
				}
			}
		}
		j++;
	}
}
*/
void Merage(int a[],int left,int mid,int right)
{
	int i,j,k;
	if(mid<right)
	{
		j=mid+1;
		for(i=mid;i>=left;i--)
		{
			if(a[j]<=a[i])
			{
				for(k=mid;k>=i;k--)
				{
					a[k+1]=a[k];
				}
				a[i]=a[j];
				break;		
			}	
		}
		Merage(a,left,mid+1,right);
	} 
}
/*
void merageSort(int a[],int length)//开始下标,结束下标//!简化max 
{
	int max=a[0],i;
	int left=0,right=0,mid=0;
	bool flag=false,flag1=false; 
	for(i=left;right<length;i++)//！递归实现 
	{
		if(a[i]>a[i+1])//寻找递增数组 
		{
			if(!flag)
			{
				mid=i;
				printf("m%d\t",mid);
				//max=a[i];
				flag=true;
			}
			else
			{
				right=i;
				printf("r%d\t",right);
				Merage(a,left,mid,right);
				mid=right;
				//max=a[i-1];//!问题所在 
				//left=i;
				//mid=i-1;
				//flag=false;
			}	
		}
		//else
			//max=a[i];
	}
	//mid=(left+right)/2;
	//merageSort(a,left,mid);
	//merageSort(a,mid+1,right);
	//Merage(a,left,mid,right);
}
*/
int main()
{
	/* 
	int a[9]={2,4,5,6,4,5,9,8,7};
	int i;
	merageSort(a,9);
	*/
	int a[6]={2,4,8,1,5,6};
	int i;
	Merage(a,0,2,5);
	printf("\n");
	for(i=0;i<6;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}
