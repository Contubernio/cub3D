/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:23:13 by albealva          #+#    #+#             */
/*   Updated: 2025/06/14 20:54:42 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	destroy_image_array(void *mlx_ptr, t_texture *images, int count)
{
	int	i;

	if (!images)
		return ;
	i = 0;
	while (i < count)
	{
		if (images[i].img_ptr)
			mlx_destroy_image(mlx_ptr, images[i].img_ptr);
		i++;
	}
}

void	destroy_loaded_images(t_game *game)
{
	if (!game || !game->mlx_ptr)
		return ;
	destroy_image_array(game->mlx_ptr, game->textures, 5);
	destroy_image_array(game->mlx_ptr, game->door_texture, 2);
	destroy_image_array(game->mlx_ptr, game->hands, 5);
	destroy_image_array(game->mlx_ptr, game->hud, 5);
	if (game->mask.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->mask.img_ptr);
}

void	cleanup_core_resources(t_game *game)
{
	if (game->original_map_path)
		free(game->original_map_path);
	if (game->data != NULL)
	{
		if (game->data->no)
			free(game->data->no);
		if (game->data->so)
			free(game->data->so);
		if (game->data->we)
			free(game->data->we);
		if (game->data->ea)
			free(game->data->ea);
		if (game->data->map)
			free_char_array(game->data->map);
		free(game->data);
	}
	if (game->mlx_ptr)
	{
		if (game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
}
