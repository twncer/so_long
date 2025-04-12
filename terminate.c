#include "so_long.h"
#include "./vendor/minilibx-linux/mlx.h"
#include "render/render.h"
#include <stdlib.h>

void free_map(char **map)
{
    int y;

    y = 0;
    while (map[y])
    {
        free(map[y]);
        y++;
    }
    free(map);
}

void terminate(struct s_eventpkg *evpkg)
{
    free_images(evpkg);
    
    /* mlx_destroy_image(evpkg->mlx.mlx, evpkg->map.exit_image);
    mlx_destroy_image(evpkg->mlx.mlx, evpkg->map.pellet_image);
    mlx_destroy_image(evpkg->mlx.mlx, evpkg->map.enemy_image);
    mlx_destroy_image(evpkg->mlx.mlx, evpkg->player.image); */
    evpkg->player.image = NULL;
    free_map(evpkg->map.map);
    mlx_destroy_window(evpkg->mlx.mlx, evpkg->mlx.win);
    mlx_destroy_display(evpkg->mlx.mlx);
    free(evpkg->mlx.mlx);
    exit(0);
}
