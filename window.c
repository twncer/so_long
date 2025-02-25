/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:56:13 by btuncer           #+#    #+#             */
/*   Updated: 2025/02/19 08:00:10 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vendor/minilibx-linux/mlx.h"
#include "so_long.h"
#include "./map/sl_map.h"
#include "./render/render.h"
#include "./player/player.h"
#include "./movement/movement.h"
#include <stdio.h>
#include <sys/time.h>

bool is_moving(bool set, bool to)
{
    static bool moving = false;
    if (set)
        moving = to;
    return (moving);
}

long long current_time_ms()
{
    struct timeval tval;
    gettimeofday(&tval, NULL);
    return (long long)(tval.tv_sec) * 1000 + (tval.tv_usec) / 1000;
}

int onpress_event(int key, struct s_eventpkg *evpkg)
{
    key_pressed(key, &(evpkg->key_list));
}

int onrelease_event(int key, struct s_eventpkg *evpkg)
{
    int q;
    
    if (evpkg->player.image != mlx_xpm_file_to_image(evpkg->mlx.mlx, "./textures/frisk/idle2.xpm", &q, &q))
        evpkg->player.image = mlx_xpm_file_to_image(evpkg->mlx.mlx, "./textures/frisk/idle2.xpm", &q, &q);
    key_released(key, &(evpkg->key_list));
}

int loop_event(struct s_eventpkg *evpkg)
{
    int q;
    static int star_animation = 1;
    static int flowey_animation = 1;
    static long long star_last_time = 0;
    static long long flowey_last_time = 0;
    long long time_h;
    
    /* movement */
    if (evpkg->key_list.key_a || evpkg->key_list.key_d 
    || evpkg->key_list.key_w || evpkg->key_list.key_s) // render if just player moves
    {
        render(evpkg);
    }
    if (evpkg->key_list.key_d && evpkg->map.map[evpkg->player.position.y / 60][evpkg->player.position.x / 60 + 1] != '1')
    {
        evpkg->player.image = mlx_xpm_file_to_image(evpkg->mlx.mlx, "./textures/frisk/walk_right/frame1.xpm", &q, &q);
        evpkg->player.position.x += PLAYER_PPM;
    }
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

    /* star animation */
    time_h = current_time_ms();
    if (time_h % 600 == 0) // every 400ms
    {
        if (!(star_last_time + 599 > time_h))
        {
            if (star_animation == 1)
            {
                evpkg->map.exit_image = mlx_xpm_file_to_image(evpkg->mlx.mlx, "./textures/star/star2.xpm", &q, &q);
                star_animation = 2;
            } else if (star_animation == 2) {
                evpkg->map.exit_image = mlx_xpm_file_to_image(evpkg->mlx.mlx, "./textures/star/star3.xpm", &q, &q);
                star_animation = 3;   
            } else {
                evpkg->map.exit_image = mlx_xpm_file_to_image(evpkg->mlx.mlx, "./textures/star/star1.xpm", &q, &q);
                star_animation = 1;  
            }
            star_last_time = time_h;
            render_exit(evpkg); // render only exit
        }
    }
    if (time_h % 500 == 0)
    {
        if (!(flowey_last_time + 499 > time_h))
        {
            if (flowey_animation == 1)
            {
                evpkg->map.enemy_image = mlx_xpm_file_to_image(evpkg->mlx.mlx, "./textures/flowey/flowey2.xpm", &q, &q);
                flowey_animation = 2;
            } else if (flowey_animation == 2)
            {
                evpkg->map.enemy_image = mlx_xpm_file_to_image(evpkg->mlx.mlx, "./textures/flowey/flowey1.xpm", &q, &q);
                flowey_animation = 1;
            }
            flowey_last_time = time_h;
            render_enemy(evpkg);
        }
    }
    printf("(%i:%i)\n", evpkg->map.current_pos.x, evpkg->map.current_pos.y);
}
// mlx_destroy_window(eventpkg->mlx.mlx, eventpkg->mlx.win);

int main()
{
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
    
    mlx.win = mlx_new_window(mlx.mlx, WIN_W, WIN_H, "so_long.xd");
    if (!mlx.win)
        return(printf("Window creation fault.\n"), 1);
        
    player = init_player(&map, mlx.mlx);
    images = init_images(mlx.mlx);
    
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
}
// mlx_string_put(mlx, win, 0, 10, 0xFFFFFF, "currently on: ground");

// bir sonraki gün (sanırım ayın 21'i) şunları yap:
// loop_event'in içindekileri ayır
// flowey'in ataklarını bitir
// ataklara değme, collectible'lara değme eventlerini yap
// yeter da
// map structunun içine ```bool enemies``` ekle boylece mapte enemy olup olmadığını-
// anlayıp ona göre animasyonu aktif edersin
// he bi de put_image falan bi fonksiyon yazıver