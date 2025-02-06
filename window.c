// cc window.c -Lminilibx-linux minilibx-linux/libmlx.a -lX11 -lXext -o a 

#include "./minilibx-linux/mlx.h"
#include <stdio.h>

int main()
{
    void *mlx;
    void *window;

    mlx = mlx_init();
    if (!mlx)
        return (printf("hataaaaa"), 1);
    window = mlx_new_window(mlx, 800, 600, "so_long.xd");
    if (!window)
        return(printf("windowhataaaa"), 1);
    mlx_loop(mlx);    
}