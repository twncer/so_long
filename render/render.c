#include "./../so_long.h"
#include "./../vendor/minilibx-linux/mlx.h"
#include "./../vendor/libsl/libsl.h"
#include <stdio.h>

static void render_once(struct s_eventpkg *evpkg)
{
    struct s_position pos;

    pos.x = 0;
    pos.y = 0;
    while (evpkg->map.map[pos.y])
    {
        while (evpkg->map.map[pos.y][pos.x])
        {
            if (evpkg->map.map[pos.y][pos.x] == '0' || evpkg->map.map[pos.y][pos.x] == 'C')
                mlx_put_image_to_window(evpkg->mlx.mlx, evpkg->mlx.win, evpkg->images.ground, pos.x * GROUND_W, pos.y * GROUND_W);
            else if (evpkg->map.map[pos.y][pos.x] == '1')
                mlx_put_image_to_window(evpkg->mlx.mlx, evpkg->mlx.win, evpkg->images.wall, pos.x * GROUND_W, pos.y * GROUND_W);
            pos.x++;
        }
        pos.x = 0;
        while (pos.y > 0 && evpkg->map.map[pos.y - 1][pos.x])
        {
            if (evpkg->map.map[pos.y - 1][pos.x] == '1' && evpkg->map.map[pos.y][pos.x] != '1')
                mlx_put_image_to_window(evpkg->mlx.mlx, evpkg->mlx.win, evpkg->images.wall, pos.x * GROUND_W, (pos.y - 1) * GROUND_W);
            pos.x++;
        }
        pos.x = 0;
        pos.y++;
    }
}

void render_exit(struct s_eventpkg *evpkg)
{
    mlx_put_image_to_window(evpkg->mlx.mlx, evpkg->mlx.win, evpkg->map.exit_image, evpkg->map.exit_pos.x * 60 + 10, evpkg->map.exit_pos.y * 60 + 12);
}

void render_enemy(struct s_eventpkg *evpkg)
{
    struct s_position pos;

    pos.x = 0;
    pos.y = 0;
    while (evpkg->map.map[pos.y])
    {
        while (evpkg->map.map[pos.y][pos.x])
        {
            if (evpkg->map.map[pos.y][pos.x] == 'F')
                mlx_put_image_to_window(evpkg->mlx.mlx, evpkg->mlx.win, evpkg->map.enemy_image, pos.x * GROUND_W, pos.y * GROUND_W);
            pos.x++;
        }
        pos.x = 0;
        pos.y++;
    }
}

void render(struct s_eventpkg *evpkg)
{
    struct s_position pos;
    static bool first_time = true;
    
    if (first_time)
    {
        render_once(evpkg);
        first_time = !first_time;
        return ;
    }
    render_once(evpkg);
}