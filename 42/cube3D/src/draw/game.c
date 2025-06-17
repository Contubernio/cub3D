/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:36:17 by albealva          #+#    #+#             */
/*   Updated: 2025/06/15 12:37:39 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
int	close_hook(void *param)
{
	return (clean_exit(param, "Ventana cerrada"));
}

int	game_loop(t_game *game)
{
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, key_release, game);
	mlx_loop_hook(game->mlx_ptr, update_and_render, game);
	mlx_hook(game->win_ptr, 17, 0, close_hook, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}

void	print_intro(int is_bonus)
{
	printf("\n");
	printf("  ██████╗ ██╗   ██╗██████╗ ███████╗█████╗ ██████╗ \n");
	printf("  ██╔═══╝ ██║   ██║██╔══██╗██╔════╝════██╗██   ██╗\n");
	printf("  ██║     ██║   ██║██████╔╝█████╗  ██████║██   ██║ \n");
	printf("  ██╚═══╗ ██║   ██║██╔══██╗██╔══╝      ██╝██   ██║ \n");
	printf("  ██████║ ╚██████╔╝██████╔╝███████╗█████║ ██████╔╝     \n");
	printf("  ╚═════╝  ╚═════╝ ╚═════╝ ╚══════╝╚════╝ ╚═════╝     \n");
	printf("\n");
	printf("        Bienvenido a cub3D: ¡Explora y sobrevive!\n");
	printf("\n");
	printf(" Controles:\n");
	printf("  - W, A, S, D     → Mover al jugador\n");
	printf("  - ←, →           → Rotar la cámara\n");
	printf("  - ESC            → Salir del juego\n");
	if (is_bonus)
	{
		printf("  - Ratón          → Rotación adicional de cámara\n");
		printf("  - ESPACIO        → Interactuar con puertas\n");
	}
	printf("\n¡Buena suerte, aventurero!\n\n");
}
/*
int print_worldmap_debug(t_game *game)
{
    printf("\n--- Debugging game->worldmap Content ---\n");

    if (game == NULL || game->data->map == NULL)
    {
        printf("Error: game o game->data->map es NULL. No se puede imprimir.\n");
        return;
    }

    int y = 0;
    // Bucle para iterar a través de las filas (punteros)
    // Usamos 'y < MAP_HEIGHT' porque sabemos el número de filas esperadas.
    // Si la última entrada es NULL, también podemos usar 'game->worldmap[y]'
    // pero si sospechamos un NULL faltante, es más seguro usar
     el límite conocido.
    while (game->data->map[y]) // Puedes extender el límite para ver 
    si hay punteros después de MAP_HEIGHT
    {
        printf("Fila %d [Addr: %p]: ", y, (void *)game->data->map[y]);

        if (game->data->map[y] == NULL)
        {
            printf("[NULL PTR]\n");
            break; // Si encontramos un NULL, asumimos 
            que es el fin del array de punteros
        }

        // Si el puntero de la fila no es NULL, intenta imprimir sus caracteres
        int x = 0;
        char current_char;
        while (game->data->map[y][x]) // Iteramos hasta
         MAP_WIDTH para ver el carácter 
        en la posición MAP_WIDTH (que debería ser '\0')
        {
            // Protección extra para evitar SEGV si la 
            fila no tiene el tamaño esperado
            // Es poco probable que necesites esto si malloc 
            funciona, pero por seguridad
            if (game->data->map[y] == NULL)
            {
                 printf(" [ERROR: Fila NULL inesperada a mitad]\n");
                 break;
            }

            current_char = game->data->map[y][x];

            if (current_char == '\0')
            {
                printf("['\\0'] "); // Imprime la indicación del terminador nulo
                // Si encuentras '\0' y esperas que la cadena termine aquí, 
                puedes romper el bucle.
                // Si quieres ver si hay más 'basura' después del '\0',
                 no rompas.
                // Para depuración, a veces es útil seguir para ver
                 qué hay después.
                break; // Romper aquí si solo quieres ver hasta el primer \0
            }
            else if (current_char == ' ')
            {
                printf("[' '] "); // Para distinguir espacios de otros caracteres
            }
            else if (current_char >= 32 && current_char <= 126) // Caracteres 
            imprimibles ASCII
            {
                printf("['%c'] ", current_char);
            }
            else
            {
                printf("[0x%02X] ", (unsigned char)current_char); 
                // Imprime el valor
                 hexadecimal de caracteres no imprimibles
            }
            x++;
        }
        printf("\n"); // Nueva línea para la siguiente fila
        y++;
    }
    printf("--- End of worldmap debug ---\n\n");
}


int	main_none(void)
{
	t_game	game;
	int		mouse_x;
	int		mouse_y;

	print_intro(BONUS);
	init_game3(&game);
	initialize_game_struct(&game);
	if (init_game(&game))
	{
		printf("main: Error en init_game\n");
		return (1);
	}
	//allocate_worldmap(&game);
	//traspase_worldmap2_to_worldmap(&game, worldMap2);
	//assign_hardcoded_worldmap(&game);
	//init_worldmap(&game);
	//print_worldmap_debug(&game);
	mlx_mouse_get_pos(game.mlx_ptr, game.win_ptr, &mouse_x, &mouse_y);
	center_mouse(&game);
	game.william.mouse_x = mouse_x;
	game.william.last_mouse_x = mouse_x;
	game_loop(&game);
	return (0);
}
*/