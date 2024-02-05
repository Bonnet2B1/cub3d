/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:38:43 by edelarbr          #+#    #+#             */
/*   Updated: 2024/02/04 20:15:08 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*================================ BUGS/CRASH ================================*/

// ! crash

// - bug

// ? trucs à fiare si on a vraaaaaaaiment le temps
// - faire une belle map
// - corriger l'angle inital du player qui bug 1 fois sur 2
// - faire une main qui tient une torche

// ! trucs à faire
// - faux segfault
// - verifier si DARKNESS_EFFECT est ok à 0
// - implementer Ra qui danse
// - verifier atoi en mettant des inputs étranges en RGB dans le .cub
// - norme
// - verifer si tout est ok avec le sujet
// - leaks
// - changer couleurs minimap
// - vérifier headers
// - makefile

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

/*============================= CUSTOMS SETTINGS =============================*/

/* WINDOW */
# define WINDOW_WIDTH		1500
# define WINDOW_HEIGHT		1000

/* MINIMAP */
# define MINIMAP_ASSET_SIZE	0 /* 0 for automatic scale of the minimap */
# define GRIDE_DOT_SIZE		1
# define PLAYER_SIZE		3

/* PLAYER */
# define STEP_LEN			0.05
# define SPRINT_MULTIPLIER	2
# define ROTATE_SPEED		0.05
# define MOUSE_SPEED		0.003

/* DISPLAY */
# define FOV				60 /* in degree */
# define ASSET_SIZE			64
# define ANIMATION_SPEED	20
# define DARKNESS_EFFECT	1

/*================================= DEFINES ==================================*/

/* ERROR */
# define FILE_FORMAT "file.cub must be formatted like this:\n\
		\nNO [path_to_the_north_texture].png\
		\nSO [path_to_the_south_texture].png\
		\nWE [path_to_the_west_texture].png\
		\nEA [path_to_the_east_texture].png\
		\n\nF [R,G,B]\
		\nC [R,G,B]\
		\n\n[map]\n..."

/*================================= STRUCTS ==================================*/

typedef struct s_list
{
	void			*content;

	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_ray
{
	double			*x;
	double			*y;
	double			angle;

	double			len;

	double			op_x;
	double			op_y;

	double			sqrt_hit;

	char			type;
	int				map_x;
	int				map_y;
	char			side;

	struct s_ray	*v;
	struct s_ray	*h;

	mlx_image_t		*ray_img; // ! temp
	int				instance_amount;
}				t_ray;

typedef struct s_assets
{
	mlx_image_t		*north_img;
	mlx_image_t		*south_img;
	mlx_image_t		*west_img;
	mlx_image_t		*east_img;

	u_int32_t		floor_trgb;
	u_int32_t		ceiling_trgb;

	mlx_image_t		*minimap_wall_img;
	mlx_image_t		*minimap_floor_img;
	mlx_image_t		*minimap_door_img;
	mlx_image_t		*minimap_goal_img;

	mlx_image_t		*anubis_chill_img;
	mlx_image_t		*anubis_not_happy_img;
	mlx_image_t		*basic_wall_img;
	mlx_image_t		*door_img;
	mlx_image_t		*goal_img;
	mlx_image_t		*mummy_left_img;
	mlx_image_t		*mummy_right_img;
	mlx_image_t		*peacock_img;
	mlx_image_t		*pillar_img;
	mlx_image_t		*sarcophagus_img;
	mlx_image_t		*wall_w_hole_img;

	u_int32_t		dark_shade[256];

	int				frame;

	mlx_image_t		*background_mask;
	mlx_image_t		*darkness_background_mask;
	mlx_image_t		*textures_mask;
	mlx_image_t		*darkness_textures_mask;
	mlx_image_t		*vignette_mask;
}					t_assets;

typedef struct s_map
{
	char			**map;
	int				height;
	int				width;

	int				minimap_img_size;
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

typedef struct s_player
{
	mlx_image_t		*minimap_img;

	double			x;
	double			y;

	double			angle;

	t_ray			**ray;
	t_ray			*front;
	t_ray			*left;
	t_ray			*right;
	t_ray			*back;

	double			step_len;
	double			rotate_speed;

}					t_player;

typedef struct s_game
{
	t_parsing		*parsing;
	t_assets		*assets;
	t_map			*gps;
	t_player		*player;

	t_list			*x_chain;

	int				mouse;
	char			*map_name;
	mlx_t			*mlx;
}					t_game;

/*================================ FUNCTIONS =================================*/

/* OTHERS */
	/* Error */
void				exit_error(t_game *data, char *message);
	/* Memory */
void				*x_malloc(t_list **lst, size_t size);
void				x_free(t_list **x_chain);
void				free_n_exit(t_game *data, int exit_code);
	/* Struc init */
t_game				game_data_init(void);
t_map				*map_init(t_game *data);
t_assets			*assets_init(t_game *data);
t_player			*player_init(t_game *data);
t_ray				*ray_init(t_game *data, t_player *player);
void				init_player_spec_sn(t_player *player);

/* PARSING */
t_parsing			*parsing(t_game *data, int argc, char **argv);
void				check_file(t_game *data, char *file);
char				**extract_file_to_tab(t_game *data, char *file);
t_parsing			*parsing_init(t_game *data);
void				valid_way(t_game *data, char **map, int x, int y);
int					find_player_y(char **map);
int					find_player_x(char **map);
char				**map_w_null_background(t_list **x_chain, char **map);
void				format_error(t_game *data, t_parsing *parsing);
t_map				*extract_data(t_game *data, t_parsing *parsing);
void				verify_map_chars(t_game *data, char **map);
int					ft_atoi_mod(const char *str);
void				fill_with_spaces(t_game *data, t_map *gps);

/* EVENTS */
	/* mlx events */
void				keyboard(void *param);
void				mouse(void *param);
void				animation(void *param);

	/* player movements */
void				move_forward(t_game *data);
void				move_backward(t_game *data);
void				move_left(t_game *data);
void				move_right(t_game *data);
	/* player actions */
void				open_door(t_game *data);
void				mod_wall(t_game *data);

/* ENGINE */
void				set_player_angle(t_player *player, char c);
double				get_principal_measure(double angle);
void				rotate_left(t_player *player, double speed);
void				rotate_right(t_player *player, double speed);
void				ray_casting(void *param);
void				deep_ray_cpy(t_ray *ray);
double				get_len(t_game *data, t_ray *ray);
double				get_len_to_vertical_collision(t_game *data, t_ray *ray);
double				get_len_to_horizontal_collision(t_game *data, t_ray *ray);
int					is_collision(t_map *gps, int y, int x);
void				game_display(t_game *data);
u_int32_t			get_color(int x, int y, mlx_image_t *img);
void				load_masks(t_game *data, t_assets *assets);
void				put_line(t_game *data, t_ray *ray, int ray_idx,
						mlx_image_t *img);
void				put_wall(t_game *data, t_ray *ray, int ray_idx);
void				put_spe(t_game *data, t_ray *ray, int ray_idx);
void				put_mod_one(t_game *data, t_ray *ray, int ray_idx);
void				put_mod_two(t_game *data, t_ray *ray, int ray_idx);

/* MLX */
mlx_image_t			*asset_to_image(t_game *data, char *path);
void				get_minimap_assets(t_game *data, t_assets *assets);
void				get_dot_ber_assets(t_game *data, t_assets *assets,
						t_parsing *parsing);
void				get_custom_assets(t_game *data, t_assets *assets);
void				load_assets(t_game *data);
void				loops(t_game *data);

/* MINIMAP */
int					find_mimimap_img_size(int width, int height);
void				create_minimap(t_game *data, int img_size);
void				create_imgs(t_game *data, int img_size);

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
u_int32_t			create_rgbt(unsigned char r, unsigned char g,
						unsigned char b, unsigned char t);
char				*ft_strchr(const char *s, int c);
int					ft_isdigit(int c);
int					ft_str_is_num(char *str);
double				ft_rad_to_deg(double rad);
double				ft_deg_to_rad(double deg);

/* TEMP */
void				draw_lazer(t_game *data, t_ray *ray);
void				display_gride(t_game *data, int img_size, int depth);
void				print_file(char **file);
void				print_map(char **map);

#endif
