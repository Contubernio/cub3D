/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:17:55 by albealva          #+#    #+#             */
/*   Updated: 2025/06/14 22:40:05 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_line_effectively_empty(const char *line)
{
	while (*line)
	{
		if (!my_is_broad_whitespace(*line))
			return (0);
		line++;
	}
	return (1);
}

int	calculate_expanded_width(const char *line)
{
	int	width;
	int	i;

	width = 0;
	i = 0;
	while (line[i] && line[i] != '\n' && line[i] != '\r')
	{
		if (line[i] == '\t')
		{
			width += 4;
		}
		else
		{
			width++;
		}
		i++;
	}
	return (width);
}

void	init_map_parsing_vars(t_map_vars *vars, int search_start_idx)
{
	vars->map_start_idx = -1;
	vars->map_end_idx = -1;
	vars->map_width = 0;
	vars->i = search_start_idx;
}

int	update_map_block_indices(t_map_vars *vars, const char *current_file_line)
{
	if (!is_line_effectively_empty(current_file_line))
	{
		if (vars->map_start_idx == -1)
			vars->map_start_idx = vars->i;
		vars->map_end_idx = vars->i;
	}
	else
	{
		if (vars->map_start_idx != -1)
			return (1);
	}
	return (0);
}

void	calculate_map_dimensions(t_map_vars *vars, char **file_content)
{
	vars->map_height = (vars->map_end_idx - vars->map_start_idx) + 1;
	vars->i = 0;
	while (vars->i < vars->map_height)
	{
		vars->current_expanded_width = \
calculate_expanded_width(file_content[vars->map_start_idx
				+ vars->i]);
		if (vars->current_expanded_width > vars->map_width)
		{
			vars->map_width = vars->current_expanded_width;
		}
		vars->i++;
	}
}
