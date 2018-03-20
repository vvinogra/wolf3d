/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:34:45 by vvinogra          #+#    #+#             */
/*   Updated: 2018/03/20 12:51:50 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "libft.h"
# include "SDL_mixer.h"
# include "SDL.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <time.h>
# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

typedef struct	s_wolf
{
	void			*mlx;
	void			*win;
	int				**map;
	struct s_cast	*ray;
	struct s_move	*move;
	struct s_image	*ret_im;
	struct s_image	*blue_br;
	struct s_image	*br;
	struct s_image	*br_one;
	struct s_image	*br_two;
	struct s_image	*floor;
	struct s_image	*ceiling;
	int				map_len;
	int				map_height;
	int				mute_sound;
	Mix_Music		*music;

	struct s_image	*shotgun_one;
	struct s_image	*shotgun_two;
	struct s_image	*shotgun_three;
	struct s_image	*shotgun_four;
	struct s_image	*shotgun_five;

	int				shoot;
	Mix_Chunk		*shoot_sound;
	int				fr;
	int				nb_shot_walls;
}				t_wolf;

typedef struct	s_move
{
	int	move_forward;
	int	move_back;
	int	move_left;
	int	move_right;
}				t_move;

typedef struct	s_cast
{
	double			player_posx;
	double			player_posy;

	double			player_dir_x;
	double			player_dir_y;

	double			plane_x;
	double			plane_y;

	double			camera;

	int				map_x;
	int				map_y;

	double			dir_x;
	double			dir_y;

	double			delx;
	double			dely;

	int				hit;
	int				side;

	double			dist;

	int				step_x;
	int				step_y;

	double			side_dist_x;
	double			side_dist_y;

	double			move_speed;
	double			cam_speed;

	int				text_x;
	int				text_y;

	double			floor_x;
	double			floor_y;

	int				draw_start;
	int				draw_end;

	int				floor_text_x;
	int				floor_text_y;
}				t_cast;

typedef struct	s_image
{
	void		*image;
	char		*pic;
	int			bpp;
	int			stride;
	int			endian;
	int			x;
	int			y;
}				t_image;

char			**getmap(int fd);
t_wolf			*parsemap(char **map);

void			solution(t_wolf *wolf);

void			pixel_image_put(t_wolf *wolf, int x, int y);
t_image			*create_new_im(void *mlx);
void			image_clear(t_image *im);
void			check_images(t_wolf *wolf);

int				exit_x(void *par);
void			move(t_wolf *wolf);

int				hook(int keycode, t_wolf *wolf);

int				loop_hook(t_wolf *wolf);

int				exposehook(int keycode, t_wolf *wolf);

t_wolf			*init(char **map);
void			init_im(t_wolf *wolf);

int				count_s(char **str);
void			free_double_arr(char **arr);

void			get_player_info(char **map, t_wolf *wolf);

void			play_music(t_wolf *wolf);
int				mute_sound(int keycode, t_wolf *wolf);

void			draw_floor(t_wolf *wolf, int x);
void			floor_direction(t_wolf *wolf, double wall_x);

void			check_map_line(char **line);
void			map_verify_help(int i, char **map, char **tmp);
void			calc_dist_help(t_wolf *wolf, int x);

void			anim_shotgun(t_wolf *wolf);

void			aim_draw(t_wolf *wolf);

#endif
