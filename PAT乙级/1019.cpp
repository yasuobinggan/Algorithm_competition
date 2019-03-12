#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int num, n[4];
//int a,b,c;
void cut()
{
	int i = 0;
	while (num>0)
	{
		n[i++] = num % 10;
		num /= 10;
	}
	//return i;
}
void out()
{
	for (int i = 0; i<4; i++)
		cout << n[i];
}
int group()
{
	int a = 0;
	for (int j = 0; j<4; j++)
	{
		a += (n[j] * pow(10, j));
	}
	return a;
}
bool compare(int a, int b)//½µÐò 
{
	return a>b;
}
int main()
{

	while (cin >> num)
	{
		int a = 0, b = 0;
		while (num != 6174 && num != 0)
		{
			cut();
			sort(n, n + 4);
			a = group();
			sort(n, n + 4, compare);
			out();
			cout << " " << '-' << " ";

			cut();
			sort(n, n + 4, compare);
			b = group();
			sort(n, n + 4);
			out();
			num = a - b;
			cout << " " << '=' <<" "<< num << endl;
		}
	}
	return 0;
}
