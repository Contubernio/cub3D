/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:05:26 by gasroman          #+#    #+#             */
/*   Updated: 2025/06/15 12:47:05 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	texture_format(char *filename)
{
	int	len;

	if (!filename)
		return (1);
	len = ft_strlen(filename);
	if (len < 5)
		return (1);
	return (0);
}

int	data_format(char *filename)
{
	int	len;

	if (!filename)
		return (1);
	len = ft_strlen(filename);
	if (len < 5)
		return (1);
	if (filename[len - 4] == '.' && \
		filename[len - 3] == 'c' && \
		filename[len - 2] == 'u' && \
		filename[len - 1] == 'b')
		return (1);
	return (0);
}
