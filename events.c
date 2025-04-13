/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:17:48 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/13 21:32:02 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./animate/sl_animations.h"
#include "./collectibles/collectibles.h"
#include "./enemy_shoot/shoot.h"
#include "./movement/movement.h"
#include "./render/render.h"
#include "so_long.h"
#include <sys/time.h>

long long	current_time_ms(void)
{
	struct timeval	tval;

	gettimeofday(&tval, (void *)0);
	return ((long long)(tval.tv_sec) *1000 + (tval.tv_usec) / 1000);
}

int	onpress_event(int key, struct s_eventpkg *evpkg)
{
	if (key == KEY_ESC)
		terminate(evpkg);
	key_pressed(key, &(evpkg->key_list));
	return (0);
}

int	onrelease_event(int key, struct s_eventpkg *evpkg)
{
	key_released(key, &(evpkg->key_list));
	return (0);
}

int	terminate_hook(struct s_eventpkg *evpkg)
{
	terminate(evpkg);
	return (0);
}

int	loop_event(struct s_eventpkg *evpkg)
{
	animate_flowey(evpkg);
	animate_exit(evpkg);
	animate_palette(evpkg);
	render(evpkg);
	collect(evpkg);
	move_player(evpkg);
	shoot(evpkg);
	return (0);
}
