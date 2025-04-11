/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_flowey.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:29:37 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/11 14:29:38 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"
#include "./sl_animations.h"

void	animate_flowey(struct s_eventpkg *evpkg)
{
	static int			frame = 0;
	static long long	frame_log_time = 0;
	long long			time_h;

	time_h = current_time_ms();
	if (time_h - frame_log_time > 400)
	{
		if (frame == 0)
			frame = 1;
		else if (frame == 1)
			frame = 0;
		frame_log_time = time_h;
	}
	evpkg->map.enemy_image = evpkg->images.flowey[frame];
}
