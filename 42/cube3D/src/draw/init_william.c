/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_william.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:02:11 by albealva          #+#    #+#             */
/*   Updated: 2025/06/12 20:55:24 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	set_player_direction(t_game *game, char dir)
{
	if (dir == 'N')
	{
		game->william.dir_x = 0.0;
		game->william.dir_y = -1.0;
	}
	else if (dir == 'S')
	{
		game->william.dir_x = 0.0;
		game->william.dir_y = 1.0;
	}
	else if (dir == 'E')
	{
		game->william.dir_x = 1.0;
		game->william.dir_y = 0.0;
	}
	else if (dir == 'W')
	{
		game->william.dir_x = -1.0;
		game->william.dir_y = 0.0;
	}
	game->william.plane_x = -game->william.dir_y * tan(game->william.fov / 2.0);
	game->william.plane_y = game->william.dir_x * tan(game->william.fov / 2.0);
}

int	init_player_pre(t_game *game)
{
	int	x;
	int	y;

	game->william.fov = FOV * M_PI / 180.0;
	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			if (ft_strchr("NSEW", game->worldmap[y][x]))
			{
				game->william.x = x + 0.5;
				game->william.y = y + 0.5;
				set_player_direction(game, game->worldmap[y][x]);
				game->map[y][x] = '0';
				return (0);
			}
			x++;
		}
		y++;
	}
	return (clean_exit(game,
			"Error: No valid player starting position found."));
}

int	init_player(t_game *game)
{
	int	x;
	int	y;

	game->william.fov = FOV * M_PI / 180.0;
	y = 0;
	while (y < game->data->map_height)
	{
		x = 0;
		while (x < game->data->map_width)
		{
			if (ft_strchr("NSEW", game->data->map[y][x]))
			{
				game->william.x = x + 0.5;
				game->william.y = y + 0.5;
				set_player_direction(game, game->data->map[y][x]);
				game->data->map[y][x] = '0';
				return (0);
			}
			x++;
		}
		y++;
	}
	return (clean_exit(game,
			"Error: No valid player starting position found."));
}
