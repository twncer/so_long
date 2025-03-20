#include "./../so_long.h"
#include "./../render/render.h"

void shoot(struct s_eventpkg *evpkg)
{
    static int attack_phase = 0;
    struct s_position pos;
    static long long frame_log_time = 0;
    long long time_h;

    pos.x = 0;
    pos.y = 0;
    while (evpkg->map.map[pos.y])
    {
        while (evpkg->map.map[pos.y][pos.x])
        {
            if (evpkg->map.map[pos.y][pos.x] == 'F')
            {
                put_img(&(evpkg->mlx), evpkg->map.palette_image, (pos.x * 60) - attack_phase * ATTACK_GAP, pos.y * 60 + 20);
                put_img(&(evpkg->mlx), evpkg->map.palette_image, (pos.x * 60) + attack_phase * ATTACK_GAP + 60, pos.y * 60 + 20);
            }
            pos.x++;
        }
        pos.x = 0;
        pos.y++;
    }
    
    time_h = current_time_ms();
    if (time_h - frame_log_time > 150)
    {
        if (attack_phase == 7)
            attack_phase = 0;
        else
            attack_phase++;
        frame_log_time = time_h;
    }
}