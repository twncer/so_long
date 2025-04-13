/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_pellets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:29:44 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/13 21:21:27 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	animate_palette(struct s_eventpkg *evpkg)
{
	static int			frame = 0;
	static long long	frame_log_time = 0;
	long long			time_h;

	time_h = current_time_ms();
	if (time_h - frame_log_time > 150)
	{
		if (frame == 0)
			frame = 1;
		else if (frame == 1)
			frame = 0;
		frame_log_time = time_h;
	}
	evpkg->map.pellet_image = evpkg->images.pellets[frame];
}
