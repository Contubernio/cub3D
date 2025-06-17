/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:21:52 by gasroman          #+#    #+#             */
/*   Updated: 2025/05/23 11:05:43 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	is_number(char *color)
{
	int	i;

	i = 0;
	if (!color)
		return (fals);
	while (color[i])
	{
		if (!ft_isdigit(color[i]))
			return (fals);
		i++;
	}
	return (tru);
}

int	value_checks(char **color)
{
	int	i;
	int	c;
	int	n;

	i = 0;
	c = -1;
	while (color[i])
	{
		n = 0;
		if (!is_number(color[i]))
			return (printf("Color Error1\n"), fals);
		while (color[i][n])
			n++;
		if (n > 3)
			return (fals);
		c = ft_atoi(color[i]);
		if (c < 0 || c > 255)
			return (printf("Color Error2\n"), fals);
		i++;
	}
	return (tru);
}
