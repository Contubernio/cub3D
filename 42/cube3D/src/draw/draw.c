/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:36:09 by albealva          #+#    #+#             */
/*   Updated: 2025/06/14 20:56:24 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	draw_sky(t_game *game)
{
	int	sky_color;
	int	y;
	int	x;

	sky_color = game->data->ceiling;
	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			game->img_data[y * WIN_WIDTH + x] = sky_color;
			x++;
		}
		y++;
	}
}

static void	draw_ground(t_game *game)
{
	int	ground_color;
	int	y;
	int	x;

	ground_color = game->data->floor;
	y = WIN_HEIGHT / 2;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			game->img_data[y * WIN_WIDTH + x] = ground_color;
			x++;
		}
		y++;
	}
}

void	draw_background(t_game *game)
{
	draw_sky(game);
	draw_ground(game);
}

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		game->img_data[y * WIN_WIDTH + x] = color;
	}
}
