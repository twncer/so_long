/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:56:13 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/12 02:14:38 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vendor/minilibx-linux/mlx.h"
#include "so_long.h"
#include "./map/sl_map.h"
#include "./render/render.h"
#include "./player/player.h"
#include "./movement/movement.h"
#include "./animate/sl_animations.h"
#include "./enemy_shoot/shoot.h"
#include "./collectibles/collectibles.h"
#include "./animate/sl_animations.h"
#include <stdio.h>
#include <sys/time.h>

long long current_time_ms()
{
    struct timeval tval;
    gettimeofday(&tval, NULL);
    return (long long)(tval.tv_sec) * 1000 + (tval.tv_usec) / 1000;
}

int onpress_event(int key, struct s_eventpkg *evpkg)
{
    if (key == KEY_ESC)
        terminate(evpkg);
    key_pressed(key, &(evpkg->key_list));
    return (0);
}

int onrelease_event(int key, struct s_eventpkg *evpkg)
{    
    key_released(key, &(evpkg->key_list));
    return (0);
}

int terminate_hook(struct s_eventpkg *evpkg)
{
    terminate(evpkg);
    return (0);
}

int loop_event(struct s_eventpkg *evpkg)
{
    animate_flowey(evpkg);
    animate_exit(evpkg);
    animate_palette(evpkg);
    
    render(evpkg);
    
    collect(evpkg);
    move_player(evpkg);
    shoot(evpkg);
    return (0);
}
// mlx_destroy_window(eventpkg->mlx.mlx, eventpkg->mlx.win);

int main(int argc, char **argv)
{
    struct s_key_listener key_list;
    struct s_eventpkg evpkg;
    
    if (!(argc == 2))
        return (1);
    init_keys(&key_list);
    if (!map_is_valid(argv[1], &evpkg.map))
        return (printf("Error!\nMap is not valid.\n"), 1);
    evpkg.mlx.mlx = mlx_init();
    if (!evpkg.mlx.mlx)
        return(printf("MLX initialization failed.\n"), 1);
    evpkg.mlx.win = mlx_new_window(evpkg.mlx.mlx, WIN_W, WIN_H, "so_long.xd");
    if (!evpkg.mlx.win)
        return(printf("Window creation failed.\n"), 1);
    evpkg.player = init_player(&evpkg.map);
    evpkg.key_list = key_list;
    evpkg.images = init_images(evpkg.mlx.mlx);
    evpkg.map.exit_image = evpkg.images.star[0];
    idleize_player(&evpkg);
    mlx_hook(evpkg.mlx.win, 2, 1L<<0, onpress_event, &evpkg); // onpress event
    mlx_hook(evpkg.mlx.win, 3, 1L<<1, onrelease_event, &evpkg); // onrelease event
    mlx_hook(evpkg.mlx.win, 17, 0, terminate_hook, &evpkg);
    mlx_loop_hook(evpkg.mlx.mlx, loop_event, &evpkg);
    render(&evpkg);
    mlx_loop(evpkg.mlx.mlx);
    /*
    char *path = "./maps/flowerbed_short.ber";
    
    struct s_mlx mlx;
    struct s_map map;
    struct s_player player;
    struct s_eventpkg eventpkg;
    struct s_key_listener key_list;
    struct s_images images;

    if (!map_is_valid(path, &map)) // also inits the map
        return (printf("Map is not valid."), 1);
    
    mlx.mlx = mlx_init();
    if (!mlx.mlx)
        return (printf("MLX init failed.\n"), 1);
    
    // mlx_do_key_autorepeatoff(mlx.mlx);

    mlx.win = mlx_new_window(mlx.mlx, WIN_W, WIN_H, "so_long.xd");
    if (!mlx.win)
        return(printf("Window creation fault.\n"), 1);
        
    player = init_player(&map, mlx.mlx);
    images = init_images(mlx.mlx);
    init_keys(&key_list);
    
    map.exit_image = images.star[0]; // AAAAAAAAAAAAAAAAA

    eventpkg.mlx = mlx;
    eventpkg.player = player;
    eventpkg.map = map;
    eventpkg.key_list = key_list;
    eventpkg.images = images;
    
    mlx_hook(mlx.win, 2, 1L<<0, onpress_event, &eventpkg); // onpress event
    mlx_hook(mlx.win, 3, 1L<<1, onrelease_event, &eventpkg); // onrelease event
    mlx_loop_hook(mlx.mlx, loop_event, &eventpkg);
    render(&eventpkg);
    mlx_loop(mlx.mlx);
    */
}
// mlx_string_put(mlx, win, 0, 10, 0xFFFFFF, "currently on: ground");

// bir sonraki gün (sanırım ayın 21'i) şunları yap:
// loop_event'in içindekileri ayır
// flowey'in ataklarını bitir
// ataklara değme, collectible'lara değme eventlerini yap
// yeter da
// map structunun içine ```bool enemies``` ekle boylece mapte enemy olup olmadığını-
// anlayıp ona göre animasyonu aktif edersin