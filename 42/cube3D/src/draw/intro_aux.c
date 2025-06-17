/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:17:44 by albealva          #+#    #+#             */
/*   Updated: 2025/06/14 21:19:43 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	update_intro_sequence(t_game *game)
{
	struct timeval	now;
	double			elapsed_seconds;

	gettimeofday(&now, NULL);
	elapsed_seconds = (now.tv_sec - game->intro_timer.tv_sec) + (now.tv_usec
			- game->intro_timer.tv_usec) / 1000000.0;
	if (elapsed_seconds >= 5.0)
	{
		game->game_state = STATE_TRANSITION;
	}
}

static void	free_map_data(t_data *data)
{
	if (!data)
		return ;
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->map)
		free_char_array(data->map);
	free(data);
}

static void	free_texture_arrays(t_game *game)
{
	if (game->textures)
	{
		free(game->textures);
		game->textures = NULL;
	}
	if (game->door_texture)
	{
		free(game->door_texture);
		game->door_texture = NULL;
	}
	if (game->hands)
	{
		free(game->hands);
		game->hands = NULL;
	}
	if (game->hud)
	{
		free(game->hud);
		game->hud = NULL;
	}
	game->mask.img_ptr = NULL;
}

void	cleanup_map_assets(t_game *game)
{
	if (!game)
		return ;
	destroy_loaded_images(game);
	free_texture_arrays(game);
	free_map_data(game->data);
	game->data = NULL;
}

void	cleanup_intro_assets(t_game *game)
{
	if (game->intro_screen.img_ptr)
	{
		mlx_destroy_image(game->mlx_ptr, game->intro_screen.img_ptr);
		game->intro_screen.img_ptr = NULL;
	}
}
