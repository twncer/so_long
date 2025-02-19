/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 04:46:55 by btuncer           #+#    #+#             */
/*   Updated: 2025/02/19 06:49:33 by btuncer          ###   ########.fr       */
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
    images.star1 = mlx_xpm_file_to_image(&mlx->mlx, "./textures/star/star1.xpm", &q, &q);
    images.star2 = mlx_xpm_file_to_image(&mlx->mlx, "./textures/star/star2.xpm", &q, &q);
    images.star3 = mlx_xpm_file_to_image(&mlx->mlx, "./textures/star/star3.xpm", &q, &q);
    images.flowey1 = mlx_xpm_file_to_image(&mlx->mlx, "./textures/flowey/flowey1.xpm", &q, &q);
    images.flowey2 = mlx_xpm_file_to_image(&mlx->mlx, "./textures/flowey/flowey2.xpm", &q, &q);
    return (images);
}
