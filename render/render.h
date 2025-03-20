/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:11:07 by btuncer           #+#    #+#             */
/*   Updated: 2025/02/19 07:53:34 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

void render(struct s_eventpkg *evpkg);
struct s_images init_images(struct s_mlx *mlx);
void render_exit(struct s_eventpkg *evpkg);
void render_enemy(struct s_eventpkg *evpkg);
long camera_move_x(long set);
long camera_move_y(long set);
void put_img(struct s_mlx *mlx, void *image, unsigned int x, unsigned int y);

#endif