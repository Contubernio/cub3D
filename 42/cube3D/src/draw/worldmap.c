/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worldmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:38:39 by albealva          #+#    #+#             */
/*   Updated: 2025/06/14 22:29:08 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
char	worldMap2[MAP_HEIGHT][MAP_WIDTH + 1] = {"1D1111111111", "1S  00000001",
		"10001O101101", "100000100001", "110011101101", "100000000001",
		"10 011101101", "100000100001", "100011101101", "100000000001",
		"100011101101", "100000100001", "1001 1101101", "100000000001",
		"100000000001", "100000000001", "111111111O11"};

///esta parte es par poder trabajar posteriormente con el data->map de Gast'on

void	allocate_worldmap(t_game *game)
{
	int	i;

	game->worldmap = malloc(sizeof(char *) * (MAP_HEIGHT));
	if (!game->worldmap)
		clean_exit(game, "Error: Memory allocation failed");
	i = 0;
	while (i < MAP_HEIGHT)
	{
		game->worldmap[i] = malloc(sizeof(char) * (MAP_WIDTH + 1));
		if (!game->worldmap[i])
			clean_exit(game, "Error: Memory allocation failed");
		i++;
	}
	game->worldmap[MAP_HEIGHT] = NULL;
}

void	traspase_worldmap2_to_worldmap_pre(t_game *game,
		char worldmap2[MAP_HEIGHT][MAP_WIDTH +1 ])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(void)worldmap2;
	while (i <MAP_HEIGHT)
	{
		while (j < MAP_WIDTH +1)
		{
			game->worldmap[i][j] = worldMap2[i][j];
			j++;
		}
		game->worldmap[i][MAP_WIDTH] = '\0';
		j = 0;
		i++;
	}
}

void	traspase_worldmap2_to_worldmap(t_game *game,
		char worldmap2[MAP_HEIGHT][MAP_WIDTH + 1])
{
	int	i;

	i = 0;
	while (i < MAP_HEIGHT)
	{
	
		strncpy(game->worldmap[i], worldmap2[i], MAP_WIDTH);
	.
		game->worldmap[i][MAP_WIDTH] = '\0';
		i++;
	}
	// Recordatorio: Asegúrate de que game->worldmap[MAP_HEIGHT] = NULL;
	// se haga en allocate_worldmap.
}

int	init_worldmap_pre(t_game *game)
{
	int	i;
	int	j;

	printf("entro en la funcion init_map \n");
	game->worldmap = malloc(MAP_HEIGHT * sizeof(char *));
	if (!game->worldmap)
		return (clean_exit(game, "Error: Failed to allocate memory for map."));
	i = 0;
	while (i < MAP_HEIGHT)
	{
		game->worldmap[i] = malloc((MAP_WIDTH + 1) * sizeof(char));
		if (!game->worldmap[i])
			return (clean_exit(game,
					"Error: Failed to allocate memory for map row."));
		j = 0;
		while (j <= MAP_WIDTH)
		{
			//printf("entra en el bucle n veces \n");
			game->worldmap[i][j] = worldMap2[i][j];
			//game->map[i][j] = game->worldmap[i][j];
			j++;
		}
		i++;
	}
	return (0);
}
*/
/*
int	init_worldmap(t_game *game)
{
	int	i;

	// Comprobación de seguridad
	if (!game || !game->data || !game->data->map)
	{
		printf(ANSI_COLOR_RED "Error:" 
        ANSI_COLOR_RESET " Cannot duplicate map,
			game->data->map is NULL.\n");
		return (1);
	}
	// 1. Reservar memoria para el nuevo array de punteros (filas)
	// Se reserva espacio para game->data->map_height punteros
		+ 1 para el puntero NULL final.
	game->worldmap = (char **)malloc((game->data->map_height + 1)
			* sizeof(char *));
	if (game->worldmap == NULL)
	{
    
		printf(ANSI_COLOR_RED "Error:"
         ANSI_COLOR_RESET " Malloc failed for game->worldmap.\n");
		return (1);
	}
	// 2. Recorrer el mapa original y duplicar cada fila
	i = 0;
	while (i < game->data->map_height)
	{
		// ft_strdup reserva memoria para la nueva cadena y copia el contenido
		game->worldmap[i] = ft_strdup(game->data->map[i]);
		if (game->worldmap[i] == NULL)
		{
			printf(ANSI_COLOR_RED "Error:" 
            ANSI_COLOR_RESET " ft_strdup failed for a map row.\n");
			// Si falla,
				hay que liberar todo lo que se haya reservado hasta ahora
			free_char_array(game->worldmap);
			game->worldmap = NULL;
			return (1);
		}
		i++;
	}
	// 3. Añadir el puntero NULL al final del array de punteros
	game->worldmap[i] = NULL;
	printf(ANSI_COLOR_YELLOW "DEBUG:" ANSI_COLOR_RESET " A deep copy
     of the map has been created in game->worldmap.\n");
	return (0);
}
*/
/*


void	assign_hardcoded_worldmap(t_game *game)
{
	// NO declarar char fixed_map_data[MAP_HEIGHT][MAP_WIDTH + 1] aquí.
	// Simplemente usamos los literales de cadena directamente.
	// Puedes imprimir para depurar si el mapa se está inicializando
	printf("Asignando game->worldmap directamente con literales de cadena...\n");
	// Asignación directa de cada fila de game->worldmap a un literal de cadena.
	// Esto asume que game->worldmap[y] ya fue asignado previamente con malloc
	// y tiene espacio para MAP_WIDTH + 1 caracteres.
	// strcpy copiará los caracteres y el '\0' final.
	strcpy(game->worldmap[0], "1D1111111111");
	strcpy(game->worldmap[1], "1S  00000001");
	strcpy(game->worldmap[2], "10001O101101");
	strcpy(game->worldmap[3], "100000100001");
	strcpy(game->worldmap[4], "110011101101");
	strcpy(game->worldmap[5], "100000000001");
	strcpy(game->worldmap[6], "100011101101");
	strcpy(game->worldmap[7], "100000100001");
	strcpy(game->worldmap[8], "100011101101");
	strcpy(game->worldmap[9], "100000000001");
	strcpy(game->worldmap[10], "100011101101");
	strcpy(game->worldmap[11], "100000100001");
	strcpy(game->worldmap[12], "1001 1101101");
	strcpy(game->worldmap[13], "100000000001");
	strcpy(game->worldmap[14], "100000000001");
	strcpy(game->worldmap[15], "100000000001");
	strcpy(game->worldmap[16], "111111111O11");
	// No necesitas asignar el NULL final aquí,
		porque allocate_worldmap ya lo hace.
}
*/

void	convert_od_to_1(char map[MAP_HEIGHT][MAP_WIDTH + 1])
{
	int	i;
	int	j;

	i = 0;
	while (i < MAP_HEIGHT)
	{
		j = 0;
		while (j < MAP_WIDTH)
		{
			if (map[i][j] == 'O' || map[i][j] == 'D')
			{
				map[i][j] = '1';
			}
			j++;
		}
		i++;
	}
}
