/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrac_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:58:13 by albealva          #+#    #+#             */
/*   Updated: 2025/06/11 13:06:59 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	extract_map_config_elements(t_game *game, char **file_content,
		int num_lines, int *p_map_start_line_idx)
{
	t_extract	aux;
	int			i;
	int			line_process_status;

	init_extract_and_loop_vars(&aux, p_map_start_line_idx, &i);
	while (i < num_lines)
	{
		aux.current_flag_index = i;
		line_process_status = process_file_line(game, &aux, file_content[i],
				aux.p_map_start_line_idx_ptr);
		if (line_process_status == 1)
			return (1);
		if (line_process_status == 2)
			return (0);
		i++;
	}
	if (validate_all_elements_found(&aux) != 0)
		return (1);
	if (*(aux.p_map_start_line_idx_ptr) == -1)
		*(aux.p_map_start_line_idx_ptr) = num_lines;
	return (0);
}
