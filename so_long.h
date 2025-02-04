/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:57:43 by btuncer           #+#    #+#             */
/*   Updated: 2025/02/05 01:27:41 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

struct		Map
{
	bool	is_rect;
	bool	is_walls_valid;
	bool	is_solveable;
	char	**map;
    unsigned int height;
    unsigned int width;
	unsigned int start_pos_x;
	unsigned int start_pos_y;
};
bool		map_is_valid(char *path, struct Map *map);
char		**sl_split(char const *s, char c);