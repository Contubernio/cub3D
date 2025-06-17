/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:07:22 by gasroman          #+#    #+#             */
/*   Updated: 2025/06/15 01:51:39 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static short	is_empty(char *line)
{
	return (!line || !line[0] || (line[0] == '\n'));
}

char	**process_line_pre(char *line)
{
	if (is_empty(line))
	{
		free(line);
		return (NULL);
	}
	if (!line || line[0] == '\0')
	{
		free(line);
		return (printf("Processing Line Error\n"), NULL);
	}
	return (ft_split_set(line, ' ', '\t'));
}
/*
char	**process_line(char *line)
{
	if (is_empty(line))
	{
		// NO HACER free(line); aquí
		return (NULL); // Simplemente indica que la línea está vacía
	}
	if (!line || line[0] == '\0')
		// Esta condición es redundante si is_empty ya la cubre bien
	{
		// NO HACER free(line); aquí tampoco
		 si is_empty ya manejó el caso !line
		// Si esta condición es para un caso diferente a is_empty,
			evalúa si free es necesario
		// pero basado en el error,
			el problema es con las líneas vacías/newline.
		printf("Processing Line Error\n");
			// Considera si este error es 
			realmente necesario o si NULL es suficiente.
		return (NULL);
	}
	return (ft_split_set(line, ' ', '\t'));
		// Asumiendo que ft_split_set no libera 'line'
}
*/