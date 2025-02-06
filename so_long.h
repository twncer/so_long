/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:57:43 by btuncer           #+#    #+#             */
/*   Updated: 2025/02/06 01:00:45 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

struct				Map
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
bool				map_is_valid(char *path, struct Map *map);
char				**sl_split(char const *s, char c);
bool				simulate_map(struct Map *map);
char				move_top(struct Map *map);
char				move_right(struct Map *map);
char				move_bottom(struct Map *map);
char				move_left(struct Map *map);
bool rec_walls(int way, unsigned int x, unsigned int y, char **map);