/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 19:43:39 by vvinogra          #+#    #+#             */
/*   Updated: 2018/03/13 19:23:54 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		count_s(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_double_arr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	check_map_line(char **line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		j = 0;
		if (ft_strlen(line[i]) > 5)
		{
			write(1, "Wrong file format\n", 18);
			exit(0);
		}
		while (line[i][j])
		{
			if (line[i][j] < '0' || line[i][j] > '9')
			{
				write(1, "Wrong file format\n", 18);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	map_verify_help(int i, char **map, char **tmp)
{
	int	j;

	j = 0;
	while (tmp[j])
	{
		if ((i == 1 || map[i + 1] == 0 || j == 0
			|| tmp[j + 1] == 0) && ft_atoi(tmp[j]) != 1)
		{
			write(1, "Incorrect map\n", 14);
			exit(0);
		}
		j++;
	}
}

void	calc_dist_help(t_wolf *wolf, int x)
{
	if (wolf->map[wolf->ray->map_x][wolf->ray->map_y] > 0)
	{
		wolf->ray->hit = 1;
		if (wolf->ray->side == 0)
			wolf->ray->dist = (wolf->ray->map_x - wolf->ray->player_posx +
				(1 - wolf->ray->step_x) / 2) / wolf->ray->dir_x;
		else
			wolf->ray->dist = (wolf->ray->map_y - wolf->ray->player_posy +
				(1 - wolf->ray->step_y) / 2) / wolf->ray->dir_y;
	}
	if (wolf->map[wolf->ray->map_x][wolf->ray->map_y] == 2 &&
			wolf->fr == 16 && x == WIN_WIDTH / 2 &&
				wolf->nb_shot_walls == 0 && wolf->ray->dist < 1.5)
	{
		wolf->ray->hit = 0;
		wolf->nb_shot_walls = 1;
		wolf->map[wolf->ray->map_x][wolf->ray->map_y] = 0;
	}
}
