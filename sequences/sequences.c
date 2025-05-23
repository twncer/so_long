/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequences.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:14:22 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/13 21:29:54 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../render/render.h"
#include "./../so_long.h"

void	seq_dead(struct s_eventpkg *evpkg)
{
	long long	time_h;
	long long	time_h_2;
	long long	frame_log_time;
	int			y;

	time_h = current_time_ms();
	frame_log_time = time_h;
	y = -800;
	while (current_time_ms() < time_h + 8000)
	{
		put_img_to_hud(&evpkg->mlx, evpkg->images.seq_images[0], 725, y);
		time_h_2 = current_time_ms();
		if (time_h_2 - frame_log_time > 5)
		{
			y = y + 4;
			frame_log_time = time_h_2;
		}
	}
	terminate(evpkg);
}

void	seq_win(struct s_eventpkg *evpkg)
{
	long long	time_h;
	long long	time_h_2;
	long long	frame_log_time;
	int			y;

	time_h = current_time_ms();
	frame_log_time = time_h;
	y = -800;
	while (current_time_ms() < time_h + 6000)
	{
		put_img_to_hud(&evpkg->mlx, evpkg->images.seq_images[1], 725, y);
		time_h_2 = current_time_ms();
		if (time_h_2 - frame_log_time > 2)
		{
			y = y + 5;
			frame_log_time = time_h_2;
		}
	}
	terminate(evpkg);
}
