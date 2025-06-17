/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:41:38 by albealva          #+#    #+#             */
/*   Updated: 2025/06/14 22:01:24 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
void	render_m2(t_game *game)
{
	if (!game->hud || !game->hud[2].img_ptr)
		return ;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->hud[2].img_ptr,
		50, 675);
}*/

void	render_m3(t_game *game)
{
	struct timeval	now;
	long			elapsed_ms;

	if (!game->hud || !game->hud[3].img_ptr)
		return ;
	if (!game->hud_message)
		return ;
	gettimeofday(&now, NULL);
	elapsed_ms = (now.tv_sec - game->hud_timer.tv_sec) * 1000 + (now.tv_usec
			- game->hud_timer.tv_usec) / 1000;
	if (elapsed_ms < 2000)
	{
		render_m1(game);
	}
	else
	{
		game->hud_message = false;
	}
}
