/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:48:57 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/13 20:36:03 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

struct s_player	init_player(struct s_map *map)
{
	struct s_player	player;

	player.position.x = (map->start_pos.x) * GROUND_W;
	player.position.y = (map->start_pos.y) * GROUND_W;
	player.moves_px = 0;
	return (player);
}
