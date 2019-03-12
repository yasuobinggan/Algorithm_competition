#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表     （也就是说提交的时候可以不考虑，不过还是要写的！）    */
void Print( List L ); /* 细节在此不表；空链表将输出NULL   （同上）*/

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Read()
{
    int n;
    scanf("%d",&n);
    List L=(List)malloc(sizeof(PtrToNode));   ///申请一个头结点
    L->Next = NULL;        ///头指针为空
    if(n)    ///当n不是0时
    {
        List r=L;     ///r是一个中间变量的节点
        for(int i=0;i<n;i++) 
        {
            List p=(List)malloc(sizeof(struct Node));
            scanf("%d",&(p->Data));    ///尾插法
            r->Next = p;
            r = p;
        }
        r->Next = NULL;         
    }
    return L;
}

void Print( List L )
{
   List p=L->Next;
   if(p)
   {
       List r;
       r = L;
       while(r->Next)
       {
           r = r->Next;
           printf("%d ",r->Data);
       }
   }
   else
   {
       printf("NULL");
   }
   printf("\n");
}
/*
List Merge( List L1, List L2 )   ///合并函数  重点要写的函数！
{
    List pa,pb,pc,L;
    L = (List)malloc(sizeof(struct Node));
    pa=L1->Next;
    pb=L2->Next;
    pc = L;
    while(pa && pb)
    {
        if(pa->Data <= pb->Data)
        {
            pc->Next = pa;
            pc = pa;
            pa = pa->Next;
        }
        else
        {
            pc->Next = pb;
            pc = pb;
            pb = pb->Next;
        }
    }
    pc->Next = pa ? pa : pb;
    L1->Next = NULL;
    L2->Next = NULL;
    return L;
}
*/
/* 你的代码将被嵌在这里 */
//List Merge(List L1,List L2)
//{
//	List Ls,ps;
//	
//	Ls->Next=NULL;
//	ps=Ls;
//	
//	List p1,p2;
//	p1=L1->Next;p2=L2->Next;
//
//	while(p1&&p2)
//	{
//		List node=(List)malloc(sizeof(List));
//		node->Next=ps->Next;
//		ps->Next=node;
//		
//		if(p1->Data <= p2->Data)
//		{
//			node->Data=p1->Data;
//			p1=p1->Next;		
//		}
//		else
//		{
//			node->Data=p2->Data;
//			p2=p2->Next;
//		}
//		
//		ps=ps->Next;
//	}
//	while(p1)
//	{
//		List node=(List)malloc(sizeof(List));
//		node->Next=ps->Next;
//		ps->Next=node;
//		
//		node->Data=p1->Data;
//		ps=ps->Next;
//	}
//	while(p2)
//	{
//		List node=(List)malloc(sizeof(List));
//		node->Next=ps->Next;
//		ps->Next=node;
//		
//		node->Data=p2->Data;
//		ps=ps->Next;
//	}
//	L1->Next=NULL;
//	L2->Next=NULL;
//	return Ls;
//}
