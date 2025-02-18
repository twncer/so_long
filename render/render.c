#include "./../so_long.h"
#include "./../vendor/minilibx-linux/mlx.h"
#include "./../vendor/libsl/libsl.h"
#include <stdio.h>

static void render_walls1(struct s_map *map, struct s_mlx *mlx)
{
    void *image;
    int q;
    struct s_position pos;

    image = mlx_xpm_file_to_image(mlx->mlx, "./textures/wall.xpm", &q, &q);
    pos.x = 0;
    pos.y = 0;
    while ((map->map)[pos.y])
    {
        while ((map->map)[pos.y][pos.x])
        {
            if ((map->map)[pos.y][pos.x] == '1')
                mlx_put_image_to_window(mlx->mlx, mlx->win, image, pos.x * GROUND_W, pos.y * GROUND_W);
            /* else if ((map->map)[pos.y][pos.x] == 'P')
                return ; */
            pos.x = pos.x + 1;
        }
        pos.x = 0;
        pos.y = pos.y + 1;
    }
}

static void render_ground1(struct s_map *map, struct s_mlx *mlx)
{
    void *image;
    int q;
    struct s_position pos;

    image = mlx_xpm_file_to_image(mlx->mlx, "./textures/platform3.xpm", &q, &q);
    pos.x = 0;
    pos.y = 0;
    while ((map->map)[pos.y])
    {
        while ((map->map)[pos.y][pos.x])
        {
            if (in("0CEP", (map->map)[pos.y][pos.x]))
                mlx_put_image_to_window(mlx->mlx, mlx->win, image, pos.x * GROUND_W, pos.y * GROUND_W);
            pos.x = pos.x + 1;
        }
        pos.x = 0;
        pos.y = pos.y + 1;
    }
}

static void render_player1(struct s_mlx *mlx, struct s_player *player)
{
    int q;

    mlx_put_image_to_window(mlx->mlx, mlx->win, player->image, player->position.x, player->position.y - 26);
}

static void render_underplayer_walls1(struct s_map *map, struct s_mlx *mlx)
{
    void *image;
    int q;
    struct s_position pos;

    image = mlx_xpm_file_to_image(mlx->mlx, "./textures/wall.xpm", &q, &q);
    pos.x = map->current_pos.x;
    pos.y = map->current_pos.y;
    while ((map->map)[pos.y][pos.x])
    {
        if ((map->map)[pos.y][pos.x] == '1')
            mlx_put_image_to_window(mlx->mlx, mlx->win, image, pos.x * GROUND_W, pos.y * GROUND_W - 39);
        pos.x = pos.x + 1;
    }
}

static void render_all(struct s_map *map, struct s_mlx *mlx, struct s_player *player)
{
    int q;
    void *img_ground = mlx_xpm_file_to_image(mlx->mlx, "./textures/platform3.xpm", &q, &q);
    void *img_wall = mlx_xpm_file_to_image(mlx->mlx, "./textures/wall.xpm", &q, &q);
    struct s_position pos;

    pos.x = 0;
    pos.y = 0;
    mlx_put_image_to_window(mlx->mlx, mlx->win, player->image, player->position.x, player->position.y - 26);
    while (map->map[pos.y])
    {
        while (map->map[pos.y][pos.x])
        {
            if (map->map[pos.y][pos.x] == '1')
                mlx_put_image_to_window(mlx->mlx, mlx->win, img_wall, pos.x * GROUND_W, pos.y * GROUND_W - 39);
            else if (map->map[pos.y][pos.x] == '0')
                mlx_put_image_to_window(mlx->mlx, mlx->win, img_ground, pos.x * GROUND_W, pos.y * GROUND_W);
            else if (map->map[pos.y][pos.x] == 'P')
                mlx_put_image_to_window(mlx->mlx, mlx->win, player->image, player->position.x * 60, player->position.y * 60);
            pos.x = pos.x + 1;
        }
        pos.x = 0;
        pos.y = pos.y + 1;
    }
}
render_ground(struct s_eventpkg *evpkg, struct s_position *pos0, struct s_position *pos1)
{
    struct s_position pos;
    void *wall_img;
    int q;

    pos.x = pos0->x;
    pos.y = pos0->y;
    wall_img = mlx_xpm_file_to_image(evpkg->mlx.mlx, "./textures/platform3.xpm", &q, &q);
    while (pos.y <= pos1->y)
    {
        while (pos.x <= pos1->x)
        {
            mlx_put_image_to_window(evpkg->mlx.mlx, evpkg->mlx.win, wall_img, pos0->x * 60, pos0->y * 60);
            pos.x = pos.x + 1;
        }
        pos.x = pos0->x;
        pos.y = pos.y + 1;
    }
}

void render(struct s_eventpkg *evpkg)
{
    int i;
    int k;
    int q;
    void *img_ground = mlx_xpm_file_to_image(evpkg->mlx.mlx, "./textures/platform3.xpm", &q, &q);
    void *img_wall = mlx_xpm_file_to_image(evpkg->mlx.mlx, "./textures/wall.xpm", &q, &q);
    i = 0;
    k = 0;
    while (k < 3)
    {
        while (&evpkg->map.current_pos - 1 + i <= &evpkg->map.current_pos + 1)
        {
            mlx_put_image_to_window(evpkg->mlx.mlx, evpkg->mlx.win, img_ground, (evpkg->map.current_pos.x - 1 + i) * 60, 
                                                                            (evpkg->map.current_pos.y - 1 + k) * 60);
            i++;
        }
        i = 0;  
        k++;
    }
    render_player1(&evpkg->mlx, &evpkg->player);
    render_walls1(&evpkg->map, &evpkg->mlx);
}