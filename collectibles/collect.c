/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:33:31 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/13 17:45:27 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	collect(struct s_eventpkg *evpkg)
{
	if (evpkg->map.map[(evpkg->player.position.y + 30)
			/ 60][(evpkg->player.position.x + 30) / 60] == 'C')
	{
		evpkg->map.collectibles_left--;
		evpkg->map.map[(evpkg->player.position.y + 30)
			/ 60][(evpkg->player.position.x + 30) / 60] = '0';
	}
}
