/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:21:05 by albealva          #+#    #+#             */
/*   Updated: 2025/06/14 21:21:16 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	key_release(int keycode, t_game *game)
{
	if (keycode == K_W)
		game->keys.w = 0;
	else if (keycode == K_S)
		game->keys.s = 0;
	else if (keycode == K_A)
		game->keys.a = 0;
	else if (keycode == K_D)
		game->keys.d = 0;
	else if (keycode == K_LEFT)
		game->keys.left = 0;
	else if (keycode == K_RIGHT)
		game->keys.right = 0;
	else if (keycode == K_SPACE)
	{
		game->keys.space_pressed = 0;
	}
	else if (keycode == K_ESC)
		game->keys.esc = 0;
	return (0);
}

void	toggle_magic_wall(t_game *game, int x, int y)
{
	(void)x;
	(void)y;
	game->hud_message2 = true;
	gettimeofday(&game->hud_timer, NULL);
}
