#include "./../so_long.h"
#include "./../vendor/libsl/libsl.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 100

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
