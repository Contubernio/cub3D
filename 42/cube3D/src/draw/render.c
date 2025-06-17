/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:20:51 by albealva          #+#    #+#             */
/*   Updated: 2025/06/14 22:22:38 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	render(t_game *game)
{
	t_render	render;

	init_render_str(&render);
	init_render_vars(game, &render);
	render_walls(game, &render);
	init_minimap_vars(&render, game);
	if (BONUS)
		render_minimap(game, &render);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_ptr, 0, 0);
	return (0);
}

static void	init_hand_vars(t_game *game, t_rhand *hand)
{
	hand->current_hand = game->hands[game->current_hand_frame];
	hand->data = hand->current_hand.data;
	hand->width = hand->current_hand.width;
	hand->height = hand->current_hand.height;
	hand->line_len = hand->current_hand.line_length / 4;
	hand->alpha = ((int *)hand->current_hand.data)[0] >> 24 & 0xFF;
	hand->y = 0;
}

static void	calculate_draw_coords(t_game *game, t_rhand *hand)
{
	hand->draw_x = game->hands_x + hand->x;
	hand->draw_y = game->hands_y + hand->y;
}

void	render_hands(t_game *game)
{
	t_rhand	hand;

	if (game->current_hand_frame >= 0 && game->current_hand_frame < 5
		&& game->hands)
	{
		init_hand_vars(game, &hand);
		while (hand.y < hand.height)
		{
			hand.x = 0;
			while (hand.x < hand.width)
			{
				hand.color = hand.data[hand.y * hand.line_len + hand.x];
				if (hand.color != hand.alpha)
				{
					calculate_draw_coords(game, &hand);
					if (hand.draw_x >= 0 && hand.draw_x < WIN_WIDTH
						&& hand.draw_y >= 0 && hand.draw_y < WIN_HEIGHT)
						game->img_data[hand.draw_y * WIN_WIDTH
							+ hand.draw_x] = hand.color;
				}
				hand.x++;
			}
			hand.y++;
		}
	}
}

/*
int	update_and_render(t_game *game)
{
#if BONUS
	if (game->game_state == STATE_SPLASH)
		update_splash_sequence(game);
	else if (game->game_state == STATE_INTRO)
	{
		update_player(game);
		update_intro_sequence(game);
		render(game);
		if (BONUS)
		{
			render_hands(game);
			render_mask(game);
		}
	}
	else if (game->game_state == STATE_TRANSITION)
	{
		draw_fullscreen_color(game, 0xFFFFFF);
		perform_game_transition(game);
	}
	else if (game->game_state == STATE_PLAYING)
#else
	if (game->game_state == STATE_PLAYING)
#endif
	{
		update_player(game);
		if (BONUS)
			update_hands_animation(game);
		render(game);
		if (BONUS)
		{
			render_hands(game);
			render_hud(game);
			render_m3(game);
			render_mask(game);
		}
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_ptr, 0, 0);
	return (0);
}
*/
/*
static void	handle_state_splash(t_game *game)
{
	update_splash_sequence(game);
}
*/
int	update_and_render(t_game *game)
{
	if (BONUS)
		handle_bonus_logic(game);
	else
		handle_mandatory_logic(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_ptr, 0, 0);
	return (0);
}
