/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:51:20 by albealva          #+#    #+#             */
/*   Updated: 2025/05/23 08:41:48 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	init_mouse_data(t_game *game)
{
	game->last_mouse_x = 0.0;
	game->mouse_sensitivity = 0.0;
	game->mouse_in_border = 0;
	game->last_turn_direction = 0;
	game->mouse_data = NULL;
}

static void	init_door_data(t_game *game)
{
	game->doors_img_ptr[0] = NULL;
	game->doors_img_ptr[1] = NULL;
	game->doors_data[0] = NULL;
	game->doors_data[1] = NULL;
	game->doors_width = 0;
	game->doors_height = 0;
	game->doors_bits_per_pixel = 0;
	game->doors_line_length = 0;
	game->doors_endian = 0;
	game->current_door_frame = 0;
	game->door_animation_timer = 0;
	game->doors_x = 0;
	game->doors_y = 0;
	game->door_open = 0;
}

static void	init_hud_data(t_game *game)
{
	game->hands = NULL;
	game->hud = NULL;
	game->hud_x = 0;
	game->hud_y = 0;
	game->hud_message = false;
}

void	init_game3(t_game *game)
{
	init_main_pointers(game);
	init_minimap_data(game);
	init_img_render_data(game);
	init_hands_data(game);
	init_mouse_data(game);
	init_door_data(game);
	init_hud_data(game);
}
