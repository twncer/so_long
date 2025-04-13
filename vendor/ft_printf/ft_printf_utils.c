/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:31:03 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/13 21:41:32 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <unistd.h>

int	printchar(char c)
{
	return (write(1, &c, 1));
}

int	printstr(char *str)
{
	if (fnot(str))
		return (printstr("(null)"));
	return (write(1, str, len_pr(str)));
}

int	format_is_valid(char c)
{
	int	counter;

	counter = 0;
	while (VALID_FORMATS[counter])
	{
		if (VALID_FORMATS[counter] == c)
			return (1);
		counter++;
	}
	return (0);
}

int	baseator(long long n, int base, bool upper)
{
	int	base_len;
	int	error_check;

	base_len = intlen_base(n, base);
	error_check = 1;
	if (n < 0)
	{
		n = n * -1;
		error_check = printchar('-');
	}
	if (n >= base)
	{
		baseator(n / base, base, upper);
		baseator(n % base, base, upper);
	}
	else if (upper)
		error_check = printchar(uppercase(BASE_TEMPLATE[n]));
	else if (fnot(upper))
		error_check = printchar(BASE_TEMPLATE[n]);
	if (error_check == -1)
		return (-1);
	if (n == 0)
		return (1);
	return (base_len);
}

int	format_pointer(void *p)
{
	int			cup;
	long long	po;

	po = (long long)p;
	cup = 0;
	if (fnot(p))
		return (printstr("(nil)"));
	if (printstr("0x") == -1)
		return (-1);
	if (po == (long long)LONG_MIN)
		cup = printstr("8000000000000000");
	else if (po == (long long)ULONG_MAX)
		cup = printstr("ffffffffffffffff");
	else if (po < 0)
		cup = baseator((-po), 16, false);
	else
		cup = baseator(po, 16, false);
	if (cup == -1)
		return (-1);
	return (cup + 2);
}
