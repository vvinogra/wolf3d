/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 21:26:14 by vvinogra          #+#    #+#             */
/*   Updated: 2018/03/14 16:14:23 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	pixel_floor_put(t_wolf *wolf, int x, int y)
{
	y = WIN_HEIGHT - y;
	wolf->ret_im->pic[4 * (WIN_WIDTH * y + x)] = wolf->ceiling->pic
		[4 * (TEXTURE_WIDTH * wolf->ray->floor_text_y
			+ wolf->ray->floor_text_x)];
	wolf->ret_im->pic[4 * (WIN_WIDTH * y + x) + 1] = wolf->ceiling->pic
		[4 * (TEXTURE_WIDTH * wolf->ray->floor_text_y +
			wolf->ray->floor_text_x) + 1];
	wolf->ret_im->pic[4 * (WIN_WIDTH * y + x) + 2] = wolf->ceiling->pic
		[4 * (TEXTURE_WIDTH * wolf->ray->floor_text_y +
			wolf->ray->floor_text_x) + 2];
}

void	pixel_ceiling_put(t_wolf *wolf, int x, int y)
{
	wolf->ret_im->pic[4 * (WIN_WIDTH * y + x)] = wolf->floor->pic
		[4 * (TEXTURE_WIDTH * wolf->ray->floor_text_y
			+ wolf->ray->floor_text_x)];
	wolf->ret_im->pic[4 * (WIN_WIDTH * y + x) + 1] = wolf->floor->pic
		[4 * (TEXTURE_WIDTH * wolf->ray->floor_text_y +
			wolf->ray->floor_text_x) + 1];
	wolf->ret_im->pic[4 * (WIN_WIDTH * y + x) + 2] = wolf->floor->pic
		[4 * (TEXTURE_WIDTH * wolf->ray->floor_text_y +
			wolf->ray->floor_text_x) + 2];
}

void	draw_floor(t_wolf *wolf, int x)
{
	double	current_dist;
	int		y;
	double	cur_floor_x;
	double	cur_floor_y;

	y = wolf->ray->draw_end + 1;
	while (y < WIN_HEIGHT)
	{
		current_dist = (double)WIN_HEIGHT /
			(2 * (double)y - (double)WIN_HEIGHT);
		cur_floor_x = current_dist / wolf->ray->dist * wolf->ray->floor_x +
			(1 - (current_dist / wolf->ray->dist)) * wolf->ray->player_posx;
		cur_floor_y = current_dist / wolf->ray->dist * wolf->ray->floor_y +
			(1 - (current_dist / wolf->ray->dist)) * wolf->ray->player_posy;
		wolf->ray->floor_text_x = (int)(cur_floor_x * TEXTURE_WIDTH)
			% TEXTURE_WIDTH;
		wolf->ray->floor_text_y = (int)(cur_floor_y * TEXTURE_HEIGHT)
			% TEXTURE_HEIGHT;
		pixel_floor_put(wolf, x, y);
		pixel_ceiling_put(wolf, x, y);
		y++;
	}
}

void	floor_direction(t_wolf *wolf, double wall_x)
{
	if (wolf->ray->side == 0 && wolf->ray->dir_x > 0)
	{
		wolf->ray->floor_x = wolf->ray->map_x;
		wolf->ray->floor_y = wolf->ray->map_y + wall_x;
	}
	else if (wolf->ray->side == 0 && wolf->ray->dir_x < 0)
	{
		wolf->ray->floor_x = wolf->ray->map_x + 1;
		wolf->ray->floor_y = wolf->ray->map_y + wall_x;
	}
	else if (wolf->ray->side == 1 && wolf->ray->dir_y > 0)
	{
		wolf->ray->floor_x = wolf->ray->map_x + wall_x;
		wolf->ray->floor_y = wolf->ray->map_y;
	}
	else
	{
		wolf->ray->floor_x = wolf->ray->map_x + wall_x;
		wolf->ray->floor_y = wolf->ray->map_y + 1;
	}
	if (wolf->ray->draw_end < 0)
		wolf->ray->draw_end = WIN_HEIGHT;
}
