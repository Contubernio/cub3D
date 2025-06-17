/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:47:09 by albealva          #+#    #+#             */
/*   Updated: 2025/06/15 01:18:36 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	draw_fullscreen_color(t_game *game, int color)
{
	int	i;
	int	total_pixels;

	i = 0;
	total_pixels = WIN_WIDTH * WIN_HEIGHT;
	while (i < total_pixels)
	{
		game->img_data[i] = color;
		i++;
	}
}

void	transition_from_splash_to_intro(t_game *game)
{
	printf("--- Splash screen finished. Starting intro sequence... ---\n");
	cleanup_intro_assets(game);
	if (parse_and_validate_map(game, "maps/intro.cub") != 0)
		clean_exit(game, "Error: Failed to load intro map.");
	if (initialize_graphics(game) != 0)
		clean_exit(game, "Error: Failed to init graphics for intro.");
	game->game_state = STATE_INTRO;
	gettimeofday(&game->intro_timer, NULL);
}

void	update_splash_sequence(t_game *game)
{
	struct timeval	now;
	double			elapsed_seconds;
	int				x;
	int				y;

	if (game->intro_screen.data)
	{
		y = 0;
		while (y < game->intro_screen.height && y < WIN_HEIGHT)
		{
			x = 0;
			while (x < game->intro_screen.width && x < WIN_WIDTH)
			{
				game->img_data[y * WIN_WIDTH + x] = game->intro_screen.data[y
					* (game->intro_screen.line_length / 4) + x];
				x++;
			}
			y++;
		}
	}
	gettimeofday(&now, NULL);
	elapsed_seconds = (now.tv_sec - game->intro_timer.tv_sec) + (now.tv_usec
			- game->intro_timer.tv_usec) / 1000000.0;
	if (elapsed_seconds >= 3.0)
		transition_from_splash_to_intro(game);
}

void	perform_game_transition(t_game *game)
{
	cleanup_map_assets(game);
	init_parser_data_structures(game);
	printf("\n--- Loading Main Level ---\n");
	if (parse_and_validate_map(game, game->original_map_path) != 0)
		clean_exit(game, "Error: Failed to load main map during transition.");
	if (init_textures_and_hands(game) != 0 || init_player(game) != 0)
		clean_exit(game, "Error: Failed to init graphics for main map.");
	game->game_state = STATE_PLAYING;
	printf("--- Level Start! ---\n");
}

void	print_intro(int is_bonus)
{
	printf("\n");
	printf("  ██████╗ ██╗   ██╗██████╗ ███████╗█████╗ ██████╗ \n");
	printf("  ██╔═══╝ ██║   ██║██╔══██╗██╔════╝════██╗██   ██╗\n");
	printf("  ██║     ██║   ██║██████╔╝█████╗  ██████║██   ██║ \n");
	printf("  ██╚═══╗ ██║   ██║██╔══██╗██╔══╝      ██╝██   ██║ \n");
	printf("  ██████║ ╚██████╔╝██████╔╝███████╗█████║ ██████╔╝     \n");
	printf("  ╚═════╝  ╚═════╝ ╚═════╝ ╚══════╝╚════╝ ╚═════╝     \n");
	printf("\n");
	printf("        Bienvenido a cub3D: ¡Explora y sobrevive!\n");
	printf("\n");
	printf(" Controles:\n");
	printf("  - W, A, S, D     → Mover al jugador\n");
	printf("  - ←, →           → Rotar la cámara\n");
	printf("  - ESC            → Salir del juego\n");
	if (is_bonus)
	{
		printf("  - Ratón          → Rotación adicional de cámara\n");
		printf("  - ESPACIO        → Interactuar con puertas\n");
	}
	printf("\n¡Buena suerte, aventurero!\n\n");
}
