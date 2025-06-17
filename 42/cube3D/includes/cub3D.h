/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 01:52:53 by albealva          #+#    #+#             */
/*   Updated: 2025/06/17 15:11:30 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "aux.h"
# include "color.h"
# include "parsing.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef BONUS
#  define BONUS 1
# endif

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define DARK_GREEN 0x004400
# define GRAY 0xAAAAAA
# define RED 0xFF0000
# define YELLOW 0xFFFF00
# define SKY_BLUE 0x87CEEB
# define GRASS_GREEN 0x32CD32
# define WALL_BROWN 0x8B4513
# define WALL_RED 0xFF0000
# define WALL_YELLOW 0xFFFF00
# define MINIMAP_PURPLE 0x800080

# define MAP_WIDTH 12
# define MAP_HEIGHT 17
# define MINI_MAP_WIDTH 60
# define MINI_MAP_HEIGHT 60
# define SCREEN_WIDTH 1920  // 800
# define SCREEN_HEIGHT 1080 // 800
# define WIN_WIDTH 1920     // 800
# define WIN_HEIGHT 1080    // 600
# define MOVE_SPEED 0.200   // 0.0125
# define ROTATE_SPEED 0.015 // 0.015

# define K_W 119
# define K_S 115
# define K_A 97
# define K_D 100
# define K_LEFT 65361
# define K_RIGHT 65363
# define K_ESC 65307
# define K_SPACE 32

# define FOV 60 // 60

# define PLAYER_RADIUS 0.2

// --- Minimap Config ---
// --- Minimap Config ---
# define MINIMAP_WIDTH 120  // Fixed width of the minimap (MAP_WIDTH * 8)
# define MINIMAP_HEIGHT 120 // Fixed height of the minimap (MAP_HEIGHT * 8)

// --- Minimap Area Config ---
# define MINIMAP_AREA_OFFSET_X 10 // Offset from the left edge of the window 10
# define MINIMAP_AREA_OFFSET_Y 10 // Offset from the top edge of the window 10
# define MINIMAP_AREA_WIDTH 140   // Fixed width of the area 140
# define MINIMAP_AREA_HEIGHT 170  // Fixed height of the area 170

# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# define MAX_LINE_LENGTH 1024

# define DOOR_INTERACTION_DISTANCE 3.0   // 1.5
# define DOOR_INTERACTION_DISTANCE_MAP 1 // Distancia de interacción en el mapa

# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_BLUE "\x1b[34m"
# define ANSI_COLOR_YELLOW "\x1b[33m"
# define ANSI_COLOR_RESET "\x1b[0m"

# define DEBUG 1

// --- Data struct ---

typedef struct s_keys
{
	int				w;
	int				s;
	int				a;
	int				d;
	int				left;
	int				right;
	int				esc;
	int				space;
	int				space_pressed;
}					t_keys;

typedef struct s_william
{
	double			x;
	double			y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			fov;
	double			playerangle;
	int				turndirection;
	int				release_mouse;
	int				mouse_x;
	int				last_mouse_x;
}					t_william;

typedef struct s_texture
{
	void			*img_ptr;
	int				width;
	int				height;
	char			*path;
	int				*data;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_texture;

typedef struct s_img
{
	void			*img;
	void			*img_ptr;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
	int				size_line;

}					t_img;

typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_win;
	t_img			*img;
}					t_mlx;

typedef struct s_mouse_bonus
{
	t_william		*william;
	t_mlx			*mlx;
	t_texture		*wall;
	t_texture		*shoot_target;
	t_texture		**weapon;
	t_texture		**digit;
	t_texture		*amo;
	int				mouse_pos;

}					t_mouse_bonus;

typedef struct s_minimap
{
	int				map_x;
	int				map_y;
	int				screen_x;
	int				screen_y;
	int				player_map_x;
	int				player_map_y;
	int				minimap_cells_x;
	int				minimap_cells_y;
	int				offset_x;
	int				offset_y;
	int				cell_size;
	int				start_x;
	int				start_y;
	int				william_center_x;
	int				william_center_y;
	int				radius;
	int				pixel_x;
	int				pixel_y;
	int				color;
	char			cell;
	int				i;
	int				j;
	double			fov_half;
}					t_minimap;

typedef struct s_wall_info
{
	char			wall_type;
	int				side;
	double			raydir_x;
	double			raydir_y;
}					t_wall_info;

typedef struct s_render
{
	int				total_pixels;
	double			fov_length;
	t_wall_info		wall_info;
	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	int				map_x;
	int				map_y;
	double			deltadist_x;
	double			deltadist_y;
	double			sidedist_x;
	double			sidedist_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	double			perpwalldist;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			wall_x;
	int				tex_x;
	t_texture		*tex;
	int				y;
	int				d;
	int				tex_y;
	int				color;
	int				x;
	int				minimap_area_width;
	int				minimap_area_height;
	int				minimap_offset_x;
	int				minimap_offset_y;
	double			minimap_scale_x;
	double			minimap_scale_y;
	double			minimap_scale;
}					t_render;

typedef struct s_rhand
{
	int				x;
	int				y;
	t_texture		current_hand;
	int				*data;
	int				width;
	int				height;
	int				line_len;
	unsigned char	alpha;
	int				color;
	int				draw_x;
	int				draw_y;
}					t_rhand;

typedef enum e_game_state
{
	STATE_INTRO,
	STATE_TRANSITION,
	STATE_PLAYING,
	STATE_SPLASH,
	STATE_GAMEOVER,
}					t_game_state;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*img_data;
	char			*addr;
	t_img			*img_ground;
	t_william		william;
	int				floor_color;
	int				ceiling_color;
	char			**map;
	void			*minimap_img_ptr;
	int				*minimap_img_data;
	int				minimap_bpp;
	int				minimap_line_length;
	int				minimap_endian;
	int				bits_per_pixel;
	int				line_length;
	int				endian;

	t_texture		*textures;
	void			*hands_img_ptr[2];
	int				*hands_data[2];
	int				hands_width;
	int				hands_height;
	int				hands_bits_per_pixel;
	int				hands_line_length;
	int				hands_endian;
	int				current_hand_frame;
	int				hand_animation_timer;
	int				hands_x;
	int				hands_y;
	t_keys			keys;
	double			last_mouse_x;
	double			mouse_sensitivity;
	int				mouse_in_border;
	int				last_turn_direction;
	t_mouse_bonus	*mouse_data;
	void			*doors_img_ptr[2];
	int				*doors_data[2];
	int				doors_width;
	int				doors_height;
	int				doors_bits_per_pixel;
	int				doors_line_length;
	int				doors_endian;
	int				current_door_frame;
	int				door_animation_timer;
	int				doors_x;
	int				doors_y;
	int				door_open;
	t_texture		*hands;
	t_texture		*hud;
	t_texture		*door_texture;
	t_texture		mask;
	int				hud_x;
	int				hud_y;
	bool			hud_message;
	bool			hud_message2;
	struct timeval	hud_timer;
	t_minimap		minimap;
	t_texture		gameover;
	char			**worldmap;
	t_data			*data;
	char			**map2;
	t_game_state	game_state;
	struct timeval	intro_timer;
	char			*original_map_path;
	t_texture		intro_screen;
	t_texture		game_over_screen;
}					t_game;

typedef struct s_cone
{
	double			angle;
	double			dir_x;
	double			dir_y;
	int				player_x;
	int				player_y;
	int				i;
	int				x;
	int				y;
}					t_cone;

typedef struct s_coneaux
{
	double			step;
	double			length;
	double			i;
	int				current_map_x;
	int				current_map_y;
}					t_coneaux;

typedef struct s_bounds
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
}					t_bounds;
typedef struct s_aux
{
	char			*line;
	char			**file_lines;
	int				count;
}					t_aux;

typedef struct s_player_map_state
{
	int				old_x;
	int				old_y;
	char			old_cell;
	int				new_x;
	int				new_y;
	char			player_char;
}					t_player_map_state;

typedef struct s_extract
{
	int				elements_found_count;
	int				element_flags[6];
	char			*value_str;
	char			*current_line_content;
	int				current_flag_index;
	const char		*current_element_name;
	int				current_identifier_len;
	int				*p_map_start_line_idx_ptr;
	char			*original_file_line_for_error;
}					t_extract;

typedef struct s_map_vars
{
	int				map_start_idx;
	int				map_end_idx;
	int				map_height;
	int				map_width;
	int				i;
	int				j;
	int				j_source;
	int				j_dest;
	int				current_expanded_width;
	const char		*source_line;
	int				source_len;
}					t_map_vars;

typedef struct s_flood_fill_vars
{
	char			**map_copy;
	int				player_x;
	int				player_y;
	int				is_leaking;
	int				y;
	int				x;
	int				i;
}					t_flood_fill_vars;

int			load_textures(t_game *game);
int			render(t_game *game);
int			update(t_game *game);
void		render_mask(t_game *game);
int			handle_input(int keycode, t_game *game);
int			game_loop(t_game *game);
void		draw_minimap(t_game *game);
void		my_mlx_pixel_put(t_game *game, int x, int y, int color);
void		drawbackground(t_game *game);
int			load_hands_images(t_game *game);
int			load_mask_images(t_game *game);
void		remove_black_background(t_game *game);

void		draw_background(t_game *game);
void		my_mlx_pixel_put(t_game *game, int x, int y, int color);

int			init_game(t_game *game);
int			init_mlx(t_game *game);
int			init_images(t_game *game);
int			init_minimap(t_game *game);
int			init_map(t_game *game);
int			init_player(t_game *game);
int			init_textures_and_hands(t_game *game);

char		*ft_strchr(const char *s, int c);
void		print_player_position(t_game *game);

int			load_hands_images(t_game *game);
int			load_textures(t_game *game);
int			load_door_images(t_game *game);
int			load_gameover(t_game *game);

void		draw_minimap(t_game *game);

int			handle_mouse(int x, int y, void *param);
int			mouse_press(int key, int x, int y, t_mouse_bonus *data);
int			mouse_release(int key, int x, int y, t_mouse_bonus *data);
void		center_mouse(t_game *game);

int			load_textures_hud(t_game *game);

void		draw_cone_line_centered(t_game *game, double angle_offset,
				int center_x, int center_y);
void		draw_cone_line(t_game *game, double angle_offset, int center_x,
				int center_y);
void		ini_minimap(t_game *game);
void		calculate_minimap_coords(t_minimap *mini);
void		set_minimap_cell_color(t_game *game, t_minimap *mini);

bool		is_player_moving(t_game *game);
bool		is_valid_move(t_game *game, double new_x, double new_y);

t_texture	*get_texture_for_wall(t_game *game, t_wall_info wall_info);
void		init_render_vars(t_game *game, t_render *render);
void		calculate_ray_vars(t_game *game, t_render *render);
void		perform_ray_casting(t_game *game, t_render *render);
void		calculate_wall_properties(t_game *game, t_render *render);

void		draw_texture_on_wall(t_game *game, t_render *render);
void		init_minimap_vars(t_render *render, t_game *game);
void		render_walls(t_game *game, t_render *render);
void		clear_minimap_area(t_game *game, t_render *render);
void		draw_scaled_minimap(t_game *game, t_render *render);

void		render_minimap(t_game *game, t_render *render);
void		init_ray_direction(t_game *game, t_render *render);

int			render(t_game *game);
void		render_hands(t_game *game);
int			update_and_render(t_game *game);

int			clean_exit(void *param, char *msg);

void		render_hud(t_game *game);
void		render_m1(t_game *game);
void		render_m2(t_game *game);
void		render_m3(t_game *game);
void		render_m4(t_game *game);

int			key_press(int keycode, t_game *game);
int			key_release(int keycode, t_game *game);

void		update_player(t_game *game);
void		update_hands_animation(t_game *game);

void		convert_od_to_1_while(char map[MAP_HEIGHT][MAP_WIDTH + 1]);

void		initialize_all_structures_while(t_game *game);

void		init_render_str(t_render *render);

void		init_game3(t_game *game);
void		initialize_game_struct(t_game *game);

void		init_main_pointers(t_game *game);
void		init_minimap_data(t_game *game);
void		init_img_render_data(t_game *game);
void		init_hands_data(t_game *game);

void		init_render_str(t_render *render);

int			key_release(int keycode, t_game *game);

void		move_player(t_game *game);

void		update_hands_animation(t_game *game);
void		update_player_state(t_player_map_state *state, t_game *game);

void		allocate_worldmap(t_game *game);
void		traspase_worldmap2_to_worldmap(t_game *game,
				char worldmap2[MAP_HEIGHT][MAP_WIDTH + 1]);
void		assign_hardcoded_worldmap(t_game *game);
int			init_worldmap(t_game *game);

void		toggle_magic_wall(t_game *game, int x, int y);

int			parser_data(int fd, t_game *game);
int			data_sorter(char **split, int *stored, t_game *game);
char		**process_line(char *line);
char		**ft_split_set(char const *s, char c1, char c2);
void		free_split(char ***arr);
void		free_data(t_game *game);
int			split_size(char **split);
int			store_texture(char **split, t_game *game);
int			texture_format(char *filename);
int			data_format(char *filename);
int			value_checks(char **color);
int			store_color(char **split, t_game *game);
int			is_texture(char **split);
int			is_color(char **split);
char		**ft_double_realloc(char **ptr, size_t new_size);
int			count_map(t_game *game, char *line);
int			parser_map(t_game *game);
int			line_checker(t_game *game);
int			is_surrounded(t_game *game, int i, int j);
int			player_count(char c);

void		print_worldmap_debug(t_game *game);

int			validate_map_is_closed(t_game *game);

void		flood_fill_recursive(char **map_copy, t_point pos, t_data *data,
				int *is_leaking);
void		cleanup_core_resources(t_game *game);

void		free_char_array(char **array);

int			init_keys(t_game *game);

int			my_isspace(char c);
void		free_char_array(char **arr);

char		*get_trimmed_value_from_line(const char *line_after_space);

int			init_parser_data_structures(t_game *game);
int			initialize_core_systems(t_game *game);

int			check_program_arguments(int argc, char **argv);

int			open_map_file(const char *filename);
char		**read_file_content(int fd, int *num_lines_read_out);

int			parse_and_validate_rgb_string(const char *rgb_string,
				int *color_out);

int			extract_map_config_elements(t_game *game, char **file_content,
				int num_lines, int *p_map_start_line_idx);

int			is_config_element_identifier(const char *line);
int			check_for_premature_map_line(t_extract *aux,
				const char *line_content);
int			validate_all_elements_found(t_extract *aux);
int			parse_texture_element(t_game *game, t_extract *aux,
				char **target_texture_ptr);
int			parse_color_element(t_game *game, t_extract *aux,
				int *target_color_ptr);

void		init_extract_and_loop_vars(t_extract *aux,
				int *p_map_start_line_idx_ptr, int *loop_idx_ptr);
int			process_file_line(t_game *game, t_extract *aux,
				char *current_file_line, int *p_map_start_line_idx_ptr);

int			process_known_element(t_game *game, t_extract *aux);
void		set_aux_element_info(t_extract *aux, int flag_idx, const char *name,
				int id_len);
int			process_texture_elements(t_game *game, t_extract *aux,
				char *line_content);
int			process_color_elements(t_game *game, t_extract *aux,
				char *line_content);
int			process_current_line(t_game *game, t_extract *aux,
				char *line_content, const char *original_line_for_error_msg);

void		cleanup_core_resources(t_game *game);

int			my_is_broad_whitespace(char c);
int			is_valid_map_char(char c);
void		aux(t_map_vars *vars);

int			create_and_normalize_map_tabs(t_game *game, char **file_content,
				int search_start_idx, int total_file_lines);

int			is_line_effectively_empty(const char *line);
int			calculate_expanded_width(const char *line);
void		init_map_parsing_vars(t_map_vars *vars, int search_start_idx);
int			update_map_block_indices(t_map_vars *vars,
				const char *current_file_line);
void		calculate_map_dimensions(t_map_vars *vars, char **file_content);

int			validate_map_is_closed(t_game *game);
int			flood_fill(t_game *game, int player_x, int player_y);

int			parse_and_validate_map(t_game *game, const char *path);
void		cleanup_map_assets(t_game *game);

int			validate_map_borders(t_game *game);
int			validate_player_data(t_game *game);
int			validate_texture_files(t_game *game);
int			validate_and_transform_borders(t_game *game);

void		update_intro_sequence(t_game *game);
void		perform_game_transition(t_game *game);
void		draw_fullscreen_color(t_game *game, int color);
void		destroy_loaded_images(t_game *game);
void		cleanup_intro_assets(t_game *game);
void		update_splash_sequence(t_game *game);

int			initialize_graphics(t_game *game);

void		handle_mandatory_logic(t_game *game);
void		handle_bonus_logic(t_game *game);
void		handle_playing_bonus(t_game *game);
void		handle_state_transition(t_game *game);
void		handle_state_intro(t_game *game);

void		print_intro(int is_bonus);
bool		parse_cub_file(const char *filename, t_game *game);

int			check_program_arguments(int argc, char **argv);
int			init_parser_data_structures(t_game *game);
int			initialize_core_systems(t_game *game);
int			open_map_file(const char *filename);
char		**read_file_content(int fd, int *num_lines_read_out);
char		*get_trimmed_value_from_line(
				const char *line_after_identifier_and_space_);
int			extract_map_config_elements(t_game *game, char **file_content,
				int num_lines, int *p_map_start_line_idx);
void		cleanup_core_resources(t_game *game);

int			start_game_bonus(t_game *game);
int			start_game_mandatory(t_game *game);
int			game_loop(t_game *game);
int			close_hook(void *param);

void	destroy_images(t_game *game);
#endif