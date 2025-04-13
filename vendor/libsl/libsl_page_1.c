#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

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

char	*expand_buffer(char **buffer, char **expand)
{
	char	*temp;

	temp = malloc(len(*buffer) + len(*expand) + 1);
	if (temp == NULL)
		return (NULL);
	setstr(&temp, buffer, 0);
	setstr(&temp, expand, len(*buffer));
	temp[len(*buffer) + len(*expand)] = '\0';
	free(*buffer);
	(*buffer) = temp;
	return (*buffer);
}
