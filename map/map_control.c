/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 22:59:23 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/13 21:26:11 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"
#include "./../vendor/libsl/libsl.h"
#include "./sl_map.h"
#include <fcntl.h>
#include <stdlib.h>

char	*write_to_buffer(char **buffer, char **buffer_temp, int fd)
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
	return (*buffer);
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
	if (write_to_buffer(&buffer, &buffer_temp, fd) == NULL)
		return (NULL);
	res = sl_split(buffer, '\n');
	return (close(fd), free(buffer), free(buffer_temp), res);
}

bool	check_position(struct s_map *map, struct s_position *pos, bool bonus)
{
	static int	p_counter = 0;
	static int	e_counter = 0;

	if ((map->map)[pos->y][pos->x] == 'P')
	{
		map->start_pos.y = pos->y;
		map->start_pos.x = pos->x;
		map->current_pos.y = pos->y;
		map->current_pos.x = pos->x;
		p_counter++;
	}
	else if ((map->map)[pos->y][pos->x] == 'E')
	{
		map->exit_pos.y = pos->y;
		map->exit_pos.x = pos->x;
		e_counter++;
	}
	else if ((map->map)[pos->y][pos->x] != '1'
		&& (map->map)[pos->y][pos->x] != '0'
		&& (map->map)[pos->y][pos->x] != 'F')
		return (false);
	else if ((!bonus && (map->map)[pos->y][pos->x] == 'F') || (p_counter > 1
			|| e_counter > 1))
		return (false);
	return (true);
}

bool	set_pos(struct s_map *map, bool bonus)
{
	struct s_position	pos;
	unsigned int		collectibles;

	pos.x = 0;
	pos.y = 0;
	collectibles = 0;
	while ((map->map)[pos.y])
	{
		while ((map->map)[pos.y][pos.x])
		{
			if ((map->map)[pos.y][pos.x] == 'C')
				collectibles++;
			else if (check_position(map, &pos, bonus) == false)
				return (false);
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
	map->collectibles_left = collectibles;
	return (true);
}

bool	map_is_valid(char *path, struct s_map *map, bool bonus)
{
	map->start_pos.x = 1;
	map->start_pos.y = 1;
	map->map = set_map(path);
	if (!map->map)
		return (false);
	if (check_is_rect(map) && check_is_walls_valid(map) && set_pos(map, bonus))
	{
		if (map->collectibles_left > 0 && flood(map->map, map->start_pos.x,
				map->start_pos.y) == map->collectibles_left)
		{
			free_map(map->map);
			map->map = set_map(path);
			return (true);
		}
	}
	free_map(map->map);
	return (false);
}
