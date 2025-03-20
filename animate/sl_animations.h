#ifndef ANIMATIONS_H
# define ANIMATIONS_H
# include <sys/time.h>
# include "./../so_long.h"

void animate_flowey(struct s_eventpkg *evpkg);
void animate_player(struct s_eventpkg *evpkg);
void idleize_player(struct s_eventpkg *evpkg);
void animate_palette(struct s_eventpkg *evpkg);

#endif