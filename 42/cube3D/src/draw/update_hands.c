/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_hands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:53:20 by albealva          #+#    #+#             */
/*   Updated: 2025/06/14 22:26:32 by contubernio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	update_hands_animation(t_game *game)
{
	if (!is_player_moving(game))
		return ;
	game->hand_animation_timer++;
	if (game->hand_animation_timer >= 3)
	{
		game->current_hand_frame = (game->current_hand_frame + 1) % 5;
		game->hand_animation_timer = 0;
	}
}

void	update_player_state(t_player_map_state *state, t_game *game)
{
	state->old_x = -1;
	state->old_y = -1;
	state->old_cell = '0';
	state->new_x = (int)game->william.x;
	state->new_y = (int)game->william.y;
	state->player_char = 'W';
}
