#include <stdio.h>
#pragma warning (disable : 4996)

bool checked[201];

int calculate(int input[201][3], int i)
{
	if (((char)input[i][0] == '+' || (char)input[i][0] == '-' || (char)input[i][0] == '*' || (char)input[i][0] == '/') && input[i][1] != -1)
	{
		checked[i] = false;
		return (calculate(input, input[i][1]) + calculate(input, input[i][2]));
	}
	else
	{
		checked[i] = false;
		return input[i][0];
	}
}

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
	int rep;
	int input[201][3];

	while (test_c <= 10)
	{
		int num;
		int res = 0;
		int flag = 1;
		char read[12];

		for (int i = 0; i < 201; i++)
		{
			for (int j = 0; j < 3; j++)
				input[i][j] = -1;
			checked[i] = false;
		}
		scanf("%d\n", &rep);
		for (int i = 0; i < rep; i++)
		{
			char c = 0;
			int j = 0, k = 0;

			for (int t = 0; t < 12; t++)
				read[t] = 0;
			while (c != '\n')
			{
				scanf("%c", &c);
				if (c != ' ' && c != '\n')
					read[j++] = c;
				else
				{
					if (k == 0)
					{
						num = ft_atoi(read);
						checked[num] = true;
					}
					else
						input[num][k - 1] = ft_atoi(read);
					for (int t = 0; t < 12; t++)
						read[t] = 0;
					j = 0;
					k++;
				}
			}
		}
		calculate(input, 1);
		for (int i = 0; i < 201; i++)
		{
			if (checked[i] == true)
				flag = 0;
		}
		printf("#%d %d\n", test_c, flag);
		test_c++;
	}
}