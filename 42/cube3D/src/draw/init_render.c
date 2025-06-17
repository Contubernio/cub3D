/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:08:57 by albealva          #+#    #+#             */
/*   Updated: 2025/05/23 08:41:54 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	init_ray_info(t_render *r)
{
	r->total_pixels = 0;
	r->fov_length = 0.0;
	r->camera_x = 0.0;
	r->raydir_x = 0.0;
	r->raydir_y = 0.0;
	r->map_x = 0;
	r->map_y = 0;
	r->deltadist_x = 0.0;
	r->deltadist_y = 0.0;
	r->sidedist_x = 0.0;
	r->sidedist_y = 0.0;
	r->step_x = 0;
	r->step_y = 0;
	r->hit = 0;
	r->side = 0;
	r->perpwalldist = 0.0;
}

static void	init_draw_info(t_render *r)
{
	r->lineheight = 0;
	r->drawstart = 0;
	r->drawend = 0;
	r->wall_x = 0.0;
	r->tex_x = 0;
	r->tex = NULL;
	r->y = 0;
	r->d = 0;
	r->tex_y = 0;
	r->color = 0;
	r->x = 0;
}

static void	init_minimap_info(t_render *r)
{
	r->minimap_area_width = 0;
	r->minimap_area_height = 0;
	r->minimap_offset_x = 0;
	r->minimap_offset_y = 0;
	r->minimap_scale_x = 0.0;
	r->minimap_scale_y = 0.0;
	r->minimap_scale = 0.0;
}

static void	init_wall_info(t_render *r)
{
	r->wall_info.wall_type = 0;
	r->wall_info.side = 0;
	r->wall_info.raydir_x = 0.0;
	r->wall_info.raydir_y = 0.0;
}

void	init_render_str(t_render *render)
{
	if (!render)
		return ;
	init_ray_info(render);
	init_draw_info(render);
	init_minimap_info(render);
	init_wall_info(render);
}
