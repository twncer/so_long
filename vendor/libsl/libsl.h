/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 22:02:34 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/13 20:11:18 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSL_H
# define LIBSL_H
# include <stdbool.h>
# include <unistd.h>

bool	in(char *str, char c);
ssize_t	len(char *str);
void	setstr(char **a, char **b, ssize_t start);
char	**sl_split(char const *s, char c);
char	*expand_buffer(char **buffer, char **expand);

#endif