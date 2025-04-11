/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:43:43 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/11 14:48:55 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../sequences/seq.h"
#include "./../so_long.h"

void	die(struct s_eventpkg *evpkg, int attack_phase)
{
	if (evpkg->map.map[(evpkg->player.position.y + 30)
			/ 60][(evpkg->player.position.x + 50 - (attack_phase * 5)) / 60
		+ 1] == 'F' || evpkg->map.map[(evpkg->player.position.y + 30)
		/ 60][(evpkg->player.position.x + 20 + (attack_phase * 5)) / 60
		- 1] == 'F')
		seq_dead(evpkg);
}

int	increase_phase(int attack_phase)
{
	static long long	frame_log_time = 0;
	long long			time_h;

	time_h = current_time_ms();
	if (time_h - frame_log_time > 200)
	{
		if (attack_phase == 8)
			attack_phase = 0;
		else
			attack_phase++;
		frame_log_time = time_h;
	}
	return (attack_phase);
}

void	shoot(struct s_eventpkg *evpkg)
{
	static int			attack_phase = 0;
	struct s_position	pos;

	pos.x = 0;
	pos.y = 0;
	while (evpkg->map.map[pos.y])
	{
		while (evpkg->map.map[pos.y][pos.x])
		{
			if (evpkg->map.map[pos.y][pos.x] == 'F')
			{
				put_img(&evpkg->mlx, evpkg->map.pellet_image, pos.x * 60 - 17
					- (attack_phase * 5), pos.y * 60 + 30);
				put_img(&evpkg->mlx, evpkg->map.pellet_image, pos.x * 60 + 61
					+ (attack_phase * 5), pos.y * 60 + 30);
			}
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
	die(evpkg, attack_phase);
	attack_phase = increase_phase(attack_phase);
}
