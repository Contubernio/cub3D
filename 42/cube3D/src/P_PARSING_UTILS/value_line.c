/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:19:12 by albealva          #+#    #+#             */
/*   Updated: 2025/06/15 00:50:56 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static const char	*skip_leading_whitespace(const char *str)
{
	while (*str && my_isspace(*str))
		str++;
	return (str);
}

static const char	*find_trimmed_end(const char *start_ptr,
		const char *original_end)
{
	while (original_end >= start_ptr && (my_isspace(*original_end)
			|| *original_end == '\n'))
		original_end--;
	return (original_end);
}

static int	validate_no_trailing_chars(const char *trimmed_end_ptr)
{
	const char	*check_after_end = trimmed_end_ptr + 1;

	while (*check_after_end && my_isspace(*check_after_end))
		check_after_end++;
	if (*check_after_end != '\0' && *check_after_end != '\n')
	{
		printf(ANSI_COLOR_RED "Error:" ANSI_COLOR_RESET " \
        Unexpected characters after value on element line: [%s]\n",
			check_after_end);
		return (0);
	}
	return (1);
}

static void	initialize_line_pointers(const char *line,
		const char **start_ptr_out, const char **original_line_end_out)
{
	*original_line_end_out = line + ft_strlen(line) - 1;
	*start_ptr_out = skip_leading_whitespace(line);
}

char	*get_trimmed_value_from_line(const char *line_after_space)
{
	const char	*start_ptr;
	const char	*end_ptr;
	char		*value;
	size_t		len;
	const char	*original_line_end;

	initialize_line_pointers(line_after_space, &start_ptr, &original_line_end);
	if (*start_ptr == '\0' || *start_ptr == '\n')
	{
		printf(ANSI_COLOR_RED "Error:" ANSI_COLOR_RESET "No value after id.\n");
		return (NULL);
	}
	end_ptr = find_trimmed_end(start_ptr, original_line_end);
	if (end_ptr < start_ptr)
	{
		printf(ANSI_COLOR_RED "Error:" ANSI_COLOR_RESET "Value' ' after id.\n");
		return (NULL);
	}
	if (!validate_no_trailing_chars(end_ptr))
		return (NULL);
	len = (end_ptr - start_ptr) + 1;
	value = ft_substr(start_ptr, 0, len);
	if (!value)
		printf(ANSI_COLOR_RED "Error:" ANSI_COLOR_RESET " Malloc failed!\n");
	return (value);
}
