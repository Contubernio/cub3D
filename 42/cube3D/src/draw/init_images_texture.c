/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:04:40 by albealva          #+#    #+#             */
/*   Updated: 2025/06/13 21:15:58 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	init_images(t_game *game)
{
	game->img_ptr = mlx_new_image(game->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	game->img_data = (int *)mlx_get_data_addr(game->img_ptr,
			&game->bits_per_pixel, &game->line_length, &game->endian);
	if (!game->img_data)
		return (clean_exit(game,
				"Error: Failed to get main image data address."));
	game->img_ground = malloc(sizeof(struct s_img));
	if (!game->img_ground)
		return (clean_exit(game,
				"Error: Failed to allocate memory for ground image."));
	game->img_ground->img_ptr = mlx_new_image(game->mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT);
	if (!game->img_ground->img_ptr)
		return (clean_exit(game, "Error: Failed to create sky_floor image."));
	game->img_ground->addr = mlx_get_data_addr(game->img_ground->img_ptr,
			&game->img_ground->bits_per_pixel, &game->img_ground->line_length,
			&game->img_ground->endian);
	if (!game->img_ground->addr)
		return (clean_exit(game,
				"Error: Failed to get sky_floor image data address."));
	return (0);
}

int	allocate_game_assets_pre(t_game *game)
{
	game->textures = malloc(5 * sizeof(t_texture));
	if (!game->textures)
		return (clean_exit(game,
				"Error: Failed to allocate memory for textures."));
	game->door_texture = malloc(2 * sizeof(t_texture));
	if (!game->door_texture)
		return (clean_exit(game,
				"Error: Failed to allocate memory for doors."));
	game->hands = malloc(5 * sizeof(t_texture));
	if (!game->hands)
		return (clean_exit(game, "Error: Fail allocate memory for hands."));
	game->hud = malloc(5 * sizeof(t_texture));
	if (!game->hud)
		return (clean_exit(game, "Error: Fail allocate memory for hud."));
	return (0);
}

static int	allocate_game_assets(t_game *game)
{
	game->textures = malloc(5 * sizeof(t_texture));
	if (!game->textures)
		return (clean_exit(game,
				"Error: Failed to allocate memory for textures."));
	game->door_texture = malloc(2 * sizeof(t_texture));
	if (!game->door_texture)
		return (clean_exit(game,
				"Error: Failed to allocate memory for doors."));
	game->hands = malloc(5 * sizeof(t_texture));
	if (!game->hands)
		return (clean_exit(game,
				"Error: Failed to allocate memory for hands."));
	game->hud = malloc(5 * sizeof(t_texture));
	if (!game->hud)
		return (clean_exit(game, "Error: Failed to allocate memory for hud."));
	return (0);
}

static int	load_game_assets(t_game *game)
{
	if (load_textures_hud(game) != 0)
		return (clean_exit(game, "Error: Failed to load textures_hud."));
	if (load_textures(game) != 0)
		return (clean_exit(game, "Error: Failed to load textures."));
	if (load_hands_images(game) != 0)
		return (clean_exit(game, "Error: Failed to load hands images."));
	if (load_door_images(game) != 0)
		return (clean_exit(game, "Error: Failed to load door images."));
	if (load_mask_images(game) != 0)
		return (clean_exit(game, "Error: Failed to load door images."));
	game->hands_x = 00;
	game->hands_y = 00;
	game->current_hand_frame = 0;
	game->hand_animation_timer = 0;
	game->william.playerangle = atan2(game->william.dir_y, game->william.dir_x);
	game->hud_x = 0;
	game->hud_y = 600;
	return (0);
}

int	init_textures_and_hands(t_game *game)
{
	if (allocate_game_assets(game) != 0)
		return (1);
	if (load_game_assets(game) != 0)
		return (1);
	return (0);
}
