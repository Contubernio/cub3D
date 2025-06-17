/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 01:33:58 by albealva          #+#    #+#             */
/*   Updated: 2025/06/15 01:43:51 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	close_hook(void *param)
{
	return (clean_exit(param, "Ventana cerrada"));
}

int	game_loop(t_game *game)
{
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, key_release, game);
	mlx_loop_hook(game->mlx_ptr, update_and_render, game);
	mlx_hook(game->win_ptr, 17, 0, close_hook, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}

int	start_game_mandatory(t_game *game)
{
	printf(ANSI_COLOR_YELLOW "[MODO OBLIGATORIO]\n" ANSI_COLOR_RESET);
	if (parse_and_validate_map(game, game->original_map_path) != 0)
		return (1);
	if (initialize_graphics(game) != 0)
		return (1);
	game->game_state = STATE_PLAYING;
	return (0);
}

int	start_game_bonus(t_game *game)
{
	printf(ANSI_COLOR_YELLOW "[MODO BONUS ACTIVADO]\n" ANSI_COLOR_RESET);
	game->intro_screen.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./img/xpm/intro.xpm", &game->intro_screen.width,
			&game->intro_screen.height);
	if (!game->intro_screen.img_ptr)
		return (1);
	game->intro_screen.data = (int *)mlx_get_data_addr(
			game->intro_screen.img_ptr,
			&game->intro_screen.bits_per_pixel,
			&game->intro_screen.line_length,
			&game->intro_screen.endian);
	game->game_state = STATE_SPLASH;
	gettimeofday(&game->intro_timer, NULL);
	return (0);
}
