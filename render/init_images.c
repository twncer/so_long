/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 04:46:55 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/13 21:41:15 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"
#include "./../vendor/minilibx-linux/mlx.h"

void	init_seq_images(struct s_mlx *mlx, struct s_images *images)
{
	int	q;

	images->seq_images[0] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/seq/uded.xpm", &q, &q);
	images->seq_images[1] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/seq/uwon.xpm", &q, &q);
}

void	init_number_images(struct s_mlx *mlx, struct s_images *images)
{
	int	q;

	images->numbers[0] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/numbers/zero.xpm", &q, &q);
	images->numbers[1] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/numbers/one.xpm", &q, &q);
	images->numbers[2] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/numbers/two.xpm", &q, &q);
	images->numbers[3] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/numbers/three.xpm", &q, &q);
	images->numbers[4] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/numbers/four.xpm", &q, &q);
	images->numbers[5] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/numbers/five.xpm", &q, &q);
	images->numbers[6] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/numbers/six.xpm", &q, &q);
	images->numbers[7] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/numbers/seven.xpm", &q, &q);
	images->numbers[8] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/numbers/eight.xpm", &q, &q);
	images->numbers[9] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/numbers/nine.xpm", &q, &q);
	images->numbers[10] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/numbers/px.xpm", &q, &q);
}

void	init_player_images(struct s_mlx *mlx, struct s_images *images)
{
	int	q;

	images->player[0][0] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/frisk/frisk.xpm", &q, &q);
	images->player[0][1] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/frisk/frisk_top_1.xpm", &q, &q);
	images->player[1][0] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/frisk/frisk_top_2.xpm", &q, &q);
	images->player[1][1] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/frisk/frisk_top_3.xpm", &q, &q);
	images->player[2][0] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/frisk/frisk_right_1.xpm", &q, &q);
	images->player[2][1] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/frisk/frisk_right_2.xpm", &q, &q);
	images->player[3][0] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/frisk/frisk_front_1.xpm", &q, &q);
	images->player[3][1] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/frisk/frisk_front_2.xpm", &q, &q);
	images->player[4][0] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/frisk/frisk_left_1.xpm", &q, &q);
	images->player[4][1] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/frisk/frisk_left_2.xpm", &q, &q);
}

void	init_flowey_images(struct s_mlx *mlx, struct s_images *images)
{
	int	q;

	images->flowey[0] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/flowey/flowey1.xpm", &q, &q);
	images->flowey[1] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/flowey/flowey2.xpm", &q, &q);
	images->pellets[0] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/flowey/pellet_1.xpm", &q, &q);
	images->pellets[1] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/flowey/pellet_2.xpm", &q, &q);
}

struct s_images	init_images(struct s_mlx *mlx)
{
	struct s_images	images;
	int				q;

	images.wall = mlx_xpm_file_to_image(&mlx->mlx, "./textures/wall.xpm", &q,
			&q);
	images.ground = mlx_xpm_file_to_image(&mlx->mlx, "./textures/platform3.xpm",
			&q, &q);
	images.star[0] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/star/star1.xpm", &q, &q);
	images.star[1] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/star/star2.xpm", &q, &q);
	images.star[2] = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/star/star3.xpm", &q, &q);
	images.collectible = mlx_xpm_file_to_image(&mlx->mlx,
			"./textures/collectible.xpm", &q, &q);
	init_player_images(mlx, &images);
	init_seq_images(mlx, &images);
	init_number_images(mlx, &images);
	init_flowey_images(mlx, &images);
	return (images);
}
