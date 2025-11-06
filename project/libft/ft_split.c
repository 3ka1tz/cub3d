/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:03:40 by iullibar          #+#    #+#             */
/*   Updated: 2025/10/17 09:34:10 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_split(char **array, int j)
{
	int	i;

	i = 0;
	while (i < j)
		free (array[i ++]);
	free (array);
}

static int	words_count(char const *s, char c)
{
	int	i;
	int	con;

	i = 0;
	con = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i ++;
		if (s[i] != '\0')
			con ++;
		while (s[i] != '\0' && s[i] != c)
			i ++;
	}
	return (con);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		con;
	int		i;

	i = 0;
	con = 0;
	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (words_count(s, c) + 1));
	if (!split)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i ++;
		if (s[i] != '\0')
		{
			split[con++] = ft_strcdup(&s[i], c);
			if (split[con - 1] == NULL)
				return (free_split(split, con - 1), NULL);
		}
		while (s[i] != '\0' && s[i] != c)
			i ++;
	}
	return (split[con] = NULL, split);
}
