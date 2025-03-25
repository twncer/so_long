#include "./../so_long.h"

void collect(struct s_eventpkg *evpkg)
{
    if (evpkg->map.map[(evpkg->player.position.y + 30) / 60][evpkg->player.position.x / 60] == 'C')
    {
        evpkg->map.collectibles_left--;
        evpkg->map.map[(evpkg->player.position.y + 30) / 60][evpkg->player.position.x / 60] = '0';
    }
}