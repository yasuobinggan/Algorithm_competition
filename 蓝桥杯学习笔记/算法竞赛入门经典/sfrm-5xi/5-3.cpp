/*
卡片序列
	一.自定义数据结构@
	二.使用vector或set 
*/
#include<iostream>
#include<algorithm>
using namespace std;
#define m_l 1000
typedef struct{
	int c[m_l];
	int top;
	int end;
}Card; 
void initial(Card &card,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		card.c[i]=i+1;
	}
	card.top=0;
	card.end=n; 
}
void pop(Card &card)
{
	cout<<"扔掉的牌:"<<card.c[card.top]<<endl;
	++card.top; 
}
void p_pb(Card &card)
{
	card.c[card.end++]=card.c[card.top++];
	//card.top++;
	//card.end++;
	//card.c[card.end++]=card.c[card.top--];
}
int main()
{
	Card card;
	int n;
	cin>>n;
	initial(card,n);
	while(card.end-card.top>2)
	{
		pop(card);
		p_pb(card);
	}
	return 0;
}
