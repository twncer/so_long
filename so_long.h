/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:57:43 by btuncer           #+#    #+#             */
/*   Updated: 2025/02/18 01:29:24 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#define WIN_W 2048
#define WIN_H 720
#define GROUND_W 60
#define WALL_H 99
#define PLAYER_W 60
#define PLAYER_H 86
#define PLAYER_PPM 1 // pixel per move
#define KEY_D 100
#define KEY_A 97
#define KEY_W 119
#define KEY_S 115

struct						s_position
{
	unsigned int			x;
	unsigned int			y;
};

struct						s_map
{
	bool					is_rect;
	bool					is_walls_valid;
	bool					is_solveable;
	char					**map;
	unsigned int			height;
	unsigned int			width;
	struct s_position		start_pos;
	struct s_position		current_pos;
};

struct						s_images
{
	void					*wall;
	void					*ground;
};

struct						s_player
{
	struct s_position position; // ayak pozisyonu
	void					*image;
	unsigned int			moves_px;
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
};