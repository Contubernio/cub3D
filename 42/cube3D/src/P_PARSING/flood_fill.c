/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:50:00 by albealva          #+#    #+#             */
/*   Updated: 2025/06/15 00:40:23 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	copy_map_for_flood_fill(t_game *game, t_flood_fill_vars *vars)
{
	vars->i = 0;
	while (vars->i < game->data->map_height)
	{
		vars->map_copy[vars->i] = ft_strdup(game->data->map[vars->i]);
		if (!vars->map_copy[vars->i])
		{
			vars->map_copy[vars->i] = NULL;
			free_char_array(vars->map_copy);
			return (1);
		}
		vars->i++;
	}
	vars->map_copy[game->data->map_height] = NULL;
	return (0);
}

static t_point	find_player_start_pos(t_data *data)
{
	t_point	pos;
	int		y;
	int		x;

	pos.y = -1;
	pos.x = -1;
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (ft_strchr("NSEW", data->map[y][x]))
			{
				pos.y = y;
				pos.x = x;
				return (pos);
			}
			x++;
		}
		y++;
	}
	return (pos);
}

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

int	validate_map_is_closed(t_game *game)
{
	char	**map_copy;
	t_point	player_pos;
	int		is_leaking;

	player_pos = find_player_start_pos(game->data);
	if (player_pos.x == -1)
		return (1);
	map_copy = duplicate_map(game->data);
	if (!map_copy)
		return (1);
	is_leaking = 0;
	flood_fill_recursive(map_copy, player_pos, game->data, &is_leaking);
	free_char_array(map_copy);
	return (is_leaking);
}

void	flood_fill_recursive(char **map_copy, t_point pos, t_data *data,
		int *is_leaking)
{
	if (*is_leaking)
		return ;
	if (pos.y < 0 || pos.y >= data->map_height || pos.x < 0
		|| pos.x >= data->map_width)
	{
		*is_leaking = 1;
		return ;
	}
	if (map_copy[pos.y][pos.x] == ' ')
	{
		*is_leaking = 1;
		return ;
	}
	if (map_copy[pos.y][pos.x] == '1' || map_copy[pos.y][pos.x] == 'F')
		return ;
	map_copy[pos.y][pos.x] = 'F';
	flood_fill_recursive(map_copy, (t_point){pos.x, pos.y + 1}, data,
		is_leaking);
	flood_fill_recursive(map_copy, (t_point){pos.x, pos.y - 1}, data,
		is_leaking);
	flood_fill_recursive(map_copy, (t_point){pos.x + 1, pos.y}, data,
		is_leaking);
	flood_fill_recursive(map_copy, (t_point){pos.x - 1, pos.y}, data,
		is_leaking);
}
