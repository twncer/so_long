#include "./sl_animations.h"
#include "./../so_long.h"

void animate_player(struct s_eventpkg *evpkg)
{
    static int frame = 0;
    static long long frame_log_time = 0;
    long long time_h;

    time_h = current_time_ms();
    if (time_h - frame_log_time > 300)
    {
        if (frame == 0)
            frame = 1;
        else if (frame == 1)
            frame = 0;
        frame_log_time = time_h; 
    }
    if (evpkg->key_list.key_w)
        evpkg->player.image = evpkg->images.player[1][frame];
    else if (evpkg->key_list.key_s)
        evpkg->player.image = evpkg->images.player[3][frame];
    else if (evpkg->key_list.key_a)
        evpkg->player.image = evpkg->images.player[4][frame];
    else if (evpkg->key_list.key_d)
        evpkg->player.image = evpkg->images.player[2][frame];
}

void idleize_player(struct s_eventpkg *evpkg)
{
    evpkg->player.image = evpkg->images.player[0][0];
}