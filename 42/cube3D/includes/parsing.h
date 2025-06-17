/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:42:41 by gasroman          #+#    #+#             */
/*   Updated: 2025/06/15 12:34:48 by contubernio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libft/libft.h"
# include "../src/getnline/get_next_line.h"
# include "color.h"
# include "cub3D.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

enum		e_bolean
{
	fals,
	tru,
};

typedef struct s_data
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor;
	int		ceiling;
	char	**map;
	int		map_width;
	int		map_height;
	int		is_leaking;

}			t_data;

#endif
