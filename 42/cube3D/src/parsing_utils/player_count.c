/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 12:21:58 by gasroman          #+#    #+#             */
/*   Updated: 2025/05/23 11:06:04 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	player_count(char c)
{
	static int	check = 0;

	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		check++;
	if (check > 1)
		return (fals);
	return (tru);
}
