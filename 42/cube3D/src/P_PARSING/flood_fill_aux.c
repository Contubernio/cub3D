/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 00:40:39 by albealva          #+#    #+#             */
/*   Updated: 2025/06/15 00:43:49 by contubernio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_flood_fill_vars(t_flood_fill_vars *vars)
{
	vars->player_x = -1;
	vars->player_y = -1;
	vars->is_leaking = 0;
	vars->y = 0;
}

int	find_player_position(t_game *game, t_flood_fill_vars *vars)
{
	vars->y = 0;
	while (vars->y < game->data->map_height)
	{
		vars->x = 0;
		while (vars->x < game->data->map_width)
		{
			if (ft_strchr("NSEW", game->data->map[vars->y][vars->x]))
			{
				vars->player_y = vars->y;
				vars->player_x = vars->x;
				return (0);
			}
			vars->x++;
		}
		vars->y++;
	}
	return (1);
}
