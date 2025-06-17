/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_william_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:31:10 by albealva          #+#    #+#             */
/*   Updated: 2025/06/14 21:23:51 by contubernio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	calculate_minimap_coords(t_minimap *mini)
{
	mini->map_x = mini->player_map_x - mini->offset_x + mini->screen_x;
	mini->map_y = mini->player_map_y - mini->offset_y + mini->screen_y;
	mini->pixel_x = mini->start_x + mini->screen_x * mini->cell_size;
	mini->pixel_y = mini->start_y + mini->screen_y * mini->cell_size;
	mini->color = BLACK;
}

void	set_minimap_cell_color(t_game *game, t_minimap *mini)
{
	if (mini->map_y < 0 || mini->map_y >= game->data->map_height
		|| mini->map_x < 0 || mini->map_x >= game->data->map_width)
	{
		mini->color = BLACK;
		return ;
	}
	mini->cell = game->data->map[mini->map_y][mini->map_x];
	if (mini->cell == '1')
		mini->color = WHITE;
	else if (mini->cell == '2')
		mini->color = WHITE;
	else if (mini->cell == 'D')
		mini->color = MINIMAP_PURPLE;
	else if (mini->cell == 'O')
		mini->color = YELLOW;
	else if (mini->cell == 'W')
		mini->color = BLACK;
	else if (mini->cell == ' ')
		mini->color = BLACK;
	else
		mini->color = BLACK;
}
