/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:50:43 by lloison           #+#    #+#             */
/*   Updated: 2023/10/10 14:24:33 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strdup(t_list **x_chain, const char *s1)
{
	size_t	size;
	size_t	i;
	char	*output;

	if (s1 == 0)
		return (0);
	size = ft_strlen(s1);
	i = 0;
	output = x_malloc(x_chain, (size + 1) * sizeof(char));
	if (output == 0)
		return (0);
	while (i < size)
	{
		output[i] = s1[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}
