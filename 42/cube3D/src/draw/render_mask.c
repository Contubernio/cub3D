/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mask.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:06:17 by albealva          #+#    #+#             */
/*   Updated: 2025/06/15 12:38:58 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	put_pixel_to_img(t_game *game, int x, int y, unsigned int color)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		game->img_data[y * WIN_WIDTH + x] = color;
	}
}

static void	draw_sprite_row(t_game *game, t_texture *sprite,
	int y, t_point offset)
{
	int				x;
	unsigned int	color;
	unsigned int	transparent_color;

	transparent_color = 0x00000000;
	x = 0;
	while (x < sprite->width)
	{
		color = (unsigned int)sprite->data[y * (sprite->line_length / 4) + x];
		if (color != transparent_color)
		{
			put_pixel_to_img(game, x + offset.x, y + offset.y, color);
		}
		x++;
	}
}

static void	draw_sprite(t_game *game, t_texture *sprite, t_point offset)
{
	int	y;

	if (!sprite || !sprite->img_ptr || !sprite->data || !game->img_data)
		return ;
	y = 0;
	while (y < sprite->height)
	{
		draw_sprite_row(game, sprite, y, offset);
		y++;
	}
}

void	render_mask(t_game *game)
{
	t_point	offset;

	offset.x = 0;
	offset.y = 0;
	draw_sprite(game, &game->mask, offset);
}

/*
void	render_mask(t_game *game)
{
	int				x;
	int				y;
	unsigned int	color;
	unsigned int	transparent_color_key;
	int				draw_x;
	int				draw_y;

	if (!game->mask.img_ptr || !game->mask.data)
		return ;
	transparent_color_key = 0x000000;
	y = 0;
	while (y < game->mask.height)
	{
		x = 0;
		while (x < game->mask.width)
		{
			color = (unsigned int)game->mask.data[y * (game->mask.line_length
					/ 4) + x];
			if (color != transparent_color_key)
			{
				draw_x = x;
				draw_y = y;
				if (draw_x >= 0 && draw_x < WIN_WIDTH && draw_y >= 0
					&& draw_y < WIN_HEIGHT)
					game->img_data[draw_y * WIN_WIDTH + draw_x] = color;
			}
			x++;
		}
		y++;
	}
}*/
