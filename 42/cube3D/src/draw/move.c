/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:41:10 by albealva          #+#    #+#             */
/*   Updated: 2025/06/14 21:28:01 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	is_player_moving(t_game *game)
{
	return (game->keys.w || game->keys.s || game->keys.a || game->keys.d
		|| game->keys.left || game->keys.right);
}

static bool	is_out_of_bounds(t_game *game, t_bounds b)
{
	if (b.x0 < 0 || b.x1 >= game->data->map_width || b.y0 < 0
		|| b.y1 >= game->data->map_height)
	{
		return (true);
	}
	if (game->data->map[b.y0][b.x0] == '2')
		return (true);
	if (game->data->map[b.y0][b.x1] == '2')
		return (true);
	if (game->data->map[b.y1][b.x0] == '2')
		return (true);
	if (game->data->map[b.y1][b.x1] == '2')
		return (true);
	return (false);
}
/*
bool	check_cell_collision_testing(t_game *game, char cell_char)
{
	if (cell_char == '1' || cell_char == 'D' || cell_char == ' ')
	{
		printf("DEBUG: Colision detectada con el caracter '%c'.\n", cell_char);
		if (cell_char == ' ')
		{
			game->hud_message2 = true;
			gettimeofday(&game->hud_timer, NULL);
			printf("DEBUG: Colision con espacio detectada.
			 hud_message2 = true. Timer reset.\n");
		}
		return (true);
	}
	return (false);
}*/

static bool	check_cell_collision(t_game *game, char cell_char)
{
	bool	is_collision_char;

	(void)game;
	is_collision_char = false;
	if (cell_char == '1')
		is_collision_char = true;
	else if (cell_char == 'D')
		is_collision_char = true;
	else if (cell_char == ' ')
		is_collision_char = true;
	if (is_collision_char)
		return (true);
	return (false);
}

static bool	has_collision(t_game *game, t_bounds b)
{
	char	**map;

	map = game->data->map;
	if (check_cell_collision(game, map[b.y0][b.x0]))
		return (true);
	if (check_cell_collision(game, map[b.y0][b.x1]))
		return (true);
	if (check_cell_collision(game, map[b.y1][b.x0]))
		return (true);
	if (check_cell_collision(game, map[b.y1][b.x1]))
		return (true);
	return (false);
}

bool	is_valid_move(t_game *game, double new_x, double new_y)
{
	t_bounds	b;
	double		r;

	r = PLAYER_RADIUS;
	b.x0 = (int)(new_x - r);
	b.y0 = (int)(new_y - r);
	b.x1 = (int)(new_x + r);
	b.y1 = (int)(new_y + r);
	if (is_out_of_bounds(game, b))
		return (false);
	if (BONUS)
	{
		if (has_collision(game, b))
			return (false);
	}
	else if (b.x0 == 0 || b.x1 == game->data->map_width - 1 || b.y0 == 0
		|| b.y1 == game->data->map_height - 1)
		return (false);
	return (true);
}
