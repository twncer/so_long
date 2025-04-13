/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 04:46:55 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/11 18:08:55 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"
#include "./../vendor/minilibx-linux/mlx.h"
#include "./../vendor/libsl/libsl.h"
#include <stdio.h>
#include "render.h"

void free_image(void *mlx, void *image)
{
    if (image)
    {
        mlx_destroy_image(mlx, image);
        image = NULL;
    }
}

void free_images(struct s_eventpkg *evpkg)
{
    free_image(evpkg->mlx.mlx, evpkg->images.wall);
    free_image(evpkg->mlx.mlx, evpkg->images.ground);
    free_image(evpkg->mlx.mlx, evpkg->images.star[0]);
    free_image(evpkg->mlx.mlx, evpkg->images.star[1]);
    free_image(evpkg->mlx.mlx, evpkg->images.star[2]);
    free_image(evpkg->mlx.mlx, evpkg->images.flowey[0]);
    free_image(evpkg->mlx.mlx, evpkg->images.flowey[1]);
    free_image(evpkg->mlx.mlx, evpkg->images.player[0][0]);
    free_image(evpkg->mlx.mlx, evpkg->images.player[0][1]);
    free_image(evpkg->mlx.mlx, evpkg->images.player[1][0]);
    free_image(evpkg->mlx.mlx, evpkg->images.player[1][1]);
    
    free_image(evpkg->mlx.mlx, evpkg->images.player[2][0]);
    free_image(evpkg->mlx.mlx, evpkg->images.player[2][1]);
    free_image(evpkg->mlx.mlx, evpkg->images.player[3][0]);
    free_image(evpkg->mlx.mlx, evpkg->images.player[3][1]);
    free_image(evpkg->mlx.mlx, evpkg->images.player[4][0]);
    free_image(evpkg->mlx.mlx, evpkg->images.player[4][1]);
    free_image(evpkg->mlx.mlx, evpkg->images.pellets[0]);
    free_image(evpkg->mlx.mlx, evpkg->images.pellets[1]);
    free_image(evpkg->mlx.mlx, evpkg->images.collectible);

    free_image(evpkg->mlx.mlx, evpkg->images.seq_images[0]);
    free_image(evpkg->mlx.mlx, evpkg->images.seq_images[1]);

    free_image(evpkg->mlx.mlx, evpkg->images.numbers[0]);
    free_image(evpkg->mlx.mlx, evpkg->images.numbers[1]); 
    free_image(evpkg->mlx.mlx, evpkg->images.numbers[2]); 
    free_image(evpkg->mlx.mlx, evpkg->images.numbers[3]); 
    free_image(evpkg->mlx.mlx, evpkg->images.numbers[4]);
    free_image(evpkg->mlx.mlx, evpkg->images.numbers[5]);
    free_image(evpkg->mlx.mlx, evpkg->images.numbers[6]); 
    free_image(evpkg->mlx.mlx, evpkg->images.numbers[7]); 
    free_image(evpkg->mlx.mlx, evpkg->images.numbers[8]); 
    free_image(evpkg->mlx.mlx, evpkg->images.numbers[9]);
    free_image(evpkg->mlx.mlx, evpkg->images.numbers[10]);
}
