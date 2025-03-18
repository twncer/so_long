/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 04:46:55 by btuncer           #+#    #+#             */
/*   Updated: 2025/02/27 19:10:46 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"
#include "./../vendor/minilibx-linux/mlx.h"
#include "./../vendor/libsl/libsl.h"
#include <stdio.h>
#include "render.h"

struct s_images init_images(struct s_mlx *mlx)
{
    struct s_images images;
    int q;
    
    images.wall = mlx_xpm_file_to_image(&mlx->mlx, "./textures/wall.xpm", &q, &q);
    images.ground = mlx_xpm_file_to_image(&mlx->mlx, "./textures/platform3.xpm", &q, &q);
    images.star[0] = mlx_xpm_file_to_image(&mlx->mlx, "./textures/star/star1.xpm", &q, &q);
    images.star[1] = mlx_xpm_file_to_image(&mlx->mlx, "./textures/star/star2.xpm", &q, &q);
    images.star[2] = mlx_xpm_file_to_image(&mlx->mlx, "./textures/star/star3.xpm", &q, &q);
    images.flowey[0] = mlx_xpm_file_to_image(&mlx->mlx, "./textures/flowey/flowey1.xpm", &q, &q);
    images.flowey[1] = mlx_xpm_file_to_image(&mlx->mlx, "./textures/flowey/flowey2.xpm", &q, &q);
    images.player[0][0] = mlx_xpm_file_to_image(&mlx->mlx, "./textures/frisk/frisk.xpm", &q, &q);
    images.player[0][1] = mlx_xpm_file_to_image(&mlx->mlx, "./textures/frisk/frisk_top_1.xpm", &q, &q);
    images.player[1][0] = mlx_xpm_file_to_image(&mlx->mlx, "./textures/frisk/frisk_top_2.xpm", &q, &q);
    images.player[1][1] = mlx_xpm_file_to_image(&mlx->mlx, "./textures/frisk/frisk_top_3.xpm", &q, &q);
    images.player[2][0] = mlx_xpm_file_to_image(&mlx->mlx, "./textures/frisk/frisk_right_1.xpm", &q, &q);
    images.player[2][1] = mlx_xpm_file_to_image(&mlx->mlx, "./textures/frisk/frisk_right_2.xpm", &q, &q);
    images.player[3][0] = mlx_xpm_file_to_image(&mlx->mlx, "./textures/frisk/frisk_front_1.xpm", &q, &q);
    images.player[3][1] = mlx_xpm_file_to_image(&mlx->mlx, "./textures/frisk/frisk_front_2.xpm", &q, &q);
    images.player[4][0] = mlx_xpm_file_to_image(&mlx->mlx, "./textures/frisk/frisk_left_1.xpm", &q, &q);
    images.player[4][1] = mlx_xpm_file_to_image(&mlx->mlx, "./textures/frisk/frisk_left_2.xpm", &q, &q);
        
    return (images);
}
