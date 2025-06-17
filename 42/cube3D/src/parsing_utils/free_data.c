/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:25:54 by gasroman          #+#    #+#             */
/*   Updated: 2025/05/23 11:08:46 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	free_data(t_game *game)
{
	if (game->data->no)
		free(game->data->no);
	if (game->data->so)
		free(game->data->so);
	if (game->data->ea)
		free(game->data->ea);
	if (game->data->we)
		free(game->data->we);
	if (game->data->map)
		free(game->data->map);
}

void	free_split(char ***arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
