/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shot_gun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:27:56 by vvinogra          #+#    #+#             */
/*   Updated: 2018/03/20 18:16:30 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	anim_shotgun_help(t_wolf *wolf)
{
	if (wolf->fr >= 15)
		mlx_put_image_to_window(wolf->mlx, wolf->win,
			wolf->shotgun_two->image, (WIN_WIDTH - 400) / 2, WIN_HEIGHT - 400);
	else if (wolf->fr >= 12 && wolf->fr <= 14)
		mlx_put_image_to_window(wolf->mlx, wolf->win,
		wolf->shotgun_three->image, (WIN_WIDTH - 400) / 2, WIN_HEIGHT - 400);
	else if (wolf->fr >= 10 && wolf->fr <= 11)
		mlx_put_image_to_window(wolf->mlx, wolf->win,
			wolf->shotgun_four->image, (WIN_WIDTH - 400) / 2, WIN_HEIGHT - 400);
	else if (wolf->fr >= 7 && wolf->fr <= 9)
		mlx_put_image_to_window(wolf->mlx, wolf->win,
			wolf->shotgun_five->image, (WIN_WIDTH - 400) / 2, WIN_HEIGHT - 400);
	else if (wolf->fr >= 5 && wolf->fr <= 7)
		mlx_put_image_to_window(wolf->mlx, wolf->win,
			wolf->shotgun_four->image, (WIN_WIDTH - 400) / 2, WIN_HEIGHT - 400);
	else if (wolf->fr >= 1 && wolf->fr <= 4)
		mlx_put_image_to_window(wolf->mlx, wolf->win,
		wolf->shotgun_three->image, (WIN_WIDTH - 400) / 2, WIN_HEIGHT - 400);
	wolf->fr--;
	if (wolf->fr == 1)
	{
		wolf->fr = 17;
		wolf->shoot = 0;
	}
}

void	anim_shotgun(t_wolf *wolf)
{
	if (wolf->shoot == 0)
	{
		mlx_put_image_to_window(wolf->mlx,
			wolf->win, wolf->shotgun_one->image,
				(WIN_WIDTH - 400) / 2, WIN_HEIGHT - 400);
	}
	else if (wolf->shoot == 1)
	{
		if (wolf->fr == 17)
			Mix_PlayChannel(0, wolf->shoot_sound, 0);
		anim_shotgun_help(wolf);
	}
}

void	aim_draw(t_wolf *wolf)
{
	int		x;
	int		y;

	x = (WIN_WIDTH / 2) - 20;
	y = WIN_HEIGHT / 2;
	while (x <= (WIN_WIDTH / 2) + 20)
	{
		wolf->ret_im->pic[4 * (WIN_WIDTH * y + x)] = 0;
		wolf->ret_im->pic[4 * (WIN_WIDTH * y + x) + 1] = 0;
		wolf->ret_im->pic[4 * (WIN_WIDTH * y + x) + 2] = (unsigned char)255;
		x++;
	}
	y = (WIN_HEIGHT / 2) - 20;
	x = WIN_WIDTH / 2;
	while (y <= (WIN_HEIGHT / 2) + 20)
	{
		wolf->ret_im->pic[4 * (WIN_WIDTH * y + x)] = 0;
		wolf->ret_im->pic[4 * (WIN_WIDTH * y + x) + 1] = 0;
		wolf->ret_im->pic[4 * (WIN_WIDTH * y + x) + 2] = (unsigned char)255;
		y++;
	}
}
