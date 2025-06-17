/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:35:54 by gasroman          #+#    #+#             */
/*   Updated: 2025/05/23 08:45:33 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static size_t	w_size(char const *s, int start, char c1, char c2)
{
	size_t	size;

	size = 0;
	while (s[start] && (s[start] != c1 && s[start] != c2 && s[start] != '\n'))
	{
		size++;
		start++;
	}
	return (size);
}

static int	count_words(char const *s, char c1, char c2)
{
	int	i;
	int	words;
	int	flag;

	i = 0;
	words = 0;
	flag = 0;
	while (s[i])
	{
		if ((s[i] != c1 && s[i] != c2 && s[i] != '\n') && flag == 0)
		{
			words++;
			flag = 1;
		}
		else if (s[i] == c1 || s[i] == c2 || s[i] == '\n')
			flag = 0;
		i++;
	}
	return (words);
}

static char	**error_free(char **str, int j)
{
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
	free(str);
	return (NULL);
}

char	**ft_split_set(char const *s, char c1, char c2)
{
	int		i;
	int		j;
	char	**str;

	str = malloc((sizeof (char *)) * (count_words(s, c1, c2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count_words(s, c1, c2))
	{
		while (s[i] == c1 || s[i] == c2 || s[i] == '\n')
			i++;
		str[j] = ft_substr(s, i, w_size(s, i, c1, c2));
		if (!str[j])
			return (error_free(str, j));
		j++;
		i += w_size(s, i, c1, c2);
	}
	str[j] = 0;
	return (str);
}
