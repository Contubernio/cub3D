/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:27:21 by albealva          #+#    #+#             */
/*   Updated: 2025/06/14 21:25:03 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	draw_minimap_cell(t_game *game, t_minimap *mini)
{
	calculate_minimap_coords(mini);
	if (mini->map_x >= 0 && mini->map_x \
	<= game->data->map_width && mini->map_y >= 0
		&& mini->map_y <= game->data->map_height)
		set_minimap_cell_color(game, mini);
	else
		mini->color = BLACK;
	mini->i = 0;
	while (mini->i < mini->cell_size)
	{
		mini->j = 0;
		while (mini->j < mini->cell_size)
		{
			my_mlx_pixel_put(game, mini->pixel_x + mini->i, mini->pixel_y
				+ mini->j, mini->color);
			mini->j++;
		}
		mini->i++;
	}
	mini->screen_x++;
}

static void	prepare_player_drawing(t_minimap *mini)
{
	mini->william_center_x = mini->start_x + (mini->minimap_cells_x / 2)
		* mini->cell_size + mini->cell_size / 2;
	mini->william_center_y = mini->start_y + (mini->minimap_cells_y / 2)
		* mini->cell_size + mini->cell_size / 2;
	mini->i = -mini->radius;
}

static void	draw_player_fov(t_game *game, t_minimap *mini)
{
	double	fov_half;

	fov_half = game->william.fov / 2.0;
	mini->fov_half = game->william.fov / 2.0;
	draw_cone_line_centered(game, +fov_half, mini->william_center_x,
		mini->william_center_y);
	draw_cone_line_centered(game, -fov_half, mini->william_center_x,
		mini->william_center_y);
}

static void	draw_player_pixel(t_game *game, t_minimap *mini)
{
	my_mlx_pixel_put(game, mini->william_center_x + mini->i,
		mini->william_center_y + mini->j, RED);
}

void	draw_minimap(t_game *game)
{
	t_minimap	*mini;

	mini = &game->minimap;
	ini_minimap(game);
	while (mini->screen_y < mini->minimap_cells_y)
	{
		mini->screen_x = 0;
		while (mini->screen_x < mini->minimap_cells_x)
			draw_minimap_cell(game, mini);
		mini->screen_y++;
	}
	prepare_player_drawing(mini);
	while (mini->i <= mini->radius)
	{
		mini->j = -mini->radius;
		while (mini->j <= mini->radius)
		{
			if (mini->i * mini->i + mini->j * mini->j <= mini->radius
				* mini->radius)
				draw_player_pixel(game, mini);
			mini->j++;
		}
		mini->i++;
	}
	draw_player_fov(game, mini);
}
