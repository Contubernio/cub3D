/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:43:09 by albealva          #+#    #+#             */
/*   Updated: 2025/06/13 21:21:32 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	load_door_images_pre(t_game *game)
{
	char	*texture_paths[2];
	int		i;

	texture_paths[0] = "./img/xpm/map1/door.xpm";
	texture_paths[1] = "./img/xpm/map1/opendoor.xpm";
	i = 0;
	while (i < 5)
	{
		game->door_texture[i].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
				texture_paths[i], &game->door_texture[i].width,
				&game->door_texture[i].height);
		if (!game->door_texture[i].img_ptr)
			return (clean_exit(game, "Error: Failed to load HUD texture."));
		game->door_texture[i].data
			= (int *)mlx_get_data_addr(game->door_texture[i].img_ptr,
				&game->door_texture[i].bits_per_pixel,
				&game->door_texture[i].line_length,
				&game->door_texture[i].endian);
		if (!game->door_texture[i].data)
			return (clean_exit(game,
					"Error: Failed to get HUD texture data address."));
		i++;
	}
	return (0);
}

static int	load_texture_data(t_game *game, int i)
{
	game->textures[i].data = (int *)mlx_get_data_addr(game->textures[i].img_ptr,
			&game->textures[i].bits_per_pixel, &game->textures[i].line_length,
			&game->textures[i].endian);
	if (!game->textures[i].data)
		return (clean_exit(game, "Error: Failed to get texture data address."));
	return (0);
}

int	load_textures(t_game *game)
{
	char	*texture_paths[5];
	int		i;

	i = 0;
	texture_paths[0] = game->data->no;
	texture_paths[1] = game->data->so;
	texture_paths[2] = game->data->we;
	texture_paths[3] = game->data->ea;
	texture_paths[4] = game->data->no;
	while (i < 5)
	{
		game->textures[i].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
				texture_paths[i], &game->textures[i].width,
				&game->textures[i].height);
		if (!game->textures[i].img_ptr)
			return (clean_exit(game, "Error: Failed to load texture."));
		if (load_texture_data(game, i) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	load_textures_hud(t_game *game)
{
	char	*texture_paths[5];
	int		i;

	texture_paths[0] = "./img/xpm/hud/800x600/mensaje11.xpm";
	texture_paths[1] = "./img/xpm/hud/800x600/mensaje22.xpm";
	texture_paths[2] = "./img/xpm/m2.xpm";
	texture_paths[3] = "./img/xpm/m3.xpm";
	texture_paths[4] = "./img/xpm/hud.xpm";
	i = 0;
	while (i < 5)
	{
		game->hud[i].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
				texture_paths[i], &game->hud[i].width, &game->hud[i].height);
		if (!game->hud[i].img_ptr)
			return (clean_exit(game, "Error: Failed to load HUD texture."));
		game->hud[i].data = (int *)mlx_get_data_addr(game->hud[i].img_ptr,
				&game->hud[i].bits_per_pixel, &game->hud[i].line_length,
				&game->hud[i].endian);
		if (!game->hud[i].data)
			return (clean_exit(game,
					"Error: Failed to get HUD texture data address."));
		i++;
	}
	return (0);
}
