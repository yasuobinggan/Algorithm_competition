#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct node *NODE;
typedef struct node {
	int da;
	NODE l, r;
}node;

NODE T;
int M, N;
int pre[10001];

NODE buildtree(int s, int e) {
	//空树
	if (e < s) return NULL;
	//边界建树
	if (s == e)
    {
		NODE tnode = (NODE)malloc(sizeof(node));
		tnode->da = pre[s];
		tnode->l = NULL;
		tnode->r = NULL;
		return tnode;
	}
	int i = s + 1;
	while (i <= e && pre[i] < pre[s]) i++;
	//
	NODE tnode = (NODE)malloc(sizeof(node));
	tnode->da = pre[s];
	tnode->l = buildtree(s + 1, i - 1);
	tnode->r = buildtree(i, e);
	return tnode;
}

bool findd(NODE tree, int a, int b,int f) {
	if (f == 1)
    {
		if (tree == NULL) return false;
		if (tree->da == a) return true;
		return findd(a < tree->da ? tree->l : tree->r, a, 0, 1);
	}
	else
	{
		if (tree == NULL)
		{
			printf("ERROR: %d and %d are not found.\n", a, b);
			return true;
		}
		if (a < tree->da&&b < tree->da) findd(tree->l, a, b, 0);
		else if (a > tree->da&&b > tree->da)
            findd(tree->r, a, b, 0);
		else
		{
			bool fda = tree->da == a || findd(tree->l, a, 0, 1) || findd(tree->r, a, 0, 1);
			bool fdb = tree->da == b || findd(tree->l, b, 0, 1) || findd(tree->r, b, 0, 1);
			if (fda&&fdb)
			{
				if (tree->da == a || tree->da == b)
					printf("%d is an ancestor of %d.\n", tree->da == a ? a : b, tree->da == b ? a : b);
				else
					printf("LCA of %d and %d is %d.\n", a, b, tree->da);
			}
			else if (fda == false && fdb == false)
			{
				printf("ERROR: %d and %d are not found.\n", a, b);
			}
			else
			{
				printf("ERROR: %d is not found.\n", fda ? b : a);
			}
			return true;
		}
	}
}

int main() {
	scanf("%d %d", &M, &N);
	int a, b;
	for (int i = 0; i < N; i++) {
		scanf("%d", &pre[i]);
	}
	//建树
	T = buildtree(0, N - 1);
	//查找
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		findd(T, a, b, 0);
	}
	return 0;
}
/*
6 8
6 3 1 2 5 4 8 7
2 5
8 7
1 9
12 -3
0 8
99 99
*/
