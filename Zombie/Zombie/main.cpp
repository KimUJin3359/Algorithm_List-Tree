#include <stdio.h>
#pragma warning (disable:4996)

int min = 987654321;
int flag = 0;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void sort(int move[3])
{
	if (move[0] > move[2])
		swap(move[0], move[2]);
	if (move[1] > move[2])
		swap(move[1], move[2]);
	if (move[0] > move[1])
		swap(move[0], move[1]);
}

void dfs(int obj, int move[3], int cnt)
{
	if (flag)
		return;
	if (obj == 0)
	{
		if (min > cnt)
		{
			min = cnt;
			flag = 1;
		}
	}
	else if (obj > 0)
	{
		for (int i = 2; i >= 0; i--)
			dfs(obj - move[i], move, cnt + 1);
	}
}

int main()
{
	int s_dis, o_dis;
	int move[3];
	int want_to_move;

	scanf("%d %d", &s_dis, &o_dis);
	scanf("%d %d %d", &move[0], &move[1], &move[2]);
	want_to_move = o_dis - s_dis;
	sort(move);
	dfs(want_to_move, move, 0);
	printf("%d\n", min);
}