/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 01:20:32 by albealva          #+#    #+#             */
/*   Updated: 2025/06/15 01:21:10 by contubernio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	check_horizontal_border(char *row, int width)
{
	int	x;

	x = 0;
	while (x < width)
	{
		if (row[x] != '1' && row[x] != ' ')
			return (1);
		x++;
	}
	return (0);
}

static int	check_middle_row_borders(char *row, int width)
{
	int	x;
	int	first_char_idx;
	int	last_char_idx;

	first_char_idx = -1;
	last_char_idx = -1;
	x = 0;
	while (x < width)
	{
		if (row[x] != ' ')
		{
			if (first_char_idx == -1)
				first_char_idx = x;
			last_char_idx = x;
		}
		x++;
	}
	if (first_char_idx != -1)
	{
		if (row[first_char_idx] != '1' || row[last_char_idx] != '1')
			return (1);
	}
	return (0);
}

int	validate_map_borders(t_game *game)
{
	int	y;

	if (!game || !game->data || !game->data->map || game->data->map_height < 3)
		return (1);
	if (check_horizontal_border(game->data->map[0], game->data->map_width))
		return (1);
	if (check_horizontal_border(game->data->map[game->data->map_height - 1],
			game->data->map_width))
		return (1);
	y = 1;
	while (y < game->data->map_height - 1)
	{
		if (check_middle_row_borders(game->data->map[y], game->data->map_width))
			return (1);
		y++;
	}
	return (0);
}
