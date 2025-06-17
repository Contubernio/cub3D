/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:08:13 by gasroman          #+#    #+#             */
/*   Updated: 2025/05/23 11:06:20 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_texture(char **split)
{
	if (ft_strncmp(split[0], "NO", 3) == 0 || \
			ft_strncmp(split[0], "SO", 3) == 0 || \
			ft_strncmp(split[0], "EA", 3) == 0 || \
			ft_strncmp(split[0], "WE", 3) == 0)
		return (tru);
	return (fals);
}

int	is_color(char **split)
{
	if (ft_strncmp(split[0], "F", 2) == 0 || \
			ft_strncmp(split[0], "C", 2) == 0)
		return (tru);
	return (fals);
}
