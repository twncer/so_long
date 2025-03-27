#include "so_long.h"

void terminate(struct s_eventpkg *evpkg)
{
    free(evpkg->map.map);
    mlx_destroy_window(evpkg->mlx.mlx, evpkg->mlx.win);
    mlx_destroy_display(evpkg->mlx.mlx);
}