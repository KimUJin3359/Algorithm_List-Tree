#include <stdio.h>
#pragma warning(disable:4996)

int priority[1000001] = { 987654321, };
int size = 1;

void swap(int &a, int &b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}

void enqueue(int data)
{
	int temp = size;

	priority[size++] = data;
	while (temp != 1)
	{
		if (priority[temp] < priority[temp / 2])
			swap(priority[temp], priority[temp / 2]);
		else
			break;
		temp = temp / 2;
	}
}

int dequeue()
{
	int temp;
	int i = 1;

	temp = priority[1];
	size--;
	swap(priority[size], priority[1]);
	priority[size] = 987654321;
	while (i * 2 < size)
	{
		if (priority[(i * 2)] < priority[(i * 2) + 1])
		{
			if (priority[i * 2] < priority[i])
				swap(priority[i], priority[i * 2]);
			else
				break;
			i = i * 2;
		}
		else
		{
			if (priority[(i * 2) + 1] < priority[i])
				swap(priority[i], priority[(i * 2) + 1]);
			else
				break;
			i = (i * 2) + 1;
		}
	}
	return (temp);
}


int main()
{
	int rep;
	int num;

	scanf("%d", &rep);
	for (int i = 0; i < rep; i++)
	{
		scanf("%d", &num);
		enqueue(num);
	}
	while (size != 1)
		printf("%d\n", dequeue());
	return (0);
}