#include <iostream>

using namespace std;

int n;
int a[505][505];

bool isBad(int h,int l) {	//位置越界判断
	return (h<0 || l<0 || h>=n ||l>=n);
}

bool PutMove(int prvs, int h, int l) {	//prvs代表经过什么移动到达第h行、第l列的位置
	if (prvs == -1){	//除第一个数以外，其他数加空格输出
		cout << a[h][l];
		if (!isBad(h,l+1))		//其右没越界
			PutMove(1,h,l+1);	//向右移动
	}
	else
		cout << " " << a[h][l];
	if (h == n-1 && l == n-1)	//递归结束
		return true;
	switch(prvs) {
		case 0:		//↓
			if (!isBad(h-1,l+1))	//其右上没越界
				PutMove(3,h-1,l+1);	//向右上移动
			else
				PutMove(2,h+1,l-1);	//向左下移动
			break;
		case 1:		//→
			if (!isBad(h+1,l-1))	//其左下没越界
				PutMove(2,h+1,l-1);	//向左下移动
			else
				PutMove(3,h-1,l+1);	//向右上移动
			break;
		case 2:		//↙
			if (!isBad(h+1,l-1))	//其左下没越界
				PutMove(2,h+1,l-1);	//向左下移动
			else if (!isBad(h+1,l))	//其下没越界
				PutMove(0,h+1,l);	//向下移动
			else
				PutMove(1,h,l+1);	//向右移动
			break;
		case 3:		//↗
			if (!isBad(h-1,l+1))	//其右上没越界
				PutMove(3,h-1,l+1);	//向右上移动
			else if (!isBad(h,l+1))	//其右没越界
				PutMove(1,h,l+1);	//向右移动
			else
				PutMove(0,h+1,l);	//向下移动
			break;
	}
}

int main() {
	cin >> n;
	int i,j;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			cin >> a[i][j];
	PutMove(-1,0,0);
	return 0;
}
