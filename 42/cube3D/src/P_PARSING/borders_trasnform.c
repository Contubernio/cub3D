/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borders_trasnform.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 01:23:06 by albealva          #+#    #+#             */
/*   Updated: 2025/06/15 01:46:10 by contubernio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static char	**duplicate_map(t_data *data)
{
	char	**map_copy;
	int		i;

	map_copy = (char **)malloc((data->map_height + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < data->map_height)
	{
		map_copy[i] = ft_strdup(data->map[i]);
		if (!map_copy[i])
		{
			free_char_array(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[data->map_height] = NULL;
	return (map_copy);
}

static int	is_border_wall(t_point p, t_data *data, char **map_copy)
{
	if (p.y == 0 || p.y == data->map_height - 1 || p.x == 0
		|| p.x == data->map_width - 1)
		return (1);
	if (map_copy[p.y - 1][p.x] == ' ' || map_copy[p.y + 1][p.x] == ' '
		|| map_copy[p.y][p.x - 1] == ' ' || map_copy[p.y][p.x + 1] == ' ')
		return (1);
	return (0);
}

static void	transform_border_walls(t_game *game, char **map_copy)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->data->map_height)
	{
		x = 0;
		while (x < game->data->map_width)
		{
			if (map_copy[y][x] == '1')
			{
				if (is_border_wall((t_point){x, y}, game->data, map_copy))
					game->data->map[y][x] = '2';
			}
			x++;
		}
		y++;
	}
}

int	validate_and_transform_borders(t_game *game)
{
	char	**map_copy;

	if (!game || !game->data || !game->data->map || game->data->map_height < 3)
		return (1);
	map_copy = duplicate_map(game->data);
	if (!map_copy)
		return (1);
	transform_border_walls(game, map_copy);
	free_char_array(map_copy);
	return (0);
}
