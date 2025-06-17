/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:35:06 by gasroman          #+#    #+#             */
/*   Updated: 2025/06/15 12:52:34 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
int	line_checker(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->data->map[j++])
	{
		i = -1;
		while (game->data->map[j][++i])
		{
			if (game->data->map[j][i] == 'N' || game->data->map[j][i] == 'S' \
				|| game->data->map[j][i] == 'E' || game->data->map[j][i] == 'W' \
				|| game->data->map[j][i] == '1' || 
				game->data->map[j][i] == '0' \
				|| game->data->map[j][i] == 'D' || game->data->map[j][i] == 'O' \
				|| game->data->map[j][i] == ' ' || game->data->map[j][i] == '\n')
			{
				if (is_surrounded(game, i, j) == fals)
					return (fals);
				if (player_count(game->data->map[j][i]) == fals)
					return (fals);
			}
			else
				return (fals);
		}
	}
	return (tru);
}
*/