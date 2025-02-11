// cc window.c -Lminilibx-linux minilibx-linux/libmlx.a -lX11 -lXext -o a 

#include "./vendor/minilibx-linux/mlx.h"
#include "./vendor/libsl/libsl.h"
#include "so_long.h"
#include "./map/sl_map.h"
#include <stdio.h>
#define PLATFORM_W 60;
#define WALL_H 99;

int main()
{
    void *mlx;
    void *win;
    void *wall;
    void *platform;
    void *collectable;
    void *frisk;
    int w, h;
    int x, y, x0, y0;

    x = 0; y = 0;
    x0 = 0; y0 = 0;

    char *path = "./maps/flowerbed.ber";
    struct s_map map;
    if (!map_is_valid(path, &map))
        return (printf("Map is not valid."), 1);
    mlx = mlx_init();
    if (!mlx)
        return (printf("MLX init failed.\n"), 1);
    win = mlx_new_window(mlx, 9000, 9000, "so_long.xd");
    if (!win)
        return(printf("Windows creation fault.\n"), 1);
    wall = mlx_xpm_file_to_image(mlx, "./textures/wall.xpm", &w, &h);
    platform = mlx_xpm_file_to_image(mlx, "./textures/platform3.xpm", &w, &h);
    collectable = mlx_xpm_file_to_image(mlx, "./textures/coll.xpm", &w, &h);
    frisk = mlx_xpm_file_to_image(mlx, "./textures/frisk/idle2.xpm", &w, &h);

    if (!wall || !platform || !collectable)
        return (printf("Image fetching failed.\n"), 1);
    while ((map.map)[y0])
    {
        while ((map.map)[y0][x0])
        {
            if ((map.map)[y0][x0] == '1')
                mlx_put_image_to_window(mlx, win, wall, x, y);
            else
                mlx_put_image_to_window(mlx, win, platform, x, y + 40);
            x = x + 60;
            x0 = x0 + 1;
        }
        y = y + 60;
        x = 0;
        x0 = 0;
        y0 = y0 + 1;
    }
    x = 0; y = 0;
    x0 = 0; y0 = 0;
    
    while ((map.map)[y0])
    {
        while ((map.map)[y0][x0])
        {
            if ((map.map)[y0][x0] == 'C')
                mlx_put_image_to_window(mlx, win, collectable, x + 17, y + 65);
            if ((map.map)[y0][x0] == 'P')
                mlx_put_image_to_window(mlx, win, frisk, x, y + 15);
            x = x + 60;
            x0 = x0 + 1;
        }
        y = y + 60;
        x = 0;
        x0 = 0;
        y0 = y0 + 1;
    }
    mlx_loop(mlx);
}
// mlx_put_image_to_window(mlx, win, img2, 120, 100);