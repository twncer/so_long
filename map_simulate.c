/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_simulate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:32:35 by btuncer           #+#    #+#             */
/*   Updated: 2025/02/06 04:18:38 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <unistd.h>

void draw_map(struct Map *map)
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
    printf("\nx position: %u", map->current_pos_x);
    printf("\ny position: %u\n", map->current_pos_y);
}

bool simulate_map(struct Map *map)
{
    if (1)
        return (true);
    unsigned int moves;
    char next_char;
    unsigned int x;
    unsigned int y;
    printf("Total moves: %u", moves);
    return (next_char == 'E');
}

