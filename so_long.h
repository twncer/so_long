/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:57:43 by btuncer           #+#    #+#             */
/*   Updated: 2025/02/11 19:29:03 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

struct				s_map
{
	bool			is_rect;
	bool			is_walls_valid;
	bool			is_solveable;
	char			**map;
	unsigned int	height;
	unsigned int	width;
	unsigned int	start_pos_x;
	unsigned int	start_pos_y;
	unsigned int	current_pos_x;
	unsigned int	current_pos_y;
};

char				move_top(struct s_map *map);
char				move_right(struct s_map *map);
char				move_bottom(struct s_map *map);
char				move_left(struct s_map *map);
bool				rec_walls(int way, unsigned int x, unsigned int y,
						char **map);