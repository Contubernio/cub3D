/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:34:07 by gasroman          #+#    #+#             */
/*   Updated: 2025/06/15 12:49:46 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	store_color(char **split, t_game *game)
{
	t_color	color;
	char	**code;

	code = ft_split(split[1], ',');
	if (!value_checks(code))
		return (printf("Color Value Error!\n"), fals);
	color.r = (unsigned char)ft_atoi(code[0]);
	color.g = (unsigned char)ft_atoi(code[1]);
	color.b = (unsigned char)ft_atoi(code[2]);
	color.a = 255;
	if (split[0][0] == 'F' && split[0][1] == '\0')
		game->data->floor = color.rgba;
	else if (split[0][0] == 'C' && split[0][1] == '\0')
		game->data->ceiling = color.rgba;
	free(code);
	return (tru);
}
