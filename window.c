/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:56:13 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/13 21:43:24 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vendor/minilibx-linux/mlx.h"
#include "./animate/sl_animations.h"
#include "./map/sl_map.h"
#include "./movement/movement.h"
#include "./render/render.h"
#include "./player/player.h"
#include "so_long.h"
#include "./vendor/ft_printf/ft_printf.h"

int	main(int argc, char **argv)
{
	struct s_key_listener	key_list;
	struct s_eventpkg		evpkg;

	if (!(argc == 2))
		return (1);
	init_keys(&key_list);
	if (!map_is_valid(argv[1], &evpkg.map, true))
		return (ft_printf("Error!\nMap is not valid.\n"), 1);
	evpkg.mlx.mlx = mlx_init();
	if (!evpkg.mlx.mlx)
		return (ft_printf("MLX initialization failed.\n"), 1);
	evpkg.mlx.win = mlx_new_window(evpkg.mlx.mlx, WIN_W, WIN_H, "so_long.xd");
	if (!evpkg.mlx.win)
		return (ft_printf("Window creation failed.\n"), 1);
	evpkg.player = init_player(&evpkg.map);
	evpkg.key_list = key_list;
	evpkg.images = init_images(evpkg.mlx.mlx);
	evpkg.map.exit_image = evpkg.images.star[0];
	idleize_player(&evpkg);
	mlx_hook(evpkg.mlx.win, 2, 1L << 0, onpress_event, &evpkg);
	mlx_hook(evpkg.mlx.win, 3, 1L << 1, onrelease_event, &evpkg);
	mlx_hook(evpkg.mlx.win, 17, 0, terminate_hook, &evpkg);
	mlx_loop_hook(evpkg.mlx.mlx, loop_event, &evpkg);
	render(&evpkg);
	mlx_loop(evpkg.mlx.mlx);
}
