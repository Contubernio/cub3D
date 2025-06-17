/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:23:56 by albealva          #+#    #+#             */
/*   Updated: 2025/06/14 21:04:49 by contubernio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	destroy_images(t_game *game);

void	clean_exit_mandatory(t_game *game)
{
	printf("--- Limpiando en modo OBLIGATORIO ---\n");
	destroy_images(game);
	cleanup_core_resources(game);
}

void	clean_exit_bonus(t_game *game)
{
	printf("--- Limpiando en modo BONUS ---\n");
	if (game->game_state == STATE_SPLASH)
		cleanup_intro_assets(game);
	else if (game->game_state == STATE_INTRO
		|| game->game_state == STATE_PLAYING)
	{
		cleanup_map_assets(game);
	}
	destroy_images(game);
	cleanup_core_resources(game);
}

int	clean_exit(void *param, char *msg)
{
	t_game	*game;

	game = (t_game *)param;
	if (!game)
		exit(1);
	printf("clean_exit: msg = %s\n", msg);
	if (BONUS)
		clean_exit_bonus(game);
	else
		clean_exit_mandatory(game);
	exit(0);
	return (0);
}

void	destroy_images(t_game *game)
{
	if (!game || !game->mlx_ptr)
		return ;
	if (game->img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->img_ptr);
	if (game->img_ground)
	{
		if (game->img_ground->img_ptr)
			mlx_destroy_image(game->mlx_ptr, game->img_ground->img_ptr);
		free(game->img_ground);
	}
}
