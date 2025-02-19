/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:53:32 by btuncer           #+#    #+#             */
/*   Updated: 2025/02/19 06:57:13 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void init_keys(struct s_key_listener *key_list)
{
    key_list->key_w = false;
    key_list->key_a = false;
    key_list->key_s = false;
    key_list->key_d = false;
}

void key_pressed(int key, struct s_key_listener *key_list)
{
    if (key == KEY_W)
        key_list->key_w = true;
    else if (key == KEY_A)
        key_list->key_a = true;
    else if (key == KEY_S)
        key_list->key_s = true;
    else if (key == KEY_D)
        key_list->key_d = true;
}

void key_released(int key, struct s_key_listener *key_list)
{
    if (key == KEY_W)
        key_list->key_w = false;
    else if (key == KEY_A)
        key_list->key_a = false;
    else if (key == KEY_S)
        key_list->key_s = false;
    else if (key == KEY_D)
        key_list->key_d = false;
}