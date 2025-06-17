/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_realloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:23:47 by gasroman          #+#    #+#             */
/*   Updated: 2025/05/23 08:45:29 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	**ft_double_realloc(char **ptr, size_t new_size)
{
	char	**new_ptr;
	size_t	old_size;
	size_t	size_to_copy;

	if (ptr == NULL)
		return (ft_calloc(new_size, sizeof(char *)));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = ft_calloc(new_size, sizeof(char *));
	if (!new_ptr)
		return (NULL);
	old_size = 0;
	while (ptr[old_size] != NULL)
		old_size++;
	if (old_size < new_size)
		size_to_copy = old_size;
	else
		size_to_copy = new_size;
	ft_memcpy(new_ptr, ptr, size_to_copy * sizeof(char *));
	free(ptr);
	return (new_ptr);
}
