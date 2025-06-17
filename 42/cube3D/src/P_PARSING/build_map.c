/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:33:28 by albealva          #+#    #+#             */
/*   Updated: 2025/06/14 22:41:40 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	allocate_and_init_map_structure(t_game *game, t_map_vars *vars,
		char **file_content)
{
	calculate_map_dimensions(vars, file_content);
	game->data->map_height = vars->map_height;
	game->data->map_width = vars->map_width;
	game->data->map = (char **)malloc((vars->map_height + 1) * sizeof(char *));
	if (game->data->map == NULL)
	{
		return (1);
	}
	vars->i = 0;
	return (0);
}

static void	copy_and_expand_line(t_game *game, t_map_vars *vars)
{
	int	tab_i;

	aux(vars);
	while (vars->source_line[vars->j_source]
		&& vars->source_line[vars->j_source] != '\n'
		&& vars->source_line[vars->j_source] != '\r'
		&& vars->j_dest < vars->map_width)
	{
		if (vars->source_line[vars->j_source] == '\t')
		{
			tab_i = 0;
			while (tab_i < 4 && vars->j_dest < vars->map_width)
			{
				game->data->map[vars->i][vars->j_dest++] = ' ';
				tab_i++;
			}
		}
		else
			game->data->map[vars->i][vars->j_dest++] = \
vars->source_line[vars->j_source];
		vars->j_source++;
	}
	while (vars->j_dest < vars->map_width)
		game->data->map[vars->i][vars->j_dest++] = ' ';
	game->data->map[vars->i][vars->map_width] = '\0';
}

static int	process_map_rows(t_game *game, t_map_vars *vars,
		char **file_content)
{
	int	k;

	vars->i = 0;
	while (vars->i < vars->map_height)
	{
		game->data->map[vars->i] = (char *)malloc((vars->map_width + 1)
				* sizeof(char));
		if (game->data->map[vars->i] == NULL)
		{
			k = 0;
			while (k < vars->i)
			{
				free(game->data->map[k]);
				k++;
			}
			free(game->data->map);
			game->data->map = NULL;
			return (1);
		}
		vars->source_line = file_content[vars->map_start_idx + vars->i];
		vars->source_len = ft_strlen(vars->source_line);
		copy_and_expand_line(game, vars);
		vars->i++;
	}
	return (game->data->map[vars->map_height] = NULL, 0);
}

static int	validate_final_map_chars(t_game *game, t_map_vars *vars)
{
	vars->i = 0;
	while (vars->i < vars->map_height)
	{
		vars->j = 0;
		while (vars->j < vars->map_width)
		{
			if (!is_valid_map_char(game->data->map[vars->i][vars->j]))
			{
				printf(ANSI_COLOR_RED "Error:" ANSI_COLOR_RESET " \
Invalid character '%c' in final map processing.\n",
					game->data->map[vars->i][vars->j]);
				free_char_array(game->data->map);
				game->data->map = NULL;
				return (1);
			}
			vars->j++;
		}
		vars->i++;
	}
	return (0);
}

int	create_and_normalize_map_tabs(t_game *game, char **file_content,
		int search_start_idx, int total_file_lines)
{
	t_map_vars	vars;

	init_map_parsing_vars(&vars, search_start_idx);
	while (vars.i < total_file_lines)
	{
		if (update_map_block_indices(&vars, file_content[vars.i]))
			break ;
		vars.i++;
	}
	if (vars.map_start_idx == -1)
	{
		printf(ANSI_COLOR_RED "Error:" ANSI_COLOR_RESET \
" No map data found.\n");
		return (1);
	}
	if (allocate_and_init_map_structure(game, &vars, file_content) != 0)
		return (1);
	if (process_map_rows(game, &vars, file_content) != 0)
		return (1);
	if (validate_final_map_chars(game, &vars) != 0)
		return (1);
	return (0);
}
