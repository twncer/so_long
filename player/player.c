/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:48:57 by btuncer           #+#    #+#             */
/*   Updated: 2025/02/18 02:33:02 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"
#include "./../vendor/minilibx-linux/mlx.h"

struct s_player init_player(struct s_map *map, void *mlx)
{
    struct s_player player;
    int q;
    
    player.position.x = (map->start_pos.x) * GROUND_W; // iki ayak ortası
    player.position.y = (map->start_pos.y) * GROUND_W; // ayak hizası
    player.image = mlx_xpm_file_to_image(mlx, "./textures/frisk/walk_right/frame1.xpm", &q, &q);
    player.moves_px = 0;

    return (player);
}