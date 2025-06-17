/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:35:30 by albealva          #+#    #+#             */
/*   Updated: 2025/06/15 12:34:55 by contubernio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

typedef struct s_hud
{
	int				x;
	int				y;
	unsigned int	color;
	unsigned int	transparent_color_key;
	int				offset_x;
	int				offset_y;
	int				draw_x;
	int				draw_y;
}					t_hud;

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;
