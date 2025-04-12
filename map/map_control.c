/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 22:59:23 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/12 05:03:44 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"
#include "./../vendor/libsl/libsl.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 100

char	*expand_buffer(char **buffer, char **expand)
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

char *write_to_buffer(char **buffer, char **buffer_temp, int fd)
{
	ssize_t	read_size;
	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, *buffer_temp, BUFFER_SIZE);
        if (read_size == -1)
            return (NULL);
		(*buffer_temp)[read_size] = '\0';
		if (expand_buffer(buffer, buffer_temp) == NULL)
			return (NULL);
	}
	return (NULL);
}

char	**set_map(char *path)
{
	char	*buffer;
	char	*buffer_temp;
	char	**res;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	buffer_temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer_temp)
		return (NULL);
	write_to_buffer(&buffer, &buffer_temp, fd);
	res = sl_split(buffer, '\n');
	return (close(fd), free(buffer), free(buffer_temp), res);
}

bool	check_is_rect(struct s_map *map)
{
	unsigned int	first_line_len;
	unsigned int	i;

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

bool	check_is_walls_valid(struct s_map *map)
{
	unsigned int	i;

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

void	set_pos(struct s_map *map)
{
	struct s_position pos;
	unsigned int	collectibles;

	pos.x = 0;
	pos.y = 0;
	collectibles = 0;
	while ((map->map)[pos.y])
	{
		while ((map->map)[pos.y][pos.x])
		{
			if ((map->map)[pos.y][pos.x] == 'P')
			{
				map->start_pos.y = pos.y;
				map->start_pos.x = pos.x;
				map->current_pos.y = pos.y;
				map->current_pos.x = pos.x;
			}
			else if ((map->map)[pos.y][pos.x] == 'E')
			{
				map->exit_pos.y = pos.y;
				map->exit_pos.x = pos.x;
			}
			else if ((map->map)[pos.y][pos.x] == 'C')
				collectibles++;
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
	map->collectibles_left = collectibles;
}

int flood(char **map, int x, int y)
{
	static bool exit_reached = false;
	static int collectibles_found = 0;
	
	if (map[y][x] == 'C')
		collectibles_found++;
	else if (map[y][x] == 'E')
		exit_reached = true;
	map[y][x] = '1';
	if (map[y - 1][x] != '1')
		flood(map, x, y - 1);
	if (map[y + 1][x] != '1')
		flood(map, x, y + 1);
	if (map[y][x - 1] != '1')
		flood(map, x - 1, y);
	if (map[y][x + 1] != '1')
		flood(map, x + 1, y);
	if (exit_reached && collectibles_found > 0)
		return (collectibles_found);
	return (0);
}

bool	map_is_valid(char *path, struct s_map *map)
{
	map->map = set_map(path);
	if (!map->map)
		return (false);
	if (check_is_rect(map) && check_is_walls_valid(map))
	{
		set_pos(map);
		if (flood(map->map, map->start_pos.x, map->start_pos.y) == map->collectibles_left)
		{
			free_map(map->map);
			map->map = set_map(path);
			return (true);
		}
	}
	free_map(map->map);
	return (false);
}
