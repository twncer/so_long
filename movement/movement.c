/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:02:02 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/11 17:49:51 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../animate/sl_animations.h"
#include "./../render/render.h"
#include "./../so_long.h"
#include "./../sequences/seq.h"
#include "./movement.h"
#include <stdio.h>
#include <limits.h>

bool	limiter(void)
{
	static int	limiter = 0;

	if (limiter == 1)
	{
		limiter = 0;
		return (true);
	}
	else
		limiter = 1;
	return (false);
}

void	if_keys_pressed(struct s_eventpkg *evpkg)
{
	if (evpkg->key_list.key_a || evpkg->key_list.key_d || evpkg->key_list.key_w
		|| evpkg->key_list.key_s)
		animate_player(evpkg);
	else
		idleize_player(evpkg);
}

void	player_actions(struct s_eventpkg *evpkg)
{
	evpkg->map.current_pos.x = evpkg->player.position.x / 60;
	evpkg->map.current_pos.y = evpkg->player.position.y / 60;
	if (evpkg->map.current_pos.x > 20)
		camera_move_x(evpkg->player.position.x - 21 * 60 - 1);
	if (evpkg->map.current_pos.y > 8)
		camera_move_y(evpkg->player.position.y - 9 * 60 - 1);
	if ((evpkg->player.position.x + 30) / 60 == evpkg->map.exit_pos.x
		&& (evpkg->player.position.y + 30) / 60 == evpkg->map.exit_pos.y
		&& evpkg->map.collectibles_left == 0)
		seq_win(evpkg);
}

unsigned int move_actually(struct s_eventpkg *evpkg, char ax)
{
	static unsigned int move_counter = 0;

	if (ax == 'd')
		evpkg->player.position.x += PLAYER_PPM;
	else if (ax == 'a')
		evpkg->player.position.x -= PLAYER_PPM;
	else if (ax == 's')
		evpkg->player.position.y += PLAYER_PPM;
	else if (ax == 'w')
		evpkg->player.position.y -= PLAYER_PPM;
	if (ax == 'd' || ax == 'a' || ax == 's' || ax == 'w')
		move_counter += 1;
	return (move_counter);
}

void	move_player(struct s_eventpkg *evpkg)
{
	if (limiter())
		return ;
	if_keys_pressed(evpkg);
	if (evpkg->key_list.key_d && evpkg->map.map[evpkg->player.position.y
			/ 60][evpkg->player.position.x / 60 + 1] != '1')
		move_actually(evpkg, 'd');
	if (evpkg->key_list.key_a && evpkg->map.map[evpkg->player.position.y
			/ 60][(evpkg->player.position.x - 1) / 60] != '1')
		move_actually(evpkg, 'a');
	if (evpkg->key_list.key_w && !(evpkg->map.map[(evpkg->player.position.y - 1)
				/ 60][evpkg->player.position.x / 60] == '1'
		|| evpkg->map.map[(evpkg->player.position.y - 1)
			/ 60][(evpkg->player.position.x + 59) / 60] == '1'))
		move_actually(evpkg, 'w');
	if (evpkg->key_list.key_s && !(evpkg->map.map[(evpkg->player.position.y + 1)
				/ 60][evpkg->player.position.x / 60] == '1'
		|| evpkg->map.map[(evpkg->player.position.y + 1)
			/ 60][(evpkg->player.position.x + 59) / 60] == '1'))
		move_actually(evpkg, 's');
	player_actions(evpkg);
	display_moves(evpkg, move_actually(evpkg, 'g'));
}
