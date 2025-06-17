/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:50:10 by albealva          #+#    #+#             */
/*   Updated: 2025/06/14 21:07:41 by contubernio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_william(t_william *william)
{
	william->x = 0.0;
	william->y = 0.0;
	william->dir_x = 0.0;
	william->dir_y = 0.0;
	william->plane_x = 0.0;
	william->plane_y = 0.0;
	william->fov = 0.0;
	william->playerangle = 0.0;
	william->turndirection = 0;
	william->release_mouse = 0;
	william->mouse_x = 0;
	william->last_mouse_x = 0;
}

void	initialize_game_struct(t_game *game)
{
	init_william(&game->william);
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->img_ptr = NULL;
	game->img_data = NULL;
	game->minimap_img_ptr = NULL;
	game->minimap_img_data = NULL;
	game->map2 = NULL;
	game->textures = NULL;
	game->door_texture = NULL;
	game->keys.space = 0;
	game->keys.space_pressed = 0;
	game->door_open = 0;
}
