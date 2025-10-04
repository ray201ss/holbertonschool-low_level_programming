#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string
 *
 * Return: the integer value, or 0 if no numbers
 */
int _atoi(char *s)
{
	int i;
	int sign;
	int result;
	int digit_found;

	i = 0;
	sign = 1;
	result = 0;
	digit_found = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] == '+')
			sign *= 1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			digit_found = 1;
			result = result * 10 - (s[i] - '0');
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
		}
		else if (digit_found)
			break;
		i++;
	}

	return (result * sign);
}
