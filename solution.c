/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:33:18 by vvinogra          #+#    #+#             */
/*   Updated: 2018/03/13 19:35:46 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw(t_wolf *wolf, int x)
{
	int		line_height;
	double	wall_x;

	line_height = (int)(WIN_HEIGHT / wolf->ray->dist);
	wolf->ray->draw_start = (WIN_HEIGHT - line_height) / 2;
	if (wolf->ray->draw_start < 0)
		wolf->ray->draw_start = 0;
	wolf->ray->draw_end = (WIN_HEIGHT + line_height) / 2;
	if (wolf->ray->draw_end >= WIN_HEIGHT)
		wolf->ray->draw_end = WIN_HEIGHT - 1;
	if (wolf->ray->side == 0)
		wall_x = wolf->ray->player_posy + wolf->ray->dist * wolf->ray->dir_y;
	else
		wall_x = wolf->ray->player_posx + wolf->ray->dist * wolf->ray->dir_x;
	wall_x -= floor(wall_x);
	wolf->ray->text_x = (int)(wall_x * TEXTURE_WIDTH);
	while (wolf->ray->draw_start < wolf->ray->draw_end)
	{
		wolf->ray->text_y = ((wolf->ray->draw_start - WIN_HEIGHT * 0.5f +
			line_height * 0.5f) * TEXTURE_WIDTH) / line_height;
		pixel_image_put(wolf, x, wolf->ray->draw_start);
		wolf->ray->draw_start++;
	}
	floor_direction(wolf, wall_x);
	draw_floor(wolf, x);
}

void	calc_dist(t_wolf *wolf, int x)
{
	while (wolf->ray->hit == 0)
	{
		if (wolf->ray->side_dist_x < wolf->ray->side_dist_y)
		{
			wolf->ray->side_dist_x += wolf->ray->delx;
			wolf->ray->map_x += wolf->ray->step_x;
			wolf->ray->side = 0;
		}
		else
		{
			wolf->ray->side_dist_y += wolf->ray->dely;
			wolf->ray->map_y += wolf->ray->step_y;
			wolf->ray->side = 1;
		}
		calc_dist_help(wolf, x);
	}
}

void	find_step(t_wolf *wolf)
{
	if (wolf->ray->dir_x < 0)
	{
		wolf->ray->step_x = -1;
		wolf->ray->side_dist_x = (wolf->ray->player_posx -
			(int)wolf->ray->player_posx) * wolf->ray->delx;
	}
	else
	{
		wolf->ray->step_x = 1;
		wolf->ray->side_dist_x = ((int)wolf->ray->player_posx + 1
			- wolf->ray->player_posx) * wolf->ray->delx;
	}
	if (wolf->ray->dir_y < 0)
	{
		wolf->ray->step_y = -1;
		wolf->ray->side_dist_y = (wolf->ray->player_posy -
			(int)wolf->ray->player_posy) * wolf->ray->dely;
	}
	else
	{
		wolf->ray->step_y = 1;
		wolf->ray->side_dist_y = ((int)wolf->ray->player_posy + 1
			- wolf->ray->player_posy) * wolf->ray->dely;
	}
}

void	raycast_init(t_wolf *wolf, double x)
{
	wolf->ray->camera = 2 * x / WIN_WIDTH - 1;
	wolf->ray->map_x = (int)wolf->ray->player_posx;
	wolf->ray->map_y = (int)wolf->ray->player_posy;
	wolf->ray->dir_x = wolf->ray->player_dir_x
		+ wolf->ray->plane_x * wolf->ray->camera;
	wolf->ray->dir_y = wolf->ray->player_dir_y
		+ wolf->ray->plane_y * wolf->ray->camera;
	wolf->ray->delx = sqrt(1 + (wolf->ray->dir_y * wolf->ray->dir_y) /
			(wolf->ray->dir_x * wolf->ray->dir_x));
	wolf->ray->dely = sqrt(1 + (wolf->ray->dir_x * wolf->ray->dir_x) /
			(wolf->ray->dir_y * wolf->ray->dir_y));
	wolf->ray->hit = 0;
	wolf->ray->dist = -1;
	wolf->ray->side = -1;
}

void	solution(t_wolf *wolf)
{
	int		x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		raycast_init(wolf, (double)x);
		find_step(wolf);
		calc_dist(wolf, x);
		draw(wolf, x);
		x++;
	}
	aim_draw(wolf);
	wolf->nb_shot_walls = 0;
}
