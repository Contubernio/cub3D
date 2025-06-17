/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:03:09 by albealva          #+#    #+#             */
/*   Updated: 2025/06/14 22:34:35 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (clean_exit(game, "Error: Failed to initialize MiniLibX."));
	if (BONUS)
	{
		game->win_ptr = mlx_new_window(game->mlx_ptr, SCREEN_WIDTH,
				SCREEN_HEIGHT, "cub3D");
		if (!game->win_ptr)
			return (clean_exit(game, "Error: Failed to create window."));
	}
	else
	{
		game->win_ptr = mlx_new_window(game->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
				"cub3D");
		if (!game->win_ptr)
			return (clean_exit(game, "Error: Failed to create window."));
	}
	return (0);
}

int	init_minimap(t_game *game)
{
	game->minimap_img_ptr = mlx_new_image(game->mlx_ptr, MINIMAP_WIDTH,
			MINIMAP_HEIGHT);
	game->minimap_img_data = (int *)mlx_get_data_addr(game->minimap_img_ptr,
			&game->minimap_bpp, &game->minimap_line_length,
			&game->minimap_endian);
	if (!game->minimap_img_data)
		return (clean_exit(game,
				"Error: Failed to get minimap image data address."));
	return (0);
}

int	init_map(t_game *game)
{
	game->map2 = game->worldmap;
	return (0);
}

int	init_keys(t_game *game)
{
	game->keys.w = 0;
	game->keys.s = 0;
	game->keys.a = 0;
	game->keys.d = 0;
	game->keys.left = 0;
	game->keys.right = 0;
	game->keys.esc = 0;
	game->keys.space = 0;
	game->keys.space_pressed = 0;
	return (0);
}

int	init_game(t_game *game)
{
	if (init_mlx(game) != 0)
		return (1);
	if (init_images(game) != 0)
		return (1);
	if (init_minimap(game) != 0)
		return (1);
	if (init_map(game) != 0)
		return (1);
	if (init_player(game) != 0)
		return (1);
	if (init_textures_and_hands(game) != 0)
		return (1);
	if (init_keys(game) != 0)
		return (1);
	return (0);
}
