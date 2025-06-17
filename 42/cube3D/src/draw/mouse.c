/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:38:11 by albealva          #+#    #+#             */
/*   Updated: 2025/05/23 08:43:14 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	center_mouse(t_game *game)
{
	int	center_x;
	int	center_y;

	center_x = WIN_WIDTH / 2;
	center_y = WIN_HEIGHT / 2;
	mlx_mouse_move(game->mlx_ptr, game->win_ptr, center_x, center_y);
}

int	handle_mouse(int x, int y, void *param)
{
	t_mouse_bonus	*data;

	data = (t_mouse_bonus *)param;
	(void)y;
	if (data->william->release_mouse)
	{
		if (x > data->mouse_pos)
			data->william->turndirection = 1;
		else if (x < data->mouse_pos)
			data->william->turndirection = -1;
		data->mouse_pos = x;
	}
	printf("Mouse moved! x=%d\n", x);
	return (0);
}

int	mouse_press(int key, int x, int y, t_mouse_bonus *data)
{
	if (key == 1 && x >= 0 && x <= WIN_WIDTH && y >= 0 && y <= WIN_HEIGHT)
	{
		data->mouse_pos = x;
		data->william->release_mouse = 1;
	}
	return (0);
}

int	mouse_release(int key, int x, int y, t_mouse_bonus *data)
{
	(void)x;
	(void)y;
	if (key == 1)
	{
		data->william->release_mouse = 0;
		data->william->turndirection = 0;
	}
	return (0);
}
