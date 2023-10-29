#include "factors.h"
#include <math.h>

double _sqrt(double);
unsigned long long int _atoi(char *);
/**
 * main - fins the factor of a number
 * @argc: the number of args passed onto a file
 * @argv: the args passed
 *
 * Return: EXIT_SUCCESS on success, otherwise EXIT_FAILURE
 */

int main(int argc, char **argv)
{
	FILE *file = 0;
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t len = 0;
	unsigned long long int prime_number = 0, mid_range = 0, i, j;
	float result;

	if (argc != 2)
	{
		dprintf(2, "Usage: factors %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
		exit(EXIT_FAILURE);

	while ((len = getline(&lineptr, &n, file)) != -1)
	{
		prime_number = _atoi(lineptr);
		mid_range = (unsigned long long int) _sqrt((double) prime_number);
		result = sqrtf(89.0);
		printf("%f\n", result);

		for (i = 0; i <= mid_range; i++)
		{
			for (j = 0; j <= mid_range; j++)
			{
				if ((i * j) == prime_number)
				{
					printf("%lld=%lld*%lld\n", prime_number, i, j);
					exit(EXIT_SUCCESS);
				}
				else
					continue;
			}
		}
		printf("%llu\n", prime_number);
	}
}


/**
 * _atoi - converts a string to an integer
 * @str: the string
 *
 * Return: int
 */

unsigned long long int _atoi(char *str)
{
	unsigned long long result = 0, i = 0;

	while (str[i] != '\n' && str[i] != '\0')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}

	return (result);
}

/**
 * _sqrt - finds the square root of a number
 * @x: the number
 *
 * Return: double
 */

double _sqrt(double x)
{
	double epsilon = 1e-6;
	double guess = x / 2.0;

	while (fabs(guess * guess - x) > epsilon)
		guess = 0.5 * (guess + x / guess);

	return (guess);
}
