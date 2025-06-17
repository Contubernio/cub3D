/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:29:54 by albealva          #+#    #+#             */
/*   Updated: 2025/06/15 00:44:56 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	init_parser_data_structures(t_game *game)
{
	game->data = (t_data *)malloc(sizeof(t_data));
	if (game->data == NULL)
	{
		printf(ANSI_COLOR_RED "Error:" ANSI_COLOR_RESET " \
        Malloc failed for game->data in init_parser_data_structures\n");
		return (1);
	}
	game->data->no = NULL;
	game->data->so = NULL;
	game->data->we = NULL;
	game->data->ea = NULL;
	game->data->floor = -1;
	game->data->ceiling = -1;
	game->data->map = NULL;
	game->data->map_width = 0;
	game->data->map_height = 0;
	game->data->is_leaking = 0;
	return (0);
}

int	initialize_core_systems(t_game *game)
{
	init_game3(game);
	initialize_game_struct(game);
	if (init_parser_data_structures(game) != 0)
	{
		return (1);
	}
	printf(ANSI_COLOR_GREEN "Success:" ANSI_COLOR_RESET " \
    Game data structures initialized.\n");
	printf("         game.data pointer is: %p\n", (void *)game->data);
	if (game->data != NULL)
	{
		printf("         \
game.data->map initial value: %p\n", (void *)game->data->map);
	}
	printf("----------------------------------------------------\n");
	return (0);
}
