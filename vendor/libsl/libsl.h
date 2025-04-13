/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 22:02:34 by btuncer           #+#    #+#             */
/*   Updated: 2025/02/11 16:21:58 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

bool	in(char *str, char c);
ssize_t	len(char *str);
void	setstr(char **a, char **b, ssize_t start);
char	**sl_split(char const *s, char c);
char	*expand_buffer(char **buffer, char **expand);