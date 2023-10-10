/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:38:43 by edelarbr          #+#    #+#             */
/*   Updated: 2023/10/10 02:52:09 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*================================ BUGS/CRASH ================================*/

// ! crash

// - bug

/*=============================== PROTECTIONS ================================*/

#ifndef CUB3D_H
# define CUB3D_H

/*================================ LIBRAIRIES ================================*/

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

/*================================= DEFINES ==================================*/

# define TRUE 1
# define SUCCESS 1
# define FALSE 0
# define ERROR -1

/*================================= STRUCTS ==================================*/

typedef struct s_list
{
	void			*content;

	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_game_data
{
	char			*map;
	t_list			*malloc_chain;
}					t_game_data;

/*================================ FUNCTIONS =================================*/

/* OTHERS */
void				*x_mallox(t_list **lst, size_t size);
void				x_free(t_list **lst);
t_game_data			game_data_init(void);
void				exit_error(t_game_data *data, char *message);

/* PARSING */
void				parsing(t_game_data *data, int argc, char **argv);

/* LIB */
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_putstr_fd(char *str, int fd);
int					ft_strlen(const char *str);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
int					ft_isascii(int c);

/* TEMP */
void				print_map(char **map);

#endif
