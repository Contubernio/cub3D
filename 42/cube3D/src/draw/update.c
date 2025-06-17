/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:06:54 by albealva          #+#    #+#             */
/*   Updated: 2025/06/14 22:27:09 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	rotate_player(t_game *game)
{
	if (game->keys.left)
		game->william.playerangle -= MOVE_SPEED;
	if (game->keys.right)
		game->william.playerangle += MOVE_SPEED;
}

static void	handle_mouse_rotation(t_game *game)
{
	int	delta_x;
	int	mouse_x;
	int	mouse_y;

	delta_x = 0;
	mlx_mouse_get_pos(game->mlx_ptr, game->win_ptr, &mouse_x, &mouse_y);
	if (mouse_x <= 0)
		delta_x = -1;
	else if (mouse_x >= WIN_WIDTH - 1)
		delta_x = 1;
	else
	{
		delta_x = mouse_x - game->last_mouse_x;
		game->last_mouse_x = mouse_x;
	}
	game->william.playerangle += delta_x * ROTATE_SPEED;
}

static void	normalize_angle_and_update_direction(t_game *game)
{
	double	plane_magnitude;

	if (game->william.playerangle < 0)
		game->william.playerangle += 2 * M_PI;
	if (game->william.playerangle >= 2 * M_PI)
		game->william.playerangle -= 2 * M_PI;
	game->william.dir_x = cos(game->william.playerangle);
	game->william.dir_y = sin(game->william.playerangle);
	plane_magnitude = 0.66;
	game->william.plane_x = -game->william.dir_y * plane_magnitude;
	game->william.plane_y = game->william.dir_x * plane_magnitude;
}

static void	update_player_position_on_map(t_game *game)
{
	static t_player_map_state	state = {.old_x = -1};

	if (!game || !game->data || !game->data->map)
		return ;
	if (state.old_x != -1)
	{
		if (state.old_y < game->data->map_height
			&& state.old_x < game->data->map_width)
			game->data->map[state.old_y][state.old_x] = state.old_cell;
	}
	state.new_x = (int)game->william.x;
	state.new_y = (int)game->william.y;
	if (state.new_y < 0 || state.new_y >= game->data->map_height
		|| state.new_x < 0 || state.new_x >= game->data->map_width)
		return ;
	state.old_cell = game->data->map[state.new_y][state.new_x];
	game->data->map[state.new_y][state.new_x] = 'P';
	state.old_x = state.new_x;
	state.old_y = state.new_y;
}

void	update_player(t_game *game)
{
	move_player(game);
	rotate_player(game);
	if (BONUS)
		handle_mouse_rotation(game);
	normalize_angle_and_update_direction(game);
	update_player_position_on_map(game);
}
