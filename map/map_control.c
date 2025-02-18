/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 22:59:23 by btuncer           #+#    #+#             */
/*   Updated: 2025/02/13 13:20:16 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "./../so_long.h"
#include "./../vendor/libsl/libsl.h"
#include <stdlib.h>
#include <stdio.h>
#define BUFFER_SIZE 100

static char	*expand_buffer(char **buffer, char **expand)
{
	char	*temp;

	temp = malloc(len(*buffer) + len(*expand) + 1);
	if (temp == NULL)
		return (NULL);
	setstr(&temp, buffer, 0);
	setstr(&temp, expand, len(*buffer));
	temp[len(*buffer) + len(*expand)] = '\0';
	free(*buffer);
	(*buffer) = temp;
	return (*buffer);
}

static char **set_map(char *path)
{
    char *buffer;
    char *buffer_temp;
    char **res;
    int fd;
    ssize_t read_size;

    buffer = malloc(sizeof(char) * BUFFER_SIZE);
    fd = open(path, O_RDONLY); //if !fd
    read_size = 1;
    buffer_temp = malloc(sizeof(char) * BUFFER_SIZE);
    while (read_size > 0)
    {
        read_size = read(fd, buffer_temp, BUFFER_SIZE); //if read_size == -1
        buffer_temp[read_size] = '\0';
        if (expand_buffer(&buffer, &buffer_temp) == NULL)
            return (NULL);
    }
    close(fd);
    res = sl_split(buffer, '\n');
    free(buffer);
    free(buffer_temp);
    return (res);
}

static bool check_is_rect(struct s_map *map)
{
    unsigned int first_line_len;
    unsigned int i;
    
    i = 0;
    first_line_len = len(*(map->map));
    while ((map->map)[i])
    {
        if (len((map->map)[i]) != first_line_len)
            return (false);
        i++;
    }
    map->height = i;
    map->width = first_line_len;
    return (true);
}

static bool check_is_walls_valid(struct s_map *map)
{
    unsigned int i;

    i = 0;
    while ((map->map)[i])
    {
        if ((map->map)[i][0] != '1' || (map->map)[i][(map->width) - 1] != '1')
            return (false);
        i++;
    }
    i = 0;
    while (i < map->width)
    {
        if ((map->map)[0][i] != '1' || (map->map)[map->height - 1][i] != '1')
            return (false);
        i++;
    }
    return (true);
}

static void set_pos(struct s_map *map)
{
    unsigned int x;
    unsigned int y;
    
    x = 0;
    y = 0;
    while ((map->map)[y][x])
    {
        while ((map->map)[y][x])
        {
            if ((map->map)[y][x] == 'P')
            {
                map->start_pos.y = y;
                map->start_pos.x = x;
                map->current_pos.y = y;
                map->current_pos.x = x;
                return ;
            }
            x++;
        }
        x = 0;
        y++;
    }
}

bool map_is_valid(char *path, struct s_map *map)
{
    map->map = set_map(path);
    map->is_rect = check_is_rect(map);
    map->is_walls_valid = check_is_walls_valid(map);
    // check if there is P C and E
    set_pos(map);
    return (true);
}
