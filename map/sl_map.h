/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:41:23 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/13 21:24:22 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_MAP_H
# define SL_MAP_H
# define BUFFER_SIZE 100

bool	check_is_rect(struct s_map *map);
bool	check_is_walls_valid(struct s_map *map);
int		flood(char **map, int x, int y);
bool	map_is_valid(char *path, struct s_map *map, bool bonus);

#endif