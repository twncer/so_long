#include <stdbool.h>
#include <unistd.h>

bool	in(char *str, char c)
{
	ssize_t	counter;

	counter = 0;
	while (str[counter])
	{
		if (str[counter] == c)
			return (true);
		counter++;
	}
	return (false);
}

ssize_t	len(char *str)
{
	ssize_t	counter;

	counter = 0;
	while (*str)
	{
		counter = counter + 1;
		str++;
	}
	return (counter);
}

void	setstr(char **a, char **b, ssize_t start)
{
	ssize_t	counter;

	counter = 0;
	while (counter < len(*b))
	{
		(*a)[counter + start] = (*b)[counter];
		counter++;
	}
}