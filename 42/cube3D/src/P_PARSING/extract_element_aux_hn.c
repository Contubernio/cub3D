/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_element_aux_hn.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:32:52 by albealva          #+#    #+#             */
/*   Updated: 2025/06/11 13:19:02 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	process_known_element(t_game *game, t_extract *aux)
{
	char	**target_texture_ptr;
	int		*target_color_ptr;

	if (aux->current_flag_index >= 0 && aux->current_flag_index <= 3)
	{
		if (aux->current_flag_index == 0)
			target_texture_ptr = &game->data->no;
		else if (aux->current_flag_index == 1)
			target_texture_ptr = &game->data->so;
		else if (aux->current_flag_index == 2)
			target_texture_ptr = &game->data->we;
		else
			target_texture_ptr = &game->data->ea;
		return (parse_texture_element(game, aux, target_texture_ptr));
	}
	else
	{
		if (aux->current_flag_index == 4)
			target_color_ptr = &game->data->floor;
		else
			target_color_ptr = &game->data->ceiling;
		return (parse_color_element(game, aux, target_color_ptr));
	}
}

void	set_aux_element_info(t_extract *aux, int flag_idx, const char *name,
		int id_len)
{
	aux->current_flag_index = flag_idx;
	aux->current_element_name = name;
	aux->current_identifier_len = id_len;
}

int	process_texture_elements(t_game *game, t_extract *aux, char *line_content)
{
	if (ft_strncmp(line_content, "NO", 2) == 0 && my_isspace(line_content[2]))
	{
		set_aux_element_info(aux, 0, "NO", 2);
		return (process_known_element(game, aux));
	}
	else if (ft_strncmp(line_content, "SO", 2) == 0
		&& my_isspace(line_content[2]))
	{
		set_aux_element_info(aux, 1, "SO", 2);
		return (process_known_element(game, aux));
	}
	else if (ft_strncmp(line_content, "WE", 2) == 0
		&& my_isspace(line_content[2]))
	{
		set_aux_element_info(aux, 2, "WE", 2);
		return (process_known_element(game, aux));
	}
	else if (ft_strncmp(line_content, "EA", 2) == 0
		&& my_isspace(line_content[2]))
	{
		set_aux_element_info(aux, 3, "EA", 2);
		return (process_known_element(game, aux));
	}
	return (-1);
}

int	process_color_elements(t_game *game, t_extract *aux, char *line_content)
{
	if (ft_strncmp(line_content, "F", 1) == 0 && my_isspace(line_content[1]))
	{
		set_aux_element_info(aux, 4, "F", 1);
		return (process_known_element(game, aux));
	}
	else if (ft_strncmp(line_content, "C", 1) == 0
		&& my_isspace(line_content[1]))
	{
		set_aux_element_info(aux, 5, "C", 1);
		return (process_known_element(game, aux));
	}
	return (-1);
}

int	process_current_line(t_game *game, t_extract *aux, char *line_content,
		const char *original_line_for_error_msg)
{
	int	result;

	aux->current_line_content = line_content;
	result = process_texture_elements(game, aux, line_content);
	if (result != -1)
		return (result);
	result = process_color_elements(game, aux, line_content);
	if (result != -1)
		return (result);
	if (check_for_premature_map_line(aux, line_content) != 0)
		return (1);
	printf(ANSI_COLOR_RED "Error:" ANSI_COLOR_RESET \
" Invalid line in config section: [%s]\n",
		original_line_for_error_msg);
	return (1);
}
