/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 01:25:43 by albealva          #+#    #+#             */
/*   Updated: 2025/06/15 01:49:37 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	initialize_graphics(t_game *game)
{
	if (init_player(game) != 0)
		return (1);
	if (init_textures_and_hands(game) != 0)
		return (1);
	if (init_keys(game) != 0)
		return (1);
	printf(ANSI_COLOR_GREEN "Success:" ANSI_COLOR_RESET
		" All game assets and systems initialized.\n");
	return (0);
}
