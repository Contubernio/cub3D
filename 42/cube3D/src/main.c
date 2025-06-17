/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:18:54 by gasroman          #+#    #+#             */
/*   Updated: 2025/06/17 15:11:52 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
#include <fcntl.h>
#include <stdio.h>

static int	init_all_systems(t_game *game)
{
	if (initialize_core_systems(game) != 0)
		return (1);
	if (init_mlx(game) != 0)
		return (1);
	if (init_images(game) != 0)
		return (1);
	return (0);
}

static int	start_game_logic(t_game *game)
{
	int	status;

	print_intro(BONUS);
	status = 0;
	if (BONUS)
		status = start_game_bonus(game);
	else
		status = start_game_mandatory(game);
	return (status);
}

static void	setup_mouse(t_game *game)
{
	int	mouse_x;
	int	mouse_y;

	mlx_mouse_get_pos(game->mlx_ptr, game->win_ptr, &mouse_x, &mouse_y);
	center_mouse(game);
	game->william.mouse_x = mouse_x;
}

static int	initialize_game(t_game *game, int argc, char **argv)
{
	if (check_program_arguments(argc, argv) != 0)
		return (1);
	game->original_map_path = ft_strdup(argv[1]);
	if (!game->original_map_path)
		return (1);
	if (init_all_systems(game) != 0)
		return (1);
	if (start_game_logic(game) != 0)
		return (1);
	setup_mouse(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (initialize_game(&game, argc, argv) != 0)
	{
		destroy_images(&game);
		cleanup_core_resources(&game);
		return (1);
	}
	game_loop(&game);
	return (0);
}
