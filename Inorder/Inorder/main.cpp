#include "tree.h"

int ft_atoi(char *str)
{
	int res = 0;
	int i = 0;

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res *= 10;
			res += str[i] - '0';
		}
		else
			return (str[i]);
		i++;
	}

	return (res);
}

int main()
{
	int test_c = 1;
	int num;
	char arr[101];
	char read[20];
	int res[4];

	while (test_c <= 10)
	{
		Tree tree;

		for (int i = 0; i < 101; i++)
			arr[i] = 0;
		scanf("%d\n", &num);
		for (int i = 0; i < num; i++)
		{
			char c = 0;
			int j = 0;
			int k = 0;

			for (int t = 0; t < 20; t++)
				read[t] = 0;
			for (int t = 0; t < 4; t++)
				res[t] = 0;

			while (c != '\n')
			{
				scanf("%c", &c);
				if (c != ' ' && c != '\n')
					read[j++] = c;
				else
				{
					res[k++] = ft_atoi(read);
					for (int t = 0; t < 20; t++)
						read[t] = 0;
					j = 0;
				}
			}

			if (i == 0)
				tree.insert_root(res[0]);
			tree.set_data(res[0], (char)res[1]);
			if (res[2])
				tree.insert_left(res[0], res[2]);
			if (res[3])
				tree.insert_right(res[0], res[3]);
		}
		printf("#%d ", test_c);
		tree.inorder(tree.root);
		printf("\n");
		tree.free(tree.root);
		test_c++;
	}
}