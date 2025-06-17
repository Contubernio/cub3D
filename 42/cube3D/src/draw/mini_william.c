/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_william.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:49:45 by albealva          #+#    #+#             */
/*   Updated: 2025/06/14 21:24:14 by contubernio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	draw_william_circle_centered(t_game *game, int center_x, int center_y)
{
	int	radius;
	int	i;
	int	j;

	radius = 3;
	i = -radius;
	while (i <= radius)
	{
		j = -radius;
		while (j <= radius)
		{
			if (i * i + j * j <= radius * radius)
				my_mlx_pixel_put(game, center_x + i, center_y + j, RED);
			j++;
		}
		i++;
	}
}

static void	init_cone_drawing(t_game *game, double angle_offset, t_cone *cone,
		t_coneaux *aux)
{
	aux->step = 0.5;
	aux->length = 5.0;
	aux->i = 0.0;
	cone->angle = angle_offset;
	cone->dir_x = game->william.dir_x * cos(cone->angle) - game->william.dir_y
		* sin(cone->angle);
	cone->dir_y = game->william.dir_x * sin(cone->angle) + game->william.dir_y
		* cos(cone->angle);
}

void	draw_cone_line_centered_pre(t_game *game, double angle_offset,
		int center_x, int center_y)
{
	t_cone		cone;
	t_coneaux	aux;

	init_cone_drawing(game, angle_offset, &cone, &aux);
	while (aux.i < aux.length)
	{
		cone.x = center_x + (int)(cone.dir_x * aux.i * 8);
		cone.y = center_y + (int)(cone.dir_y * aux.i * 8);
		aux.current_map_x = (cone.x - 10) / 8 + ((int)game->william.x
				- (MINIMAP_WIDTH / (2 * 8)));
		aux.current_map_y = (cone.y - 10) / 8 + ((int)game->william.y
				- (MINIMAP_HEIGHT / (2 * 8)));
		if (aux.current_map_x >= 0 && aux.current_map_x < MAP_WIDTH
			&& aux.current_map_y >= 0 && aux.current_map_y < MAP_HEIGHT)
		{
			if (game->data->map[aux.current_map_y][aux.current_map_x] == '1'
				|| game->data->map[aux.current_map_y][aux.current_map_x] == 'D')
				break ;
		}
		my_mlx_pixel_put(game, cone.x, cone.y, YELLOW);
		aux.i += aux.step;
	}
}

void	draw_cone_line_centered(t_game *game, double angle_offset, int center_x,
		int center_y)
{
	t_cone		cone;
	t_coneaux	aux;

	init_cone_drawing(game, angle_offset, &cone, &aux);
	while (aux.i < aux.length)
	{
		cone.x = center_x + (int)(cone.dir_x * aux.i * 8);
		cone.y = center_y + (int)(cone.dir_y * aux.i * 8);
		aux.current_map_x = (cone.x - 10) / 8 + ((int)game->william.x
				- (MINIMAP_WIDTH / (2 * 8)));
		aux.current_map_y = (cone.y - 10) / 8 + ((int)game->william.y
				- (MINIMAP_HEIGHT / (2 * 8)));
		if (aux.current_map_x >= 0 && aux.current_map_x < game->data->map_width
			&& aux.current_map_y >= 0
			&& aux.current_map_y < game->data->map_height)
		{
			if (game->data->map[aux.current_map_y][aux.current_map_x] == '1'
				|| game->data->map[aux.current_map_y][aux.current_map_x] == '2'
				|| game->data->map[aux.current_map_y][aux.current_map_x] == 'D')
				break ;
		}
		my_mlx_pixel_put(game, cone.x, cone.y, YELLOW);
		aux.i += aux.step;
	}
}

void	ini_minimap(t_game *game)
{
	t_minimap	*mini;

	mini = &game->minimap;
	mini->player_map_x = (int)game->william.x;
	mini->player_map_y = (int)game->william.y;
	mini->minimap_cells_x = 15;
	mini->minimap_cells_y = 15;
	mini->offset_x = mini->minimap_cells_x / 2;
	mini->offset_y = mini->minimap_cells_y / 2;
	mini->cell_size = 8;
	mini->start_x = 387;
	mini->start_y = 670;
	mini->radius = 3;
	mini->screen_y = 0;
}
