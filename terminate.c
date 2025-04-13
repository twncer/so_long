/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:19:08 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/13 20:19:08 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vendor/minilibx-linux/mlx.h"
#include "render/render.h"
#include "so_long.h"
#include <stdlib.h>

void	free_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
}

void	terminate(struct s_eventpkg *evpkg)
{
	free_images(evpkg);
	evpkg->player.image = NULL;
	free_map(evpkg->map.map);
	mlx_destroy_window(evpkg->mlx.mlx, evpkg->mlx.win);
	mlx_destroy_display(evpkg->mlx.mlx);
	free(evpkg->mlx.mlx);
	exit(0);
}
