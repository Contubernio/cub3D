/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_intro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:23:55 by albealva          #+#    #+#             */
/*   Updated: 2025/06/15 00:47:40 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	parse_and_validate_map(t_game *game, const char *path)
{
	char	**file_content;
	int		num_lines;
	int		map_start_idx;
	int		fd;

	fd = open_map_file(path);
	if (fd == -1)
		return (1);
	file_content = read_file_content(fd, &num_lines);
	close(fd);
	if (!file_content)
		return (1);
	if (extract_map_config_elements(game, file_content, num_lines,
			&map_start_idx) != 0)
		return (free_char_array(file_content), 1);
	if (create_and_normalize_map_tabs(game, file_content, map_start_idx,
			num_lines) != 0)
		return (free_char_array(file_content), 1);
	free_char_array(file_content);
	if (validate_map_borders(game) != 0 || validate_player_data(game) != 0 || \
validate_map_is_closed(game) != 0 || validate_texture_files(game) != 0)
		return (1);
	validate_and_transform_borders(game);
	printf(ANSI_COLOR_GREEN "Success:" ANSI_COLOR_RESET " Map '%s'ok.\n", path);
	return (0);
}
