/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:20:26 by albealva          #+#    #+#             */
/*   Updated: 2025/06/15 00:49:27 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	is_valid_digit_string(const char *str)
{
	int	k;

	k = 0;
	if (str[0] == '\0')
		return (1);
	while (str[k])
	{
		if (!ft_isdigit(str[k]))
			return (1);
		k++;
	}
	return (0);
}

static int	is_val_in_rgb_range(long val)
{
	if (val < 0 || val > 255)
		return (1);
	return (0);
}

static int	validate_rgb_component(const char *component_str, int *val_out,
		const char *s, int c)
{
	long	val;

	if (is_valid_digit_string(component_str) != 0)
	{
		if (component_str[0] == '\0')
			printf(ANSI_COLOR_RED "E:" ANSI_COLOR_RESET "RGB%dempty[%s].\n", c
				+ 1, s);
		else
			printf(ANSI_COLOR_RED "E:" ANSI_COLOR_RESET "RGB'%s'is't ok[%s].\n",
				component_str, s);
		return (1);
	}
	val = ft_atoi(component_str);
	if (is_val_in_rgb_range(val) != 0)
	{
		printf(ANSI_COLOR_RED "" ANSI_COLOR_RESET "RGB%ld(0-255)[%s].\n", val,
			s);
		return (1);
	}
	*val_out = (int)val;
	return (0);
}

static int	validate_and_extract_rgb_values(char **rgb_parts,
		int *rgb_values_out, const char *rgb_string)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (rgb_parts[count])
		count++;
	if (count != 3)
	{
		printf(ANSI_COLOR_RED "Error:" ANSI_COLOR_RESET
			" RGB string does not contain 3 components: [%s]\n", rgb_string);
		return (1);
	}
	i = 0;
	while (i < 3)
	{
		if (validate_rgb_component(rgb_parts[i], &rgb_values_out[i], rgb_string,
				i) != 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	parse_and_validate_rgb_string(const char *rgb_string, int *color_out)
{
	char	**rgb_parts;
	int		rgb_values[3];

	if (!rgb_string || !color_out)
		return (1);
	rgb_parts = ft_split(rgb_string, ',');
	if (!rgb_parts)
	{
		printf(ANSI_COLOR_RED "Error:" ANSI_COLOR_RESET
			" ft_split failed for RGB string.\n");
		return (1);
	}
	if (validate_and_extract_rgb_values(rgb_parts, rgb_values, rgb_string) != 0)
	{
		free_char_array(rgb_parts);
		return (1);
	}
	free_char_array(rgb_parts);
	*color_out = (rgb_values[0] << 16) | (rgb_values[1] << 8) | rgb_values[2];
	return (0);
}
