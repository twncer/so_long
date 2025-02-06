#include "so_long.h"

bool rec_walls(int way, unsigned int x, unsigned int y, char **map)
{
    int walls[5];

    if (way == 0) 
        return(map[y - 1][x] == '1');
    if (way == 1)
        return(map[y][x + 1] == '1');
    if (way == 2)
        return(map[y + 1][x] == '1');
    if (way == 3)
        return(map[y][x - 1] == '1');
    return (false);
}

char move_top(struct Map *map)
{
    char swap;
    
    if (!rec_walls(0, map->current_pos_x, map->current_pos_y, map->map))
    {
        swap = (map->map)[map->current_pos_y - 1][map->current_pos_x];
        (map->map)[map->current_pos_y][map->current_pos_x] = '0';
        (map->map)[map->current_pos_y - 1][map->current_pos_x] = 'P';
        map->current_pos_y = (map->current_pos_y) - 1;
        return (swap);
    }
    return ('Q');
}

char move_right(struct Map *map)
{
    char swap;
    
    if (!rec_walls(1, map->current_pos_x, map->current_pos_y, map->map))
    {
        swap = (map->map)[map->current_pos_y][map->current_pos_x + 1];
        (map->map)[map->current_pos_y][map->current_pos_x] = '0';    
        (map->map)[map->current_pos_y][map->current_pos_x + 1] = 'P';    
        map->current_pos_x = (map->current_pos_x) + 1;
        return (swap);
    }
    return ('Q');
}

char move_bottom(struct Map *map)
{
    char swap;
    
    if (!rec_walls(2, map->current_pos_x, map->current_pos_y, map->map))
    {
        swap = (map->map)[map->current_pos_y + 1][map->current_pos_x];
        (map->map)[map->current_pos_y][map->current_pos_x] = '0';
        (map->map)[map->current_pos_y + 1][map->current_pos_x] = 'P';
        map->current_pos_y = (map->current_pos_y) + 1;
        return (swap);
    }
    return ('Q');
}

char move_left(struct Map *map)
{
    char swap;
    
    if (!rec_walls(3, map->current_pos_x, map->current_pos_y, map->map))
    {
        swap = (map->map)[map->current_pos_y][map->current_pos_x - 1];
        (map->map)[map->current_pos_y][map->current_pos_x] = '0';
        (map ->map)[map->current_pos_y][map->current_pos_x - 1] = 'P';
        map->current_pos_x = (map->current_pos_x) - 1;
        return (swap);
    }
    return ('Q');
}