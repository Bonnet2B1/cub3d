/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:38:43 by edelarbr          #+#    #+#             */
/*   Updated: 2023/10/10 21:40:14 by edelarbr         ###   ########.fr       */
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
# include <fcntl.h>

/*================================= DEFINES ==================================*/

# define TRUE 1
# define SUCCESS 1
# define FALSE 0
# define ERROR -1
# define FILE_FORMAT "file.cub must be formatted like this:\n\
		\n1. NO [path_to_the_north_texture]\
		\n2. SO [path_to_the_south_texture]\
		\n3. WE [path_to_the_west_texture]\
		\n4. EA [path_to_the_east_texture]\
		\n5. \n6. F [R,G,B]\
		\n7. C [R,G,B]\
		\n8. \n9. [map]\n..."

/*================================= STRUCTS ==================================*/

typedef struct s_list
{
	void			*content;

	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_assets
{
}					t_assets;

typedef struct s_parsing
{
	char			**file;
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
	char			*floor_color;
	char			*ceiling_color;
	int				n;
	int				s;
	int				w;
	int				e;
	char			**map;
	int				hole;
}					t_parsing;

typedef struct s_game_data
{
	char			**map;
	t_list			*x_chain;
}					t_game_data;

/*================================ FUNCTIONS =================================*/

/* OTHERS */
void				*x_malloc(t_list **lst, size_t size);
void				x_free(t_list **lst);
t_game_data			game_data_init(void);
void				exit_error(t_game_data *data, char *message);
void				free_n_exit(t_game_data *data, int exit_code);

/* PARSING */
void				parsing(t_game_data *data, int argc, char **argv);
void				check_file(t_game_data *data, char *file);
char				**extract_file_to_tab(t_game_data *data, char *file);
t_parsing			*parsing_init(t_game_data *data);

/* LIB */
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_putstr_fd(char *str, int fd);
int					ft_strlen(const char *str);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
int					ft_isascii(int c);
char				*ft_strdup(t_list **x_chain, const char *s1);
char				*ft_strjoin(t_list **x_chain, char *s1, char *s2);
char				**ft_split(t_list **x_chain, char *s, char c);
int					ft_tablen(char **tab);
char				**ft_tabdup(t_game_data *data, char **tab);

/* TEMP */
void				print_file(char **file);
void				print_map(char **map);

#endif
