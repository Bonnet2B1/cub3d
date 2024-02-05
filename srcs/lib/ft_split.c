/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:32:22 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/27 18:32:22 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static size_t	nextlen(const char *s, size_t i, char c)
{
	size_t	len;

	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static size_t	wordcount(const char *s, char c)
{
	size_t	count;
	size_t	i;

	i = 1;
	count = 0;
	while (s[i - 1])
	{
		if (i != 0 && s[i - 1] != c && (s[i] == c || !s[i]))
			count++;
		i++;
	}
	return (count);
}

static char	*nextword(const char *s, size_t *i, char c, size_t len)
{
	char	*cpy;
	size_t	y;

	y = 0;
	while (s[*i] == c)
		(*i)++;
	cpy = malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	while (len)
	{
		cpy[y++] = s[(*i)++];
		len--;
	}
	cpy[y] = '\0';
	return (cpy);
}

char	**ft_split(t_list **x_chain, char *s, char c)
{
	size_t	i;
	size_t	y;
	char	**tab;
	char	*temp;

	i = 0;
	y = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (wordcount(s, c) + 1));
	if (!tab)
		return (NULL);
	while (y < wordcount(s, c))
	{
		temp = nextword(s, &i, c, nextlen(s, i, c));
		tab[y] = ft_strdup(x_chain, temp);
		if (!tab[y])
			return (free(temp), NULL);
		free(temp);
		y++;
	}
	tab[wordcount(s, c)] = NULL;
	return (tab);
}
