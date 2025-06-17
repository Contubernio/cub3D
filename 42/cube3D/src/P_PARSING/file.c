/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:36:58 by albealva          #+#    #+#             */
/*   Updated: 2025/06/10 19:06:47 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	open_map_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf(ANSI_COLOR_RED "Error:" ANSI_COLOR_RESET \
		" Could not open map file:	%s\n", filename);
		printf("       Please ensure the file \
exists and that you have read permissions.\n");
		printf("       You can try granting read permissions with: " \
		ANSI_COLOR_YELLOW "chmod +r %s" ANSI_COLOR_RESET "\n", filename);
		return (-1);
	}
	return (fd);
}

static char	**handle_read_error(t_aux aux, int *num_lines_read_out,
		const char *error_msg)
{
	int	i;

	i = 0;
	printf(ANSI_COLOR_RED "Error:" ANSI_COLOR_RESET " %s\n", error_msg);
	if (aux.file_lines != NULL)
	{
		while (i < aux.count)
		{
			if (aux.file_lines[i])
				free(aux.file_lines[i]);
			i++;
		}
		free(aux.file_lines);
	}
	if (aux.line)
	{
		free(aux.line);
	}
	*num_lines_read_out = 0;
	return (NULL);
}

static int	append_line_to_array(char ***file_lines_ptr, char *current_line,
		int *count_ptr)
{
	char	**temp_lines;

	temp_lines = ft_double_realloc(*file_lines_ptr, (*count_ptr + 2)
			* sizeof(char *));
	if (temp_lines == NULL)
	{
		return (1);
	}
	*file_lines_ptr = temp_lines;
	(*file_lines_ptr)[*count_ptr] = ft_strdup(current_line);
	if ((*file_lines_ptr)[*count_ptr] == NULL)
		return (1);
	(*count_ptr)++;
	return (0);
}

char	**read_file_content(int fd, int *num_lines_read_out)
{
	t_aux	aux;

	aux.line = NULL;
	aux.file_lines = NULL;
	aux.count = 0;
	if (fd < 0 || num_lines_read_out == NULL)
		return (NULL);
	*num_lines_read_out = 0;
	aux.line = get_next_line(fd);
	while (aux.line != NULL)
	{
		if (append_line_to_array(&aux.file_lines, aux.line, &aux.count) != 0)
		{
			return (handle_read_error(aux, num_lines_read_out,
					"Failed to reallocate or duplicate line content."));
		}
		free(aux.line);
		aux.line = get_next_line(fd);
	}
	if (aux.file_lines)
		aux.file_lines[aux.count] = NULL;
	*num_lines_read_out = aux.count;
	return (aux.file_lines);
}
