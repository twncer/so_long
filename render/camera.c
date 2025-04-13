/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:22:40 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/13 21:41:16 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	camera_move_x(long set)
{
	static long	moves_x = 0;

	if (set > 0)
		moves_x = set;
	return (moves_x);
}

long	camera_move_y(long set)
{
	static long	moves_y = 0;

	if (set > 0)
		moves_y = set;
	return (moves_y);
}
