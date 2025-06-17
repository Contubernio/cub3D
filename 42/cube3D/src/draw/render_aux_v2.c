/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_aux_v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:05:37 by albealva          #+#    #+#             */
/*   Updated: 2025/06/14 21:32:10 by contubernio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	draw_texture_column(t_game *game, t_render *render)
{
	int	y;
	int	d;
	int	tex_y;

	y = render->drawstart;
	while (y < render->drawend)
	{
		d = y * 256 - WIN_HEIGHT * 128 + render->lineheight * 128;
		tex_y = ((d * TEX_HEIGHT) / render->lineheight) / 256;
		if (tex_y < 0 || tex_y >= render->tex->height)
			break ;
		render->color = render->tex->data[tex_y * (render->tex->line_length / 4)
			+ render->tex_x];
		game->img_data[y * WIN_WIDTH + render->x] = render->color;
		y++;
	}
}

void	draw_texture_on_wall(t_game *game, t_render *render)
{
	render->tex_x = (int)(render->wall_x * (double)TEX_WIDTH);
	if ((render->side == 0 && render->raydir_x > 0) || (render->side == 1
			&& render->raydir_y < 0))
		render->tex_x = TEX_WIDTH - render->tex_x - 1;
	render->wall_info.wall_type = game->data->map[render->map_y][render->map_x];
	render->wall_info.side = render->side;
	render->wall_info.raydir_x = render->raydir_x;
	render->wall_info.raydir_y = render->raydir_y;
	render->tex = get_texture_for_wall(game, render->wall_info);
	if (!render->tex || !render->tex->data)
		return ;
	if (render->tex_x < 0 || render->tex_x >= render->tex->width)
		return ;
	draw_texture_column(game, render);
}

void	init_minimap_vars(t_render *render, t_game *game)
{
	render->minimap_area_width = game->data->map_width * 10;
	render->minimap_area_height = game->data->map_height * 10;
	render->minimap_offset_x = 10;
	render->minimap_offset_y = WIN_HEIGHT - render->minimap_area_height - 10;
}

void	render_walls(t_game *game, t_render *render)
{
	while (render->x < WIN_WIDTH)
	{
		calculate_ray_vars(game, render);
		perform_ray_casting(game, render);
		calculate_wall_properties(game, render);
		draw_texture_on_wall(game, render);
		render->x++;
	}
}

void	clear_minimap_area(t_game *game, t_render *render)
{
	(void)game;
	render->y = render->minimap_offset_y;
	while (render->y < render->minimap_offset_y + render->minimap_area_height)
	{
		render->x = render->minimap_offset_x;
		while (render->x < render->minimap_offset_x
			+ render->minimap_area_width)
		{
			render->x++;
		}
		render->y++;
	}
}
