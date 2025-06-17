/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:34:54 by albealva          #+#    #+#             */
/*   Updated: 2025/06/14 22:35:15 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_program_arguments(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Argument Error\n");
		printf("Usage:\
%s " ANSI_COLOR_RED "<path_to_map.cub>" ANSI_COLOR_RESET "\n",
			argv[0]);
		return (1);
	}
	if (!data_format(argv[1]))
	{
		printf("Argument Format Error\n");
		return (1);
	}
	printf(ANSI_COLOR_GREEN "Success:" ANSI_COLOR_RESET " Program \
arguments validated.\n");
	printf(ANSI_COLOR_BLUE "Map file provided:" ANSI_COLOR_RESET " %s\n",
		argv[1]);
	printf("----------------------------------------------------\n");
	return (0);
}
