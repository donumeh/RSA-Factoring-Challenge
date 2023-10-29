#include <stdio.h>

int is_prime(int n)
{
	int i = 0;

	if (n <= 1)
		return (0);
	if (n <= 3)
		return (1);
	if (n % 2 == 0 || n % 3 == 3)
		return (0);
	for (i = 5; i * i <= n; i += 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return (0);
	}

	return (1);
}

void factorize(int n)
{
	int i;

	for (i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
		{
			int factor1 = i;
			int factor2 = n / i;

			if (!is_prime(factor1) && !is_prime(factor2))
			{
				printf("%d=%d*%d\n", n, factor1, factor2);
				return;
			}
		}
	}
}

int main(int argc, char **argv)
{
	FILE *file;
	int num;

	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Failed to open the file.\n");
		return (1);
	}

	while (fscanf(file, "%d", &num) == 1)
		factorize(num);

	fclose(file);
	return (0);
}
