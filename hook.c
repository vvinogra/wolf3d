/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:50:14 by vvinogra          #+#    #+#             */
/*   Updated: 2018/03/14 13:37:19 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		loop_hook(t_wolf *wolf)
{
	image_clear(wolf->ret_im);
	move(wolf);
	solution(wolf);
	mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->ret_im->image, 0, 0);
	anim_shotgun(wolf);
	return (0);
}

int		exit_x(void *par)
{
	par = NULL;
	exit(0);
	return (0);
}

int		exit_esc(int keycode, t_wolf *wolf)
{
	if (keycode == 53)
	{
		mlx_destroy_window(wolf->mlx, wolf->win);
		exit(0);
	}
	return (0);
}

int		hook(int keycode, t_wolf *wolf)
{
	exit_esc(keycode, wolf);
	if (keycode == 123)
		wolf->move->move_left = 1;
	if (keycode == 124)
		wolf->move->move_right = 1;
	if (keycode == 125)
		wolf->move->move_back = 1;
	if (keycode == 126)
		wolf->move->move_forward = 1;
	if (keycode == 257)
		wolf->ray->move_speed = 0.1;
	return (0);
}

int		exposehook(int keycode, t_wolf *wolf)
{
	exit_esc(keycode, wolf);
	if (keycode == 123)
		wolf->move->move_left = 0;
	if (keycode == 124)
		wolf->move->move_right = 0;
	if (keycode == 125)
		wolf->move->move_back = 0;
	if (keycode == 126)
		wolf->move->move_forward = 0;
	if (keycode == 257)
		wolf->ray->move_speed = 0.05;
	if (keycode == 49)
		wolf->shoot = 1;
	mute_sound(keycode, wolf);
	return (0);
}
