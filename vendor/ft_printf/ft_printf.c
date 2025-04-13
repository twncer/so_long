/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:31:05 by btuncer           #+#    #+#             */
/*   Updated: 2024/12/05 20:00:46 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_hub(char format, va_list valist)
{
	if (format == 'c')
		return (printchar(va_arg(valist, int)));
	if (format == 's')
		return (printstr(va_arg(valist, char *)));
	if (format == 'p')
		return (format_pointer(va_arg(valist, void *)));
	if (format == 'd' || format == 'i')
		return (baseator(va_arg(valist, int), 10, false));
	if (format == 'u')
		return (baseator(va_arg(valist, unsigned int), 10, false));
	if (format == 'x')
		return (baseator(va_arg(valist, unsigned int), 16, false));
	if (format == 'X')
		return (baseator(va_arg(valist, unsigned int), 16, true));
	return (-1);
}

int	format_string(const char **str, va_list valist)
{
	char	format;

	format = ((*str) + 1)[0];
	if (format_is_valid(format))
	{
		*str = (*str) + 2;
		return (format_hub(format, valist));
	}
	*str = (*str) + 1;
	printchar('%');
	if (format == '%')
		*str = (*str) + 1;
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	valist;
	int		cup;
	int		cup_history;

	if (fnot(str))
		return (-1);
	cup = 0;
	va_start(valist, str);
	while (*str)
	{
		if (fnot(cup == -1))
			cup_history = cup;
		if (*str == '%')
			cup = cup + format_string(&str, valist);
		else
		{
			cup = cup + printchar(*str);
			cup++;
			str++;
		}
		if (fnot(cup >= cup_history) && fnot(cup == -1) && (fnot(*str == '%')))
			cup = -1;
	}
	va_end(valist);
	return (cup);
}
