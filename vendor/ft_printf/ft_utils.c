/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:30:49 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/13 21:38:11 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	fnot(bool condition)
{
	return (!condition);
}

int	len_pr(char *str)
{
	int	counter;

	counter = 0;
	while (*str)
	{
		counter++;
		str++;
	}
	return (counter);
}

int	intlen_base(long long n, int base)
{
	int	cup;

	cup = 0;
	if (n < 0)
	{
		n = n * -1;
		cup = cup + 1;
	}
	while (n > base - 1)
	{
		n = n / base;
		cup++;
	}
	if (fnot(n == 0))
		cup++;
	return (cup);
}

char	uppercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
