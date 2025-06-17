/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrac_element_aux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:28:15 by albealva          #+#    #+#             */
/*   Updated: 2025/06/14 23:11:20 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_config_element_identifier(const char *line)
{
	if ((ft_strncmp(line, "NO", 2) == 0 && my_isspace(line[2]))
		|| (ft_strncmp(line, "SO", 2) == 0 && my_isspace(line[2]))
		|| (ft_strncmp(line, "WE", 2) == 0 && my_isspace(line[2]))
		|| (ft_strncmp(line, "EA", 2) == 0 && my_isspace(line[2])))
		return (1);
	if ((ft_strncmp(line, "F", 1) == 0 && my_isspace(line[1]))
		|| (ft_strncmp(line, "C", 1) == 0 && my_isspace(line[1])))
		return (1);
	return (0);
}

int	check_for_premature_map_line(t_extract *aux, const char *line_content)
{
	if (aux->elements_found_count < 6)
	{
		if (*line_content == '1' || *line_content == '0'
			|| my_isspace(*line_content))
		{
			printf(ANSI_COLOR_RED "Error:" ANSI_COLOR_RESET \
" Map-like line encountered before all 6 elements were defined (found\
%d/6): [%s]\n", aux->elements_found_count, line_content);
			return (1);
		}
	}
	return (0);
}

int	validate_all_elements_found(t_extract *aux)
{
	if (aux->elements_found_count != 6)
	{
		printf(ANSI_COLOR_RED "Error:" ANSI_COLOR_RESET " \
Missing one or more configuration elements. Found \
%d/6.\n", aux->elements_found_count);
		return (1);
	}
	return (0);
}

int	parse_texture_element(t_game *game, t_extract *aux,
		char **target_texture_ptr)
{
	(void)game;
	if (aux->element_flags[aux->current_flag_index])
	{
		printf(ANSI_COLOR_RED "Error:" ANSI_COLOR_RESET \
" Duplicate	%s element.\n", aux->current_element_name);
		return (1);
	}
	aux->value_str = get_trimmed_value_from_line(aux->current_line_content
			+ aux->current_identifier_len);
	if (!aux->value_str)
		return (1);
	if (*target_texture_ptr)
		free(*target_texture_ptr);
	*target_texture_ptr = aux->value_str;
	aux->element_flags[aux->current_flag_index] = 1;
	aux->elements_found_count++;
	return (0);
}

int	parse_color_element(t_game *game, t_extract *aux, int *target_color_ptr)
{
	(void)game;
	if (aux->element_flags[aux->current_flag_index])
	{
		printf(ANSI_COLOR_RED "Error:" ANSI_COLOR_RESET
			" Duplicate	%s element.\n", aux->current_element_name);
		return (1);
	}
	aux->value_str = get_trimmed_value_from_line
		(aux->current_line_content + aux->current_identifier_len);
	if (!aux->value_str)
		return (1);
	if (parse_and_validate_rgb_string(aux->value_str, target_color_ptr) != 0)
	{
		free(aux->value_str);
		return (1);
	}
	free(aux->value_str);
	aux->element_flags[aux->current_flag_index] = 1;
	aux->elements_found_count++;
	return (0);
}
