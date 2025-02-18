/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:56:13 by btuncer           #+#    #+#             */
/*   Updated: 2025/02/19 00:50:56 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vendor/minilibx-linux/mlx.h"
#include "so_long.h"
#include "./map/sl_map.h"
#include "./render/render.h"
#include "./player/player.h"
#include "./movement/movement.h"
#include <stdio.h>

bool is_moving(bool set, bool to)
{
    static bool moving = false;
    if (set)
        moving = to;
    return (moving);
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
    
    if (evpkg->key_list.key_a || evpkg->key_list.key_d 
    || evpkg->key_list.key_w || evpkg->key_list.key_s)
        render(evpkg);
        
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
    
    printf("      W(%i)\nA(%i)  S(%i)  D(%i)\n\n", evpkg->key_list.key_w, evpkg->key_list.key_a, 
                                        evpkg->key_list.key_s, evpkg->key_list.key_d);
    printf("\nLocation: (%i:%i)[%i:%i]\n\n", evpkg->player.position.x, evpkg->player.position.y, 
                                            evpkg->player.position.x / 60, evpkg->player.position.y / 60);
    printf("\n\n[%c][%c][%c]\n[%c][P][%c]\n[%c][%c][%c]\n\n",
        evpkg->map.map[evpkg->player.position.y / 60 - 1][evpkg->player.position.x / 60 - 1],
        evpkg->map.map[evpkg->player.position.y / 60 - 1][evpkg->player.position.x / 60],
        evpkg->map.map[evpkg->player.position.y / 60 - 1][evpkg->player.position.x / 60 + 1],
        evpkg->map.map[evpkg->player.position.y / 60][evpkg->player.position.x / 60 - 1],
        /*evpkg->map.map[evpkg->player.position.y / 60][evpkg->player.position.x / 60],*/
        evpkg->map.map[evpkg->player.position.y / 60][evpkg->player.position.x / 60 + 1],
        evpkg->map.map[evpkg->player.position.y / 60 + 1][evpkg->player.position.x / 60 - 1],
        evpkg->map.map[evpkg->player.position.y / 60 + 1][evpkg->player.position.x / 60],
        evpkg->map.map[evpkg->player.position.y / 60 + 1][evpkg->player.position.x / 60 + 1]
    );
}
// mlx_destroy_window(eventpkg->mlx.mlx, eventpkg->mlx.win);

int main()
{
    char *path = "./maps/flowerbed.ber";
    
    struct s_mlx mlx;
    struct s_map map;
    struct s_player player;
    struct s_eventpkg eventpkg;
    struct s_key_listener key_list;
    
    int q;
    
    if (!map_is_valid(path, &map)) // also inits the map
        return (printf("Map is not valid."), 1);
    
    mlx.mlx = mlx_init();
    if (!mlx.mlx)
        return (printf("MLX init failed.\n"), 1);
    
    mlx.win = mlx_new_window(mlx.mlx, WIN_W, WIN_H, "so_long.xd");
    if (!mlx.win)
        return(printf("Window creation fault.\n"), 1);
        
    player = init_player(&map, mlx.mlx); // doesnt sets a player image, so should set it before rendering
    player.image = mlx_xpm_file_to_image(mlx.mlx, "./textures/frisk/idle2.xpm", &q, &q);
    
    eventpkg.mlx = mlx;
    eventpkg.player = player;
    eventpkg.map = map;
    eventpkg.key_list = key_list;
    
    printf("x %u, y %u\n", player.position.x / 60, player.position.y / 60);
    
    mlx_hook(mlx.win, 2, 1L<<0, onpress_event, &eventpkg); // onpress event
    mlx_hook(mlx.win, 3, 1L<<1, onrelease_event, &eventpkg); // onrelease event
    mlx_loop_hook(mlx.mlx, loop_event, &eventpkg);
    mlx_loop(mlx.mlx);
}
// mlx_string_put(mlx, win, 0, 10, 0xFFFFFF, "currently on: ground");