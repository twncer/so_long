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

void free_images(struct s_eventpkg *evpkg)
{
    mlx_destroy_image(evpkg->mlx.mlx, evpkg->images.wall);
    mlx_destroy_image(evpkg->mlx.mlx, evpkg->images.ground);
    mlx_destroy_image(evpkg->mlx.mlx, evpkg->images.star[0]);
    mlx_destroy_image(evpkg->mlx.mlx, evpkg->images.star[1]);
    mlx_destroy_image(evpkg->mlx.mlx, evpkg->images.flowey[0]);
    mlx_destroy_image(evpkg->mlx.mlx, evpkg->images.flowey[1]);
    mlx_destroy_image(evpkg->mlx.mlx, evpkg->images.player[0][0]);
    mlx_destroy_image(evpkg->mlx.mlx, evpkg->images.player[0][1]);
    mlx_destroy_image(evpkg->mlx.mlx, evpkg->images.player[1][0]);
    mlx_destroy_image(evpkg->mlx.mlx, evpkg->images.player[1][1]);
    mlx_destroy_image(evpkg->mlx.mlx, evpkg->images.player[2][0]);
    mlx_destroy_image(evpkg->mlx.mlx, evpkg->images.player[2][1]);
    mlx_destroy_image(evpkg->mlx.mlx, evpkg->images.player[3][0]);
    mlx_destroy_image(evpkg->mlx.mlx, evpkg->images.player[3][1]);
    mlx_destroy_image(evpkg->mlx.mlx, evpkg->images.player[4][0]);
    mlx_destroy_image(evpkg->mlx.mlx, evpkg->images.player[4][1]);
    mlx_destroy_image(evpkg->mlx.mlx, evpkg->images.pellets[0]);
    mlx_destroy_image(evpkg->mlx.mlx, evpkg->images.pellets[1]);
    mlx_destroy_image(evpkg->mlx.mlx, evpkg->images.collectible);
    mlx_destroy_image(evpkg->mlx.mlx, evpkg->images.seq_images[0]);
}