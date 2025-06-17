/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:02:14 by gasroman          #+#    #+#             */
/*   Updated: 2025/06/15 12:47:24 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	printf_double_array(char **split)
{
	int	iter;

	if (!split || !split[0])
		return ;
	iter = 0;
	while (split[iter])
	{
		printf("[%d] line: *%s*\n", iter, split[iter]);
		iter++;
	}
}

int	store_texture(char **split, t_game *game)
{
	int	fd;

	if (!split[1])
		return (printf("Texture Error1\n"), 1);
	if (texture_format(split[1]))
		return (printf("Texture Format Error\n"), 1);
	printf_double_array(split);
	fd = open(split[1], O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (printf("Texture Error2\n"), 1);
	}
	if (!ft_strncmp(split[0], "NO", 3) && game->data->no == NULL)
		game->data->no = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "SO", 3) && game->data->so == NULL)
		game->data->so = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "EA", 3) && game->data->ea == NULL)
		game->data->ea = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "WE", 3) && game->data->we == NULL)
		game->data->we = ft_strdup(split[1]);
	else
		return (fals);
	return (tru);
}
