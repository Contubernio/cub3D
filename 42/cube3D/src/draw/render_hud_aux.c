/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hud_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:59:14 by albealva          #+#    #+#             */
/*   Updated: 2025/06/14 22:01:51 by contubernio      ###   ########.fr       */
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

static void	draw_sprite_row(t_game *game, t_texture *sprite, int y,
		t_point offset)
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

void	render_hud(t_game *game)
{
	t_point	offset;

	if (!game->hud)
		return ;
	offset.x = 1300;
	offset.y = 450;
	draw_sprite(game, &game->hud[0], offset);
}

void	render_m1(t_game *game)
{
	t_point	offset;

	if (!game->hud)
		return ;
	offset.x = 600;
	offset.y = 800;
	draw_sprite(game, &game->hud[1], offset);
}
