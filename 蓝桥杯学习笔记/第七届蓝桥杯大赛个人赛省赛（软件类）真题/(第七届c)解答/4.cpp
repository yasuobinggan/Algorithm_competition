#include <stdio.h>

void swap(int a[], int i, int j)
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

int partition(int a[], int p, int r)
{
    int i = p;//开始位置 
    int j = r + 1;//末尾位置 
    int x = a[p];//标志位 
    while(1){
        while(i<r && a[++i]<x);//i找比标记位大的 
        while(a[--j]>x);//j找比标记位小的 
        if(i>=j) break;
        swap(a,i,j);
    }
	swap(a,p,j);
    return j;//返回标志数字的最后位置 
}

void quicksort(int a[], int p, int r)
{
    if(p<r){
        int q = partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}
    
int main()//先定位主函数 
{
	int i;
	int a[] = {5,13,6,24,2,8,19,27,6,12,1,17};
	int N = 12;
	
	quicksort(a, 0, N-1);
	
	for(i=0; i<N; i++) printf("%d ", a[i]);
	printf("\n");
	
	return 0;
}