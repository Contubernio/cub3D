/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:53:05 by gasroman          #+#    #+#             */
/*   Updated: 2025/06/15 12:46:41 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
int	count_map_pre(t_game *game, char *line)
{
	static int	j = 0;

	if (j == 0 && line[0] == '\n')
		return (tru);
	game->data->map = \
		ft_double_realloc(game->data->map, (j + 2) * sizeof(char *));
	if (!game->data->map)
		return (fals);
	game->data->map[j] = ft_strdup(line);
	if (!game->data->map[j])
		return (fals);
	j++;
	return (tru);
}

int	count_map(t_game *game, char *line)
{
	static int	j = 0;

	if (!line) // Añadimos una comprobación por si line es NULL
	{
		printf("count_map: ADVERTENCIA - se recibió una línea 
		NULL (EOF probable), j=%d. No se procesa.\n", j);+
		
		// Dependiendo de tu lógica, podrías querer retornar 
		fals aquí si una línea NULL no debería llegar
		// o si significa el final y el mapa debería estar terminado.
		// Por ahora, solo lo reportamos y no la procesamos
		 si es NULL para evitar ft_strdup(NULL) sin control.
		return (tru); // O fals si esto es un error que debe detener el parseo.
	}

	if (j == 0 && line[0] == '\n')
		return (tru);
	game->data->map = \
		ft_double_realloc(game->data->map, (j + 2) * sizeof(char *));
	if (!game->data->map)
		return (fals);
	game->data->map[j] = ft_strdup(line);

	// --- INSTRUCCIÓN DE DEBUG AÑADIDA ---
	printf("DEBUG count_map: Fila j=%d, Puntero asignado
	game->data->map[j]=%p, Contenido línea (aprox): \"%.40s\"\n",
		   j,
		   (void *)game->data->map[j],
		   line); // "%.40s" imprime hasta 40 caracteres 
		   de la línea para evitar salidas muy largas
	// --- FIN DE INSTRUCCIÓN DE DEBUG ---

	if (!game->data->map[j])
		return (fals); // Esta línea ya la tenías, es para 
		el caso de que ft_strdup falle y devuelva NULL.
	j++;
	return (tru);
}

*/