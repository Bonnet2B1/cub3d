/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:31:18 by edelarbr          #+#    #+#             */
/*   Updated: 2023/10/11 18:43:58 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_file(char **file)
{
	int	i;

	printf("=========================<FILE>=========================\n");
	if (!file)
	{
		printf("NULL\n");
		return ;
	}
	i = -1;
	while (file[++i])
		printf("%s\n", file[i]);
	printf("=====================<END OF FILE>======================\n");
}

void	print_map(char **map)
{
	int	i;

	printf("=========================<MAP>==========================\n");
	if (!map)
	{
		printf("NULL\n");
		return ;
	}
	i = -1;
	while (map[++i])
		printf("%s\n", map[i]);
	printf("======================<END OF MAP>======================\n");
}
