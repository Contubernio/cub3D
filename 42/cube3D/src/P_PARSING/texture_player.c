/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 01:24:32 by albealva          #+#    #+#             */
/*   Updated: 2025/06/15 01:47:48 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	validate_player_data(t_game *game)
{
	int	player_count;
	int	y;
	int	x;

	player_count = 0;
	y = 0;
	if (!game || !game->data || !game->data->map)
		return (1);
	while (y < game->data->map_height)
	{
		x = 0;
		while (x < game->data->map_width)
		{
			if (ft_strchr("NSEW", game->data->map[y][x]))
				player_count++;
			x++;
		}
		y++;
	}
	if (player_count != 1)
	{
		return (1);
	}
	return (0);
}

int	validate_texture_files(t_game *game)
{
	char	*texture_paths[4];
	int		i;
	int		fd;

	texture_paths[0] = game->data->no;
	texture_paths[1] = game->data->so;
	texture_paths[2] = game->data->we;
	texture_paths[3] = game->data->ea;
	i = 0;
	while (i < 4)
	{
		fd = open(texture_paths[i], O_RDONLY);
		if (fd == -1)
		{
			printf(ANSI_COLOR_RED "Error:" ANSI_COLOR_RESET
				" Cannot open texture file: [%s]\n", texture_paths[i]);
			return (1);
		}
		close(fd);
		i++;
	}
	printf(ANSI_COLOR_GREEN "Success:" ANSI_COLOR_RESET
		" All texture files are valid and accessible.\n");
	return (0);
}
