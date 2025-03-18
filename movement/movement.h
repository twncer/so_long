/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:42:28 by btuncer           #+#    #+#             */
/*   Updated: 2025/02/14 21:58:22 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
# define MOVEMENT_H
char					move_top(struct s_map *map);
char					move_right(struct s_map *map);
char					move_bottom(struct s_map *map);
char					move_left(struct s_map *map);
bool					rec_walls(int way, unsigned int x, unsigned int y,
							char **map);
void init_keys(struct s_key_listener *key_list);
void key_pressed(int key, struct s_key_listener *key_list);
void key_released(int key, struct s_key_listener *key_list);
void move_player(struct s_eventpkg *evpkg);
#endif