/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:53:36 by albealva          #+#    #+#             */
/*   Updated: 2025/05/23 17:27:24 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_main_pointers(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->img_ptr = NULL;
	game->img_data = NULL;
	game->addr = NULL;
	game->map2 = NULL;
	game->textures = NULL;
	game->door_texture = NULL;
	game->img_ground = NULL;
	game->floor_color = 0;
	game->ceiling_color = 0;
}

void	init_minimap_data(t_game *game)
{
	game->minimap_img_ptr = NULL;
	game->minimap_img_data = NULL;
	game->minimap_bpp = 0;
	game->minimap_line_length = 0;
	game->minimap_endian = 0;
}

void	init_img_render_data(t_game *game)
{
	game->bits_per_pixel = 0;
	game->line_length = 0;
	game->endian = 0;
}

void	init_hands_data(t_game *game)
{
	game->hands_img_ptr[0] = NULL;
	game->hands_img_ptr[1] = NULL;
	game->hands_data[0] = NULL;
	game->hands_data[1] = NULL;
	game->hands_width = 0;
	game->hands_height = 0;
	game->hands_bits_per_pixel = 0;
	game->hands_line_length = 0;
	game->hands_endian = 0;
	game->current_hand_frame = 0;
	game->hand_animation_timer = 0;
	game->hands_x = 0;
	game->hands_y = 0;
}
