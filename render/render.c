/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:03:45 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/13 21:41:17 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"
#include "./render.h"

void	render_onplayer_walls(struct s_eventpkg *evpkg)
{
	struct s_position	pos;

	pos.x = 0;
	pos.y = evpkg->player.position.y / 60 + 1;
	while (evpkg->map.map[pos.y])
	{
		while (evpkg->map.map[pos.y][pos.x])
		{
			if (evpkg->map.map[pos.y][pos.x] == '1')
				put_img(&evpkg->mlx, evpkg->images.wall, pos.x * GROUND_W, pos.y
					* GROUND_W);
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
}

void	render_comps(struct s_eventpkg *evpkg, struct s_position *pos)
{
	if (evpkg->map.map[pos->y][pos->x] != '1')
		put_img(&evpkg->mlx, evpkg->images.ground, pos->x * GROUND_W, pos->y
			* GROUND_W);
	else if (evpkg->map.map[pos->y][pos->x] == '1')
		put_img(&evpkg->mlx, evpkg->images.wall, pos->x * GROUND_W, pos->y
			* GROUND_W);
	if (evpkg->map.map[pos->y][pos->x] == 'C')
		put_img(&evpkg->mlx, evpkg->images.collectible, pos->x * GROUND_W + 15,
			pos->y * GROUND_W + 20);
	else if (evpkg->map.map[pos->y][pos->x] == 'E')
		put_img(&evpkg->mlx, evpkg->map.exit_image, pos->x * GROUND_W + 15,
			pos->y * GROUND_W + 16);
}

void	render_once(struct s_eventpkg *evpkg)
{
	struct s_position	pos;

	pos.x = 0;
	pos.y = 0;
	while (evpkg->map.map[pos.y])
	{
		while (evpkg->map.map[pos.y][pos.x])
		{
			render_comps(evpkg, &pos);
			pos.x++;
		}
		pos.x = 0;
		put_img(&evpkg->mlx, evpkg->player.image, evpkg->player.position.x,
			evpkg->player.position.y - 26);
		while (pos.y > 0 && evpkg->map.map[pos.y - 1][pos.x++])
		{
			if (evpkg->map.map[pos.y - 1][pos.x] == '1'
				&& evpkg->map.map[pos.y][pos.x] != '1')
				put_img(&evpkg->mlx, evpkg->images.wall, pos.x * GROUND_W,
					(pos.y - 1) * GROUND_W);
		}
		pos.x = 0;
		pos.y++;
	}
	render_onplayer_walls(evpkg);
}

void	render_enemy(struct s_eventpkg *evpkg)
{
	struct s_position	pos;

	pos.x = 0;
	pos.y = 0;
	while (evpkg->map.map[pos.y])
	{
		while (evpkg->map.map[pos.y][pos.x])
		{
			if (evpkg->map.map[pos.y][pos.x] == 'F')
				put_img(&evpkg->mlx, evpkg->map.enemy_image, pos.x * GROUND_W
					+ 10, pos.y * GROUND_W + 10);
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
}

void	render(struct s_eventpkg *evpkg)
{
	static bool	first_time = true;

	if (first_time)
	{
		render_once(evpkg);
		first_time = !first_time;
		return ;
	}
	render_once(evpkg);
	render_enemy(evpkg);
}
