#include "./../so_long.h"
#include "./../render/render.h"
#include "./../animate/sl_animations.h"

void move_player(struct s_eventpkg *evpkg)
{
	static int limiter = 0;
	
	if (limiter == 1)
	{
		limiter = 0;
		return ;
	}
	else
		limiter = 1;
    if (evpkg->key_list.key_a || evpkg->key_list.key_d 
    || evpkg->key_list.key_w || evpkg->key_list.key_s) // render just if player moves
		animate_player(evpkg);
	else
		idleize_player(evpkg);
    if (evpkg->key_list.key_d && evpkg->map.map[evpkg->player.position.y / 60][evpkg->player.position.x / 60 + 1] != '1')
        evpkg->player.position.x += PLAYER_PPM;
    if (evpkg->key_list.key_a && evpkg->map.map[evpkg->player.position.y / 60][(evpkg->player.position.x - 1) / 60] != '1')
        evpkg->player.position.x -= PLAYER_PPM;
    if (evpkg->key_list.key_w && !(evpkg->map.map[(evpkg->player.position.y - 1) / 60][evpkg->player.position.x / 60] == '1' ||
        evpkg->map.map[(evpkg->player.position.y - 1) / 60][(evpkg->player.position.x + 59) / 60] == '1'))
        evpkg->player.position.y -= PLAYER_PPM;
    if (evpkg->key_list.key_s && !(evpkg->map.map[(evpkg->player.position.y + 1) / 60][evpkg->player.position.x / 60] == '1' ||
        evpkg->map.map[(evpkg->player.position.y + 1) / 60][(evpkg->player.position.x + 59) / 60] == '1'))
        evpkg->player.position.y += PLAYER_PPM;
        
    evpkg->map.current_pos.x = evpkg->player.position.x / 60;
    evpkg->map.current_pos.y = evpkg->player.position.y / 60;

	if (evpkg->map.current_pos.x > 20)
		camera_move_x(evpkg->player.position.x - 21 * 60 - 1);
	if (evpkg->map.current_pos.y > 10)
		camera_move_y(evpkg->player.position.y - 11 * 60 - 1);
}

bool	rec_walls(int way, unsigned int x, unsigned int y, char **map)
{
	if (way == 0)
		return (map[y - 1][x] == '1');
	if (way == 1)
		return (map[y][x + 1] == '1');
	if (way == 2)
		return (map[y + 1][x] == '1');
	if (way == 3)
		return (map[y][x - 1] == '1');
	return (false);
}

char	move_top(struct s_map *map)
{
	char	swap;

	if (!rec_walls(0, map->current_pos.x, map->current_pos.y, map->map))
	{
		swap = (map->map)[map->current_pos.y - 1][map->current_pos.x];
		(map->map)[map->current_pos.y][map->current_pos.x] = '0';
		(map->map)[map->current_pos.y - 1][map->current_pos.x] = 'P';
		map->current_pos.y = (map->current_pos.y) - 1;
		return (swap);
	}
	return ('Q');
}

char	move_right(struct s_map *map)
{
	char	swap;

	if (!rec_walls(1, map->current_pos.x, map->current_pos.y, map->map))
	{
		swap = (map->map)[map->current_pos.y][map->current_pos.x + 1];
		(map->map)[map->current_pos.y][map->current_pos.x] = '0';
		(map->map)[map->current_pos.y][map->current_pos.x + 1] = 'P';
		map->current_pos.x = (map->current_pos.x) + 1;
		return (swap);
	}
	return ('Q');
}

char	move_bottom(struct s_map *map)
{
	char	swap;

	if (!rec_walls(2, map->current_pos.x, map->current_pos.y, map->map))
	{
		swap = (map->map)[map->current_pos.y + 1][map->current_pos.x];
		(map->map)[map->current_pos.y][map->current_pos.x] = '0';
		(map->map)[map->current_pos.y + 1][map->current_pos.x] = 'P';
		map->current_pos.y = (map->current_pos.y) + 1;
		return (swap);
	}
	return ('Q');
}

char	move_left(struct s_map *map)
{
	char swap;

	if (!rec_walls(3, map->current_pos.x, map->current_pos.y, map->map))
	{
		swap = (map->map)[map->current_pos.y][map->current_pos.x - 1];
		(map->map)[map->current_pos.y][map->current_pos.x] = '0';
		(map->map)[map->current_pos.y][map->current_pos.x - 1] = 'P';
		map->current_pos.x = (map->current_pos.x) - 1;
		return (swap);
	}
	return ('Q');
}
