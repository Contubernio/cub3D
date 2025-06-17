/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_william.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:51:07 by albealva          #+#    #+#             */
/*   Updated: 2025/05/23 08:43:21 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->william.x + game->william.dir_x * MOVE_SPEED;
	new_y = game->william.y + game->william.dir_y * MOVE_SPEED;
	if (is_valid_move(game, new_x, new_y))
	{
		game->william.x = new_x;
		game->william.y = new_y;
	}
}

static void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->william.x - game->william.dir_x * MOVE_SPEED;
	new_y = game->william.y - game->william.dir_y * MOVE_SPEED;
	if (is_valid_move(game, new_x, new_y))
	{
		game->william.x = new_x;
		game->william.y = new_y;
	}
}

static void	strafe_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->william.x + game->william.dir_y * MOVE_SPEED;
	new_y = game->william.y - game->william.dir_x * MOVE_SPEED;
	if (is_valid_move(game, new_x, new_y))
	{
		game->william.x = new_x;
		game->william.y = new_y;
	}
}

static void	strafe_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->william.x - game->william.dir_y * MOVE_SPEED;
	new_y = game->william.y + game->william.dir_x * MOVE_SPEED;
	if (is_valid_move(game, new_x, new_y))
	{
		game->william.x = new_x;
		game->william.y = new_y;
	}
}

void	move_player(t_game *game)
{
	if (game->keys.w)
		move_forward(game);
	if (game->keys.s)
		move_backward(game);
	if (game->keys.a)
		strafe_left(game);
	if (game->keys.d)
		strafe_right(game);
}
