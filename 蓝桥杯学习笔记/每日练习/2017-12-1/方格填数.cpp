#include<stdio.h>
typedef struct{
	int x;
	int y;
	int num; 
}visit;
void createmap(int map[3][4])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
			map[i][j]=-1;
	}
	map[0][0]=map[2][3]=-2;
}
int find(visit visited[],int v_length,int x,int y)
{
	int i;
	for(i=0;i<v_length;i++)
	{
		if(x==visited[i].x&&y==visited[i].y)
			return 1;
	}
	return 0;
}
int can(int map[3][4],int x,int y,visit visited[],int v_length,visit c[])
{
	int i;int j;
	int c_length=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			if((i>=x-1&&i<=x+1)&&(j>=y-1&&j<=y+1))
			{
			}
			else if((map[i][j]!=-2)&&!find(visited,v_length,i,j))
			{
				c[c_length].x=i;c[c_length].y=j;
				c_length++; 
			}
		}
	}
	return c_length;
}

void count_num(int map[3][4],int num,int x,int y,visit visited[],int v_length,int &sum)//num为每一轮输入的数字 
{
	visit c[10];
	int c_length,i;
	int t_l;
	int s_num;
	int j;//控制输出可选解 
	if(x==1&&y==1)
	{
		s_num=num;
	 }
	 if(v_length==10)
	 {
	 	for(i=0;i<v_length;i++)
		 	printf("(%d,%d):%d\t",visited[i].x,visited[i].y,visited[i].num);
		 	sum++;
		printf("\n\n"); 
	  } 
	/* 
	if((v_length==10)&&((num+1)%10==s_num))
	{
		sum++;
	}
	*/
	else
	{
		c_length=can(map,x,y,visited,v_length,c);
		num=(num+1)%10;
		for(i=0;i<c_length;i++)
		{
			map[c[i].x][c[i].y]=num;
			visited[v_length].x=c[i].x;
			visited[v_length].y=c[i].y;
			visited[v_length].num=num;
			t_l=v_length+1;
			count_num(map,num,visited[v_length].x,visited[v_length].y,visited,t_l,sum);
		}
	}
	//return sum;
}
int main()
{
	int map[3][4];
	int sum=0,sums=0;//定义时初始化int a[5]={1};其余四位补全,其他情况必须初始化
	int i;
	visit visited[10];int v_length=0;
	createmap(map);
	visited[0].x=1;visited[0].y=1;v_length=1;
	for(i=0;i<10;i++)
	{
		map[1][1]=i;
		visited[0].num=i;
		sum=0;//计数 
		count_num(map,i,1,1,visited,v_length,sum);
		printf("%d\t",sum);
		sums+=sum;
	}
	printf("%d",sums);//输出可选解数量 
}

