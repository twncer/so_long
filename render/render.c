#include "./../so_long.h"
#include "./../vendor/minilibx-linux/mlx.h"
#include "./../vendor/libsl/libsl.h"
#include <stdio.h>

static void put_img(struct s_mlx *mlx, void *image, unsigned int x, unsigned int y)
{
    mlx_put_image_to_window(mlx->mlx, mlx->win, image, x, y);
}

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
                put_img(&evpkg->mlx, evpkg->images.ground, pos.x * GROUND_W, pos.y * GROUND_W);
            else if (evpkg->map.map[pos.y][pos.x] == '1')
                put_img(&evpkg->mlx, evpkg->images.wall, pos.x * GROUND_W, pos.y * GROUND_W);
            pos.x++;
        }
        pos.x = 0;
        put_img(&evpkg->mlx, evpkg->player.image, evpkg->player.position.x, evpkg->player.position.y - 26);
        while (pos.y > 0 && evpkg->map.map[pos.y - 1][pos.x])
        {
            if (evpkg->map.map[pos.y - 1][pos.x] == '1' && evpkg->map.map[pos.y][pos.x] != '1')
                put_img(&evpkg->mlx, evpkg->images.wall, pos.x * GROUND_W, (pos.y - 1) * GROUND_W);    
            pos.x++;
        }
        pos.x = 0;
        pos.y++;
    }
}

void render_exit(struct s_eventpkg *evpkg)
{
    put_img(&evpkg->mlx, evpkg->map.exit_image, evpkg->map.exit_pos.x * 60 + 10, evpkg->map.exit_pos.y * 60 + 12);
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
                put_img(&evpkg->mlx, evpkg->map.enemy_image, pos.x * GROUND_W, pos.y * GROUND_W);
            pos.x++;
        }
        pos.x = 0;
        pos.y++;
    }
}

void render_around_player(struct s_eventpkg *evpkg)
{
    struct s_position pos;

    pos.x = evpkg->player.position.x / 60 - 1;
    pos.y = evpkg->player.position.y / 60 - 1;
    while (pos.y <= evpkg->player.position.y / 60 + 1)
    {
        while (pos.x <= evpkg->player.position.x / 60 + 1)
        {
            if (evpkg->map.map[pos.y][pos.x] == '1')
                put_img(&evpkg->mlx, evpkg->images.wall, pos.x * GROUND_W, pos.y * GROUND_W);
            else if (evpkg->map.map[pos.y][pos.x] == '0')
                put_img(&evpkg->mlx, evpkg->images.ground, pos.x * GROUND_W, pos.y * GROUND_W);
            if (pos.x == evpkg->player.position.x / 60 && pos.y == evpkg->player.position.y / 60)
                put_img(&evpkg->mlx, evpkg->player.image, evpkg->player.position.x, evpkg->player.position.y);
            pos.x++;
        }
        pos.x = evpkg->player.position.x / 60 - 1;
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