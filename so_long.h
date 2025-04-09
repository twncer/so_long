/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:57:43 by btuncer           #+#    #+#             */
/*   Updated: 2025/02/27 19:09:55 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# define WIN_W 2048
# define WIN_H 720
# define GROUND_W 60
# define WALL_H 99
# define PLAYER_W 60
# define PLAYER_H 86
# define PLAYER_PPM 1// pixel per move
# define ATTACK_GAP 10
# define KEY_D 100
# define KEY_A 97
# define KEY_W 119
# define KEY_S 115
# define KEY_ESC 65307

struct						s_position
{
	unsigned int			x;
	unsigned int			y;
};

struct						s_map
{
	bool is_rect;        // remove later
	bool is_walls_valid; // remove later
	bool is_solveable;   // replace it with is_valid
	char					**map;
	unsigned int			height;
	unsigned int			width;
	struct s_position start_pos; // remove later
	struct s_position		current_pos;
	struct s_position		exit_pos;
	void					*exit_image;
	void					*enemy_image;
	void	*pellet_image;
	int collectibles_left;
};

struct						s_images
{
	void					*wall;
	void					*ground;
	void *exit[3];
	void *star[3];
	void *player[5][2];
	void *flowey[2];
	void *pellets[2];
	void *collectible;
	void *seq_images[1];
};

struct						s_player
{
	struct s_position position; // ayak pozisyonu
	void					*image;
	unsigned int			moves_px;
	// s_player_images top;
	// s_player_images right;
	// s_player_images bottom;
	// s_player_images left;
};

struct						s_mlx
{
	void					*mlx;
	void					*win;
};

struct						s_key_listener
{
	bool					key_w;
	bool					key_a;
	bool					key_s;
	bool					key_d;
};

struct						s_eventpkg
{
	struct s_mlx			mlx;
	struct s_player			player;
	struct s_map			map;
	struct s_key_listener	key_list;
	struct s_images			images;
};

long long current_time_ms();
void terminate(struct s_eventpkg *evpkg);

#endif