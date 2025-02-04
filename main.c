/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 22:14:49 by btuncer           #+#    #+#             */
/*   Updated: 2025/02/05 01:44:37 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct Map map;
    unsigned int i;

    i = 0;
    if (map_is_valid("./maps/maze.ber", &map))
    {
        while ((map.map)[i])
        {
            printf("%s", (map.map)[i]);
            printf("\n");
            free((map.map)[i]);
            i++;
        }
        printf("\nis_rect = %d", map.is_rect);
        printf("\nis_walls_valid = %d", map.is_walls_valid);
        printf("\nstarting y position: %u", map.start_pos_y);
        printf("\nstarting x position: %u", map.start_pos_x);
        free((map.map));
    }
}