/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:56:13 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/13 21:54:00 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./collectibles/collectibles.h"
#include "./map/sl_map.h"
#include "./player/player.h"
#include "./render/render.h"
#include "./vendor/minilibx-linux/mlx.h"
#include "so_long.h"
#include "./vendor/ft_printf/ft_printf.h"

void	onpress_action(int key, struct s_eventpkg *evpkg)
{
	if (key == KEY_ESC)
		terminate(evpkg);
	if (key == KEY_D && evpkg->map.map[evpkg->player.position.y
			/ 60][evpkg->player.position.x / 60 + 1] != '1')
		evpkg->player.position.x += 60;
	else if (key == KEY_S && evpkg->map.map[evpkg->player.position.y / 60
			+ 1][evpkg->player.position.x / 60] != '1')
		evpkg->player.position.y += 60;
	else if (key == KEY_A && evpkg->map.map[evpkg->player.position.y
			/ 60][evpkg->player.position.x / 60 - 1] != '1')
		evpkg->player.position.x -= 60;
	else if (key == KEY_W && evpkg->map.map[evpkg->player.position.y / 60
			- 1][evpkg->player.position.x / 60] != '1')
		evpkg->player.position.y -= 60;
	render(evpkg);
}

int	onpress_event(int key, struct s_eventpkg *evpkg)
{
	static unsigned int	moves = 0;
	struct s_position	before_pos;

	before_pos.x = evpkg->player.position.x;
	before_pos.y = evpkg->player.position.y;
	onpress_action(key, evpkg);
	if (before_pos.x != evpkg->player.position.x
		|| before_pos.y != evpkg->player.position.y)
		moves += 1;
	ft_printf("Moves: %dblock (collectibles left: %d)\n", moves,
		evpkg->map.collectibles_left);
	if (evpkg->map.map[evpkg->player.position.y / 60][evpkg->player.position.x
		/ 60] == 'E')
		if (evpkg->map.collectibles_left == 0)
			terminate(evpkg);
	return (0);
}

int	terminate_hook(struct s_eventpkg *evpkg)
{
	terminate(evpkg);
	return (0);
}

int	loop_event(struct s_eventpkg *evpkg)
{
	collect(evpkg);
	return (0);
}

int	main(int argc, char **argv)
{
	struct s_eventpkg	evpkg;

	if (!(argc == 2))
		return (ft_printf("Error!\nUsg: ./so_long {path_to_map}\n"), 1);
	if (!map_is_valid(argv[1], &evpkg.map, false))
		return (ft_printf("Error!\nMap is not valid.\n"), 1);
	evpkg.mlx.mlx = mlx_init();
	if (!evpkg.mlx.mlx)
		return (ft_printf("MLX initialization failed.\n"), 1);
	evpkg.mlx.win = mlx_new_window(evpkg.mlx.mlx, WIN_W, WIN_H, "so_long.xd");
	if (!evpkg.mlx.win)
		return (ft_printf("Window creation failed.\n"), 1);
	evpkg.player = init_player(&evpkg.map);
	evpkg.images = init_images(evpkg.mlx.mlx);
	evpkg.map.exit_image = evpkg.images.star[0];
	evpkg.player.image = evpkg.images.player[0][0];
	evpkg.map.enemy_image = evpkg.images.flowey[0];
	mlx_hook(evpkg.mlx.win, 2, 1L << 0, onpress_event, &evpkg);
	mlx_hook(evpkg.mlx.win, 17, 0, terminate_hook, &evpkg);
	mlx_loop_hook(evpkg.mlx.mlx, loop_event, &evpkg);
	render(&evpkg);
	mlx_loop(evpkg.mlx.mlx);
}
