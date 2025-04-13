/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:26:03 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/13 21:41:15 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"
#include "./../vendor/minilibx-linux/mlx.h"
#include "./render.h"

void	put_img(struct s_mlx *mlx, void *image, unsigned int x, unsigned int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, image, x - camera_move_x(0), y
		- camera_move_y(0));
}

void	put_img_to_hud(struct s_mlx *mlx, void *image, unsigned int x,
		unsigned int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, image, x, y);
}
