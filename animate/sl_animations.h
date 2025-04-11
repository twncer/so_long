/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_animations.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:30:10 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/11 14:32:58 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_ANIMATIONS_H
# define SL_ANIMATIONS_H
# include "./../so_long.h"
# include <sys/time.h>

void	animate_flowey(struct s_eventpkg *evpkg);
void	animate_player(struct s_eventpkg *evpkg);
void	idleize_player(struct s_eventpkg *evpkg);
void	animate_palette(struct s_eventpkg *evpkg);
void	animate_exit(struct s_eventpkg *evpkg);

#endif