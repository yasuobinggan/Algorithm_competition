#include<iostream>
using namespace std;
class Array
{
	private:
		int a[3][4];
	public:
		Array(int t[][4],int n)
		{
			int i,j;
			for(i=0;i<3&&i<n;i++)
			{
				for(j=0;j<4;j++)
					a[i][j]=t[i][j];
			}
		}
		void fun()
		{
			int i,j;
			for(i=1;i<3;i++)
			{
				for(j=0;j<4;j++)
					a[i][j]=a[i-1][j]+1;
			}
		}
		void print()
		{
			int i,j;
			for(i=0;i<3;i++)
			{
				for(j=0;j<4;j++)
				{
					cout<<a[i][j]<<"\t";
				}
				cout<<endl;
			}
		}
}; 
int main()
{
	char name[10];
	int age;
	int a[5][4],k=1,i,j;
	cout<<"ÊäÈëÄêÁä,ÐÕÃû:"<<endl;
	cin>>age>>name;
	for(i=0;i<5;i++)
	{
		for(j=0;j<4;j++)
		{
			a[i][j]=k;
			k++;	
		}		
	}
	Array array(a,5);
	array.print();
	array.fun();
	array.print();
	return 0;
}