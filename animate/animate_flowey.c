#include "./sl_animations.h"
#include "./../so_long.h"

void animate_flowey(struct s_eventpkg *evpkg)
{
    static int frame = 1;

    evpkg->map.enemy_image = evpkg->images.flowey[frame];
    frame++;
    if (frame >= 2)
        frame = 0;
}
