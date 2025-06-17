/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 22:19:20 by albealva          #+#    #+#             */
/*   Updated: 2025/06/14 22:25:30 by contubernio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	handle_state_intro(t_game *game)
{
	update_player(game);
	update_intro_sequence(game);
	render(game);
	render_hands(game);
	render_mask(game);
}

void	handle_state_transition(t_game *game)
{
	draw_fullscreen_color(game, 0xFFFFFF);
	perform_game_transition(game);
}

void	handle_playing_bonus(t_game *game)
{
	update_player(game);
	update_hands_animation(game);
	render(game);
	render_hands(game);
	render_hud(game);
	render_m3(game);
	render_mask(game);
}

void	handle_bonus_logic(t_game *game)
{
	if (game->game_state == STATE_SPLASH)
		update_splash_sequence(game);
	else if (game->game_state == STATE_INTRO)
		handle_state_intro(game);
	else if (game->game_state == STATE_TRANSITION)
		handle_state_transition(game);
	else if (game->game_state == STATE_PLAYING)
		handle_playing_bonus(game);
}

void	handle_mandatory_logic(t_game *game)
{
	if (game->game_state == STATE_PLAYING)
	{
		update_player(game);
		render(game);
	}
}
