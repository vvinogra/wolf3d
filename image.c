/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 19:36:12 by vvinogra          #+#    #+#             */
/*   Updated: 2018/03/14 14:03:39 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	pixel_image_put(t_wolf *wolf, int x, int y)
{
	t_image	*tmp;

	if (wolf->ray->side == 0 && wolf->ray->dir_x >= 0)
		tmp = wolf->blue_br;
	else if (wolf->ray->side == 0 && wolf->ray->dir_x < 0)
		tmp = wolf->br;
	else if (wolf->ray->side == 1 && wolf->ray->dir_y >= 0)
		tmp = wolf->br_one;
	else
		tmp = wolf->br_two;
	if (wolf->map[wolf->ray->map_x][wolf->ray->map_y] == 2)
		tmp = wolf->br_one;
	wolf->ret_im->pic[4 * (WIN_WIDTH * y + x)] = tmp->pic
		[4 * (TEXTURE_WIDTH * wolf->ray->text_y + wolf->ray->text_x)];
	wolf->ret_im->pic[4 * (WIN_WIDTH * y + x) + 1] = tmp->pic
		[4 * (TEXTURE_WIDTH * wolf->ray->text_y + wolf->ray->text_x) + 1];
	wolf->ret_im->pic[4 * (WIN_WIDTH * y + x) + 2] = tmp->pic
		[4 * (TEXTURE_WIDTH * wolf->ray->text_y + wolf->ray->text_x) + 2];
}

t_image	*create_new_im(void *mlx)
{
	t_image *im;

	im = (t_image *)malloc(sizeof(t_image));
	im->image = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	im->pic = mlx_get_data_addr(im->image, &im->bpp, &im->stride, &im->endian);
	im->bpp /= 8;
	return (im);
}

void	image_clear(t_image *im)
{
	ft_bzero(im->pic, WIN_WIDTH * WIN_HEIGHT * im->bpp);
}

void	check_images(t_wolf *wolf)
{
	if (wolf->blue_br->image == 0 || wolf->br->image == 0 ||
		wolf->br_one->image == 0 || wolf->br_two->image == 0 ||
		wolf->floor->image == 0 || wolf->shotgun_one->image == 0 ||
		wolf->shotgun_two->image == 0 || wolf->shotgun_three->image == 0 ||
		wolf->shotgun_four->image == 0 || wolf->shotgun_five->image == 0 ||
		wolf->ceiling->image == 0)
	{
		write(1, "Textures weren't found\n", 23);
		exit(0);
	}
}
