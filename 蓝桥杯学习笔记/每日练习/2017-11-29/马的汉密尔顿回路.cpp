#include<stdio.h>
#define max 100
int count=0; 
typedef struct{
	int x;
	int y;
}visit;
void createmap(int map[max][max],int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			map[i][j]=0;
	}
}
int find(int x,int y,visit visited[],int v_length)
{
	int i;
	for(i=0;i<v_length;i++)
	{
		if(x==visited[i].x&&y==visited[i].y)
			return 1;
	}
	return 0;//不在被选过的集合内 
}
int can(int x,int y,visit c[],visit visited[],int v_length,int m,int n)//通过约束条件创造候选解集
{
	int c_length=0;
	if(x-2>=0&&x-2<m)
	{
		if(y-1>=0&&!find(x-2,y-1,visited,v_length))
		{
			c[c_length].x=x-2;
			c[c_length].y=y-1; 
			c_length++;
			}
		if(y+1<n&&!find(x-2,y+1,visited,v_length))	
		{
			c[c_length].x=x-2;
			c[c_length].y=y+1;
			c_length++;
		}
	 } 
	if(x-1>=0&&x-1<m)
	{
		if(y-2>=0&&!find(x-1,y-2,visited,v_length))
		{
			c[c_length].x=x-1;
			c[c_length].y=y-2;
			c_length++;
		}
		if(y+2<n&&!find(x-1,y+2,visited,v_length))
		{
			c[c_length].x=x-1;
			c[c_length].y=y+2;
			c_length++;
		}
	}
	if(x+1>=0&&x+1<m)
	{
		if(y-2>=0&&!find(x+1,y-2,visited,v_length))
		{
			c[c_length].x=x+1;
			c[c_length].y=y-2;
			c_length++;
		}
		if(y+2<n&&!find(x+1,y+2,visited,v_length))
		{
			c[c_length].x=x+1;
			c[c_length].y=y+2;
			c_length++;
		}
	}
	if(x+2>=0&&x+2<m)
	{
		if(y-1>=0&&!find(x+2,y-1,visited,v_length))
		{
			c[c_length].x=x+2;
			c[c_length].y=y-1;
			c_length++;
		}
		if(y+1<n&&!find(x+2,y+1,visited,v_length))
		{
			c[c_length].x=x+2;
			c[c_length].y=y+1;
			c_length++;
		}
	}
	return c_length;
 }

void print_visited(visit visited[],int v_length)
{
	int i;int count=0;
	for(i=0;i<v_length;i++)
	{
		printf("(%d,%d)\t",visited[i].x,visited[i].y);
		count++;
		if(count%6==0)
		printf("\n");
	}
	printf("\n\n");
}
void hamilton(int map[max][max],int m,int n,visit visited[],int v_length,int a,int b)//从0,0点开始//借用t_l保持数组的更新 
{
	int i;int t_l;
	visit c[max];int c_length=0;//候选解集//可以缩小数组c的固定长度 
	if(v_length==(m*n)&&((visited[v_length-1].x==1&&visited[v_length-1].y==2)||(visited[v_length-1].x==2&&visited[v_length-1].y==1)))
	{
		print_visited(visited,v_length);
		count++;
		//return;	
	}
	else
	{
		c_length=can(a,b,c,visited,v_length,m,n);//构造候选解 
		for(i=0;i<c_length;i++)
		{
			visited[v_length].x=c[i].x;
			visited[v_length].y=c[i].y;
			t_l=v_length+1;
			hamilton(map,m,n,visited,t_l,visited[v_length].x,visited[v_length].y);//最后两个参数更标准的是vistied[i].x,visited[i].y
			//t_l替换成v_length++ 
		}
	}
}
int main()
{
	int m,n;
	int map[max][max];
	visit visited[max];int v_length;
	scanf("%d%d",&m,&n);//m是行数目 
	createmap(map,m,n);
	visited[0].x=0;visited[0].y=0;v_length=1;
	hamilton(map,m,n,visited,v_length,0,0);
	//printf("%d",count); 
	return 0;
}

