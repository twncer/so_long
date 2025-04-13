/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:29:46 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/13 21:21:33 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	animate_player(struct s_eventpkg *evpkg)
{
	static int			frame = 0;
	static long long	frame_log_time = 0;
	long long			time_h;

	time_h = current_time_ms();
	if (time_h - frame_log_time > 300)
	{
		if (frame == 0)
			frame = 1;
		else if (frame == 1)
			frame = 0;
		frame_log_time = time_h;
	}
	if (evpkg->key_list.key_w)
		evpkg->player.image = evpkg->images.player[1][frame];
	else if (evpkg->key_list.key_s)
		evpkg->player.image = evpkg->images.player[3][frame];
	else if (evpkg->key_list.key_a)
		evpkg->player.image = evpkg->images.player[4][frame];
	else if (evpkg->key_list.key_d)
		evpkg->player.image = evpkg->images.player[2][frame];
}

void	idleize_player(struct s_eventpkg *evpkg)
{
	evpkg->player.image = evpkg->images.player[0][0];
}
