/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:13:56 by vvinogra          #+#    #+#             */
/*   Updated: 2018/03/11 20:22:25 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	move_forward(t_wolf *wolf)
{
	if (wolf->map[(int)(wolf->ray->player_posx +
			wolf->ray->player_dir_x * wolf->ray->move_speed)]
				[(int)wolf->ray->player_posy] == 0)
		wolf->ray->player_posx += wolf->ray->player_dir_x
									* wolf->ray->move_speed;
	if (wolf->map[(int)wolf->ray->player_posx]
			[(int)(wolf->ray->player_posy +
				wolf->ray->player_dir_y * wolf->ray->move_speed)] == 0)
		wolf->ray->player_posy += wolf->ray->player_dir_y
									* wolf->ray->move_speed;
}

void	move_back(t_wolf *wolf)
{
	if (wolf->map[(int)(wolf->ray->player_posx -
			wolf->ray->player_dir_x * wolf->ray->move_speed)]
				[(int)wolf->ray->player_posy] == 0)
		wolf->ray->player_posx -= wolf->ray->player_dir_x
									* wolf->ray->move_speed;
	if (wolf->map[(int)wolf->ray->player_posx]
			[(int)(wolf->ray->player_posy -
				wolf->ray->player_dir_y * wolf->ray->move_speed)] == 0)
		wolf->ray->player_posy -= wolf->ray->player_dir_y
									* wolf->ray->move_speed;
}

void	move_right(t_wolf *wolf)
{
	double	old_player_dir_x;
	double	old_plane_x;

	old_player_dir_x = wolf->ray->player_dir_x;
	wolf->ray->player_dir_x = wolf->ray->player_dir_x *
		cos(-wolf->ray->cam_speed) -
			wolf->ray->player_dir_y * sin(-wolf->ray->cam_speed);
	wolf->ray->player_dir_y = old_player_dir_x *
		sin(-wolf->ray->cam_speed) +
			wolf->ray->player_dir_y * cos(-wolf->ray->cam_speed);
	old_plane_x = wolf->ray->plane_x;
	wolf->ray->plane_x = wolf->ray->plane_x *
		cos(-wolf->ray->cam_speed) -
			wolf->ray->plane_y * sin(-wolf->ray->cam_speed);
	wolf->ray->plane_y = old_plane_x *
		sin(-wolf->ray->cam_speed) +
			wolf->ray->plane_y * cos(-wolf->ray->cam_speed);
}

void	move_left(t_wolf *wolf)
{
	double	old_player_dir_x;
	double	old_plane_x;

	old_player_dir_x = wolf->ray->player_dir_x;
	wolf->ray->player_dir_x = wolf->ray->player_dir_x *
		cos(wolf->ray->cam_speed) -
			wolf->ray->player_dir_y * sin(wolf->ray->cam_speed);
	wolf->ray->player_dir_y = old_player_dir_x *
		sin(wolf->ray->cam_speed) +
			wolf->ray->player_dir_y * cos(wolf->ray->cam_speed);
	old_plane_x = wolf->ray->plane_x;
	wolf->ray->plane_x = wolf->ray->plane_x *
		cos(wolf->ray->cam_speed) -
			wolf->ray->plane_y * sin(wolf->ray->cam_speed);
	wolf->ray->plane_y = old_plane_x *
		sin(wolf->ray->cam_speed) +
			wolf->ray->plane_y * cos(wolf->ray->cam_speed);
}

void	move(t_wolf *wolf)
{
	if (wolf->move->move_left == 1)
		move_left(wolf);
	if (wolf->move->move_right == 1)
		move_right(wolf);
	if (wolf->move->move_back == 1)
		move_back(wolf);
	if (wolf->move->move_forward == 1)
		move_forward(wolf);
}
