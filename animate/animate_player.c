#include "./sl_animations.h"
#include "./../so_long.h"

void animate_player(struct s_eventpkg *evpkg)
{
    static short frame = 1;
}

void idleize_player(struct s_eventpkg *evpkg)
{
    evpkg->player.image = evpkg->images.player_idle;
}