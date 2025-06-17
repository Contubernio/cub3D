/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_element_aux_line.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:52:11 by albealva          #+#    #+#             */
/*   Updated: 2025/06/11 13:13:57 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	is_empty_or_newline(const char *line)
{
	while (*line && my_isspace(*line))
		line++;
	return (*line == '\0' || *line == '\n');
}

void	init_extract_and_loop_vars(t_extract *aux,
		int *p_map_start_line_idx_ptr, int *loop_idx_ptr)
{
	aux->elements_found_count = 0;
	memset(aux->element_flags, 0, sizeof(aux->element_flags));
	aux->value_str = NULL;
	aux->current_line_content = NULL;
	aux->current_element_name = NULL;
	aux->current_identifier_len = 0;
	aux->current_flag_index = -1;
	aux->p_map_start_line_idx_ptr = p_map_start_line_idx_ptr;
	aux->original_file_line_for_error = NULL;
	*p_map_start_line_idx_ptr = -1;
	*loop_idx_ptr = 0;
}

static int	handle_initial_line_checks(t_extract *aux,
		char *trimmed_line_content, int *p_map_start_line_idx_out)
{
	if (is_empty_or_newline(trimmed_line_content))
		return (0);
	if (aux->elements_found_count == 6)
	{
		if (is_config_element_identifier(trimmed_line_content))
		{
			printf(ANSI_COLOR_RED "Error:" ANSI_COLOR_RESET \
" Element definition found after all 6 elements were already parsed: [%s]\n",
				trimmed_line_content);
			return (1);
		}
		*p_map_start_line_idx_out = aux->current_flag_index;
		return (2);
	}
	return (-1);
}

int	process_file_line(t_game *game, t_extract *aux, char *current_file_line,
		int *p_map_start_line_idx_ptr)
{
	char	*trimmed_line_content;
	int		status;

	aux->original_file_line_for_error = current_file_line;
	aux->p_map_start_line_idx_ptr = p_map_start_line_idx_ptr;
	trimmed_line_content = current_file_line;
	while (*trimmed_line_content && my_isspace(*trimmed_line_content))
		trimmed_line_content++;
	aux->current_line_content = trimmed_line_content;
	status = handle_initial_line_checks(aux, aux->current_line_content,
			aux->p_map_start_line_idx_ptr);
	if (status != -1)
		return (status);
	status = process_current_line(game, aux, aux->current_line_content,
			aux->original_file_line_for_error);
	if (status == 1)
		return (1);
	return (0);
}
