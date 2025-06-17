/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_aux_v3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:34:24 by albealva          #+#    #+#             */
/*   Updated: 2025/06/14 21:33:12 by contubernio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	render_minimap(t_game *game, t_render *render)
{
	clear_minimap_area(game, render);
	draw_minimap(game);
	render->minimap_scale_x = (double)render->minimap_area_width
		/ (game->data->map_width * 8);
	render->minimap_scale_y = (double)render->minimap_area_height
		/ (game->data->map_height * 8);
	if (render->minimap_scale_x < render->minimap_scale_y)
		render->minimap_scale = render->minimap_scale_x;
	else
		render->minimap_scale = render->minimap_scale_y;
}

void	init_ray_direction(t_game *game, t_render *render)
{
	render->camera_x = 2.0 * render->x / WIN_WIDTH - 1.0;
	render->raydir_x = game->william.dir_x + game->william.plane_x
		* render->camera_x;
	render->raydir_y = game->william.dir_y + game->william.plane_y
		* render->camera_x;
	render->map_x = (int)game->william.x;
	render->map_y = (int)game->william.y;
}

void	perform_ray_casting(t_game *game, t_render *render)
{
	char	current_cell;

	while (!render->hit)
	{
		if (render->sidedist_x < render->sidedist_y)
		{
			render->sidedist_x += render->deltadist_x;
			render->map_x += render->step_x;
			render->side = 0;
		}
		else
		{
			render->sidedist_y += render->deltadist_y;
			render->map_y += render->step_y;
			render->side = 1;
		}
		current_cell = game->data->map[render->map_y][render->map_x];
		if (current_cell == '1' || current_cell == '2' || current_cell == 'D')
			render->hit = 1;
	}
}

void	calculate_wall_properties(t_game *game, t_render *render)
{
	if (render->side == 0)
		render->perpwalldist = (render->map_x - game->william.x + (1
					- render->step_x) / 2.0) / render->raydir_x;
	else
		render->perpwalldist = (render->map_y - game->william.y + (1
					- render->step_y) / 2.0) / render->raydir_y;
	if (render->perpwalldist < 0.0001)
		render->perpwalldist = 0.0001;
	render->lineheight = (int)(WIN_HEIGHT / render->perpwalldist);
	if (render->lineheight < 1)
		render->lineheight = 1;
	render->drawstart = -render->lineheight / 2 + WIN_HEIGHT / 2;
	if (render->drawstart < 0)
		render->drawstart = 0;
	render->drawend = render->lineheight / 2 + WIN_HEIGHT / 2;
	if (render->drawend >= WIN_HEIGHT)
		render->drawend = WIN_HEIGHT - 1;
	if (render->side == 0)
		render->wall_x = game->william.y + render->perpwalldist
			* render->raydir_y;
	else
		render->wall_x = game->william.x + render->perpwalldist
			* render->raydir_x;
	render->wall_x -= floor(render->wall_x);
}

void	draw_scaled_minimap(t_game *game, t_render *render)
{
	int	scaled_x;
	int	scaled_y;

	render->y = 0;
	while (render->y < MINIMAP_HEIGHT)
	{
		render->x = 0;
		while (render->x < MINIMAP_WIDTH)
		{
			scaled_x = (int)(render->x * render->minimap_scale);
			scaled_y = (int)(render->y * render->minimap_scale);
			if (scaled_x >= 0 && scaled_x < render->minimap_area_width
				&& scaled_y >= 0 && scaled_y < render->minimap_area_height)
			{
				game->img_data[(render->minimap_offset_y + scaled_y) * WIN_WIDTH
					+ (render->minimap_offset_x
						+ scaled_x)] = game->minimap_img_data[render->y
					* game->minimap_line_length / 4 + render->x];
			}
			render->x++;
		}
		render->y++;
	}
}
