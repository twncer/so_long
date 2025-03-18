#include "./sl_animations.h"
#include "./../so_long.h"

void animate_flowey(struct s_eventpkg *evpkg)
{
    static int frame = 0;
    static long long frame_log_time = 0;
    long long time_h;

    time_h = current_time_ms();
    if (time_h - frame_log_time > 400)
    {
        if (frame == 0)
            frame = 1;
        else if (frame == 1)
            frame = 0;
        frame_log_time = time_h;
    }
    evpkg->map.enemy_image = evpkg->images.flowey[frame];
}
