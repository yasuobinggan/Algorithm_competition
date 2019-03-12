#include <stdio.h>
#include <math.h>
int flag[3][4]; //表示哪些可以填数
int mpt[3][4]; //填数
bool visit[10];
int ans = 0;//可选解数量 
void init()   //初始化可选解 
{
	int i,j;
	for(i = 0 ; i < 3 ; i ++)
		for(j = 0 ; j < 4 ; j ++)
			flag[i][j] = 1;//flag[i][j]==1可选 
	flag[0][0] = 0;
	flag[2][3] = 0;
}
void Solve()//判断解是否可选 
{
	int dir[8][2] = { 0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,1,-1,-1};//表示方向 
	int book = true;
	for(int i = 0 ; i < 3 ; i ++)
	{
		for(int j = 0 ; j < 4; j ++)
		{
			//判断每个数周围是否满足
			if(flag[i][j] == 0)continue;
			for( int k = 0 ; k < 8 ; k ++)//判断四周的可选解 
			{
				int x,y;
				x = i + dir[k][0];
				y = j + dir[k][1];
				if(x < 0 || x >= 3 || y < 0 || y >= 4 || flag[x][y] == 0)//越界到不可选空间 
					continue;
				if(abs(mpt[x][y] - mpt[i][j]) == 1)//未越界到不可选空间,查看此位置是否被选过  
					book = false;//如果相邻数位置相邻,book=false,此解不可行 
			}
		}
	}
	if(book) ans ++;
}
void dfs(int index)
{
	int x,y;
	x = index / 4;
	y = index % 4;
	//x,y控制flag的遍历 
	if( x == 3)//表示可选解已满 
	{
		Solve();//判断是否可选,控制计数器自加 
		return;
	}
	if(flag[x][y])//flag可选 
	{
		for(int i = 0 ; i < 10 ; i ++)
		{
			if(!visit[i])//i为填写的数字 
			{
				visit[i] = true;//标注访问 
				mpt[x][y] = i;
				dfs(index+1);
				visit[i] = false;
			}
		}
	}
	else//flag不可选 
	{
		dfs(index+1);
	}
}
//构造全排列,再用约束条件判断是否可行 
int main()
{
	init();
	dfs(0);
	printf("%d\n",ans);
	return 0;
}
