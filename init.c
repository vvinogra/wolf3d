/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:20:07 by vvinogra          #+#    #+#             */
/*   Updated: 2018/03/14 14:04:30 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_wolf	*init(char **map)
{
	t_wolf	*wolf;

	wolf = parsemap(map);
	wolf->mlx = mlx_init();
	wolf->win = mlx_new_window(wolf->mlx, WIN_WIDTH, WIN_HEIGHT, "wolf3d");
	wolf->mute_sound = 0;
	wolf->nb_shot_walls = 0;
	wolf->shoot = 0;
	wolf->fr = 17;
	wolf->ray = malloc(sizeof(t_cast));
	wolf->ray->player_dir_x = -1;
	wolf->ray->player_dir_y = 0;
	wolf->ray->plane_x = 0;
	wolf->ray->plane_y = 0.66;
	wolf->ray->move_speed = 0.05;
	wolf->ray->cam_speed = 0.05;
	wolf->move = malloc(sizeof(t_move));
	wolf->move->move_left = 0;
	wolf->move->move_right = 0;
	wolf->move->move_back = 0;
	wolf->move->move_forward = 0;
	return (wolf);
}

void	init_im_addr(t_wolf *wolf)
{
	wolf->blue_br->pic = mlx_get_data_addr(wolf->blue_br->image,
		&wolf->blue_br->bpp, &wolf->blue_br->stride, &wolf->blue_br->endian);
	wolf->br->pic = mlx_get_data_addr(wolf->br->image,
		&wolf->br->bpp, &wolf->br->stride, &wolf->br->endian);
	wolf->br_one->pic = mlx_get_data_addr(wolf->br_one->image,
		&wolf->br_one->bpp, &wolf->br_one->stride, &wolf->br_one->endian);
	wolf->br_two->pic = mlx_get_data_addr(wolf->br_two->image,
		&wolf->br_two->bpp, &wolf->br_two->stride, &wolf->br_two->endian);
	wolf->shotgun_one->pic = mlx_get_data_addr(wolf->shotgun_one->image,
		&wolf->shotgun_one->bpp, &wolf->shotgun_one->stride,
			&wolf->shotgun_one->endian);
	wolf->shotgun_two->pic = mlx_get_data_addr(wolf->shotgun_two->image,
		&wolf->shotgun_two->bpp, &wolf->shotgun_two->stride,
			&wolf->shotgun_two->endian);
	wolf->shotgun_three->pic = mlx_get_data_addr(wolf->shotgun_three->image,
		&wolf->shotgun_three->bpp, &wolf->shotgun_three->stride,
			&wolf->shotgun_three->endian);
	wolf->shotgun_four->pic = mlx_get_data_addr(wolf->shotgun_four->image,
		&wolf->shotgun_four->bpp, &wolf->shotgun_four->stride,
			&wolf->shotgun_four->endian);
	wolf->shotgun_five->pic = mlx_get_data_addr(wolf->shotgun_five->image,
		&wolf->shotgun_five->bpp, &wolf->shotgun_five->stride,
			&wolf->shotgun_five->endian);
	wolf->floor->pic = mlx_get_data_addr(wolf->floor->image,
		&wolf->floor->bpp, &wolf->floor->stride, &wolf->floor->endian);
}

void	init_im_help(t_wolf *wolf)
{
	wolf->shotgun_one = malloc(sizeof(t_image));
	wolf->shotgun_one->image = mlx_xpm_file_to_image(wolf->mlx,
		"pic/shotgun1.xpm", &wolf->shotgun_one->x, &wolf->shotgun_one->y);
	wolf->shotgun_two = malloc(sizeof(t_image));
	wolf->shotgun_two->image = mlx_xpm_file_to_image(wolf->mlx,
		"pic/shotgun2.xpm", &wolf->shotgun_two->x, &wolf->shotgun_two->y);
	wolf->shotgun_three = malloc(sizeof(t_image));
	wolf->shotgun_three->image = mlx_xpm_file_to_image(wolf->mlx,
		"pic/shotgun3.xpm", &wolf->shotgun_three->x, &wolf->shotgun_three->y);
	wolf->shotgun_four = malloc(sizeof(t_image));
	wolf->shotgun_four->image = mlx_xpm_file_to_image(wolf->mlx,
		"pic/shotgun4.xpm", &wolf->shotgun_four->x, &wolf->shotgun_four->y);
	wolf->shotgun_five = malloc(sizeof(t_image));
	wolf->shotgun_five->image = mlx_xpm_file_to_image(wolf->mlx,
		"pic/shotgun5.xpm", &wolf->shotgun_five->x, &wolf->shotgun_five->y);
}

void	init_im(t_wolf *wolf)
{
	wolf->ret_im = create_new_im(wolf->mlx);
	wolf->blue_br = malloc(sizeof(t_image));
	wolf->blue_br->image = mlx_xpm_file_to_image(wolf->mlx,
		"pic/bluebrickimage.xpm", &wolf->blue_br->x, &wolf->blue_br->y);
	wolf->br = malloc(sizeof(t_image));
	wolf->br->image = mlx_xpm_file_to_image(wolf->mlx,
		"pic/brickimage.xpm", &wolf->br->x, &wolf->br->y);
	wolf->br_one = malloc(sizeof(t_image));
	wolf->br_one->image = mlx_xpm_file_to_image(wolf->mlx,
		"pic/brickimage2.xpm", &wolf->br_one->x, &wolf->br_one->y);
	wolf->br_two = malloc(sizeof(t_image));
	wolf->br_two->image = mlx_xpm_file_to_image(wolf->mlx,
		"pic/brickimage3.xpm", &wolf->br_two->x, &wolf->br_two->y);
	wolf->floor = malloc(sizeof(t_image));
	wolf->floor->image = mlx_xpm_file_to_image(wolf->mlx,
		"pic/floor.xpm", &wolf->floor->x, &wolf->floor->y);
	wolf->ceiling = malloc(sizeof(t_image));
	wolf->ceiling->image = mlx_xpm_file_to_image(wolf->mlx,
		"pic/ceiling.xpm", &wolf->ceiling->x, &wolf->ceiling->y);
	init_im_help(wolf);
	check_images(wolf);
	init_im_addr(wolf);
	wolf->ceiling->pic = mlx_get_data_addr(wolf->ceiling->image,
		&wolf->ceiling->bpp, &wolf->ceiling->stride, &wolf->ceiling->endian);
}
