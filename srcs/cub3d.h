/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:38:43 by edelarbr          #+#    #+#             */
/*   Updated: 2023/12/06 19:59:40 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*================================ BUGS/CRASH ================================*/

// ! crash

// - bug
// Sauf pour la map elle-même, les informations de chaque élément peuvent être
// séparées par un ou plusieurs espace(s).

// ? trucs à fiare si on a vraaaaaaaiment le temps
// verifier atoi en mettant des inputs étranges en RGB dans le .cub

/*=============================== PROTECTIONS ================================*/

#ifndef CUB3D_H
# define CUB3D_H

/*================================ LIBRAIRIES ================================*/

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"

/*================================= DEFINES ==================================*/

# define TRUE 1
# define SUCCESS 1
# define FALSE 0
# define ERROR -1
# define FILE_FORMAT "file.cub must be formatted like this:\n\
		\nNO [path_to_the_north_texture].png\
		\nSO [path_to_the_south_texture].png\
		\nWE [path_to_the_west_texture].png\
		\nEA [path_to_the_east_texture].png\
		\n\nF [R,G,B]\
		\nC [R,G,B]\
		\n\n[map]\n..."
# define OPAQUE 255
# define TRANSPARENT 0

/*================================= STRUCTS ==================================*/

typedef struct s_list
{
	void			*content;

	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_assets
{
	mlx_image_t		*north_img;
	mlx_image_t		*south_img;
	mlx_image_t		*west_img;
	mlx_image_t		*east_img;

	int				floor_trgb;
	int				ceiling_trgb;

	mlx_image_t		*minimap_wall_img;
	mlx_image_t		*minimap_floor_img;
	mlx_image_t		*minimap_player_img;
}					t_assets;

typedef struct s_map
{
	char			**map;
	int				height;
	int				width;

	int				minimap_size;
}					t_map;

typedef struct s_parsing
{
	char			**file;

	char			**temp_map;
	int				map_hole;

	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
	char			**floor_rgb;
	char			**ceiling_rgb;

}					t_parsing;

typedef struct s_game_data
{
	t_parsing		*parsing;
	t_map			*gps;
	t_assets		*assets;

	t_list			*x_chain;
	mlx_image_t		*img_chain;

	mlx_t			*mlx;
}					t_game_data;

/*================================ FUNCTIONS =================================*/

/* OTHERS */
void				*x_malloc(t_list **lst, size_t size);
void				x_free(t_list **x_chain);
t_game_data			game_data_init(void);
t_map				*map_init(t_game_data *data);
t_assets			*assets_init(t_game_data *data);
void				exit_error(t_game_data *data, char *message);
void				free_n_exit(t_game_data *data, int exit_code);

/* PARSING */
t_parsing			*parsing(t_game_data *data, int argc, char **argv);
void				check_file(t_game_data *data, char *file);
char				**extract_file_to_tab(t_game_data *data, char *file);
t_parsing			*parsing_init(t_game_data *data);
void				valid_way(t_game_data *data, char **map, int x, int y);
int					find_player_y(char **map);
int					find_player_x(char **map);
char				**map_w_null_background(t_list **x_chain, char **map);
void				format_error(t_game_data *data, t_parsing *parsing);
t_map				*extract_data(t_game_data *data, t_parsing *parsing);
void				verify_map_chars(t_game_data *data, char **map);
int					ft_atoi_mod(const char *str);

/* MLX */
mlx_image_t			*asset_to_image(t_game_data *data, char *path);
void				get_minimap_assets(t_game_data *data, t_assets *assets);
void				get_dot_ber_assets(t_game_data *data, t_assets *assets,
						t_parsing *parsing);
void				load_assets(t_game_data *data);

/* MINIMAP */
int					find_mimimap_img_size(int width, int height);
void				display_minimap(t_game_data *data, int img_size);

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
char				**ft_tabdup(t_list **x_chain, char **tab);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					create_trgb(unsigned char t, unsigned char r,
						unsigned char g, unsigned char b);
unsigned char		get_t(int trgb);
unsigned char		get_r(int trgb);
unsigned char		get_g(int trgb);
unsigned char		get_b(int trgb);
char				*ft_strchr(const char *s, int c);
int					ft_isdigit(int c);
int					ft_str_is_num(char *str);

/* TEMP */
void				print_file(char **file);
void				print_map(char **map);

#endif
