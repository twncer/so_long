/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_simulate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:32:35 by btuncer           #+#    #+#             */
/*   Updated: 2025/02/12 15:24:21 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"
#include <stdio.h>
#include <unistd.h>

void draw_map(struct s_map *map)
{
    int i;
    i = 0;
    while ((map->map)[i])
    {
        printf("%s", (map->map)[i]);
        printf("\n");
        i++;
    }
    printf("\nis_rect = %d", map->is_rect);
    printf("\nis_walls_valid = %d", map->is_walls_valid);
    printf("\nx position: %u", map->current_pos.x);
    printf("\ny position: %u\n", map->current_pos.y);
}
