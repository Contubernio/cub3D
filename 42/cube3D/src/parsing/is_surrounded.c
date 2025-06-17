/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_surrounded.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:37:23 by gasroman          #+#    #+#             */
/*   Updated: 2025/06/15 12:56:47 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_surrounded(t_game *game, int i, int j)
{
	if (game->data->map[j][i] != ' ' && game->data->map[j][i] != '\n')
	{
		if (game->data->map[j][i] != '1')
		{
			if (j == 0 || i == 0 || (ft_strlen(game->data->map[j + 1]) \
				< (size_t)i + 1) || (ft_strlen(game->data->map[j - 1]) \
				< (size_t)i + 1) || game->data->map[j - 1][i] == ' ' || \
				game->data->map[j][i - 1] == ' ' ||
				game->data->map[j][i + 1] == ' ' || \
				game->data->map[j + 1][i] == ' ')
				return (fals);
		}
	}
	return (tru);
}
