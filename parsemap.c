/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 19:44:19 by vvinogra          #+#    #+#             */
/*   Updated: 2018/03/13 16:55:57 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	get_player_info(char **map, t_wolf *wolf)
{
	char	**tmp;

	tmp = ft_strsplit(map[0], ' ');
	if (count_s(tmp) != 2)
	{
		write(1, "Incorrect player info\n", 22);
		exit(0);
	}
	check_map_line(tmp);
	if (ft_atoi(tmp[0]) < wolf->map_len
			&& ft_atoi(tmp[1]) < wolf->map_height
				&& ft_atoi(tmp[0]) > 0 && ft_atoi(tmp[1]) > 0
					&& wolf->map[ft_atoi(tmp[1])][ft_atoi(tmp[0])] == 0)
	{
		wolf->ray->player_posx = (double)ft_atoi(tmp[1]) + 0.5;
		wolf->ray->player_posy = (double)ft_atoi(tmp[0]) + 0.5;
	}
	else
	{
		write(1, "Incorrect player info\n", 22);
		exit(0);
	}
	free_double_arr(tmp);
}

void	map_verify(char **map, t_wolf *wolf)
{
	int		i;
	char	**tmp;
	int		map_len;

	i = 1;
	tmp = ft_strsplit(map[i], ' ');
	map_len = count_s(tmp);
	free_double_arr(tmp);
	while (map[i])
	{
		tmp = ft_strsplit(map[i], ' ');
		if (map_len != count_s(tmp) || count_s(tmp) == 0)
		{
			write(1, "Incorrect map size\n", 19);
			exit(0);
		}
		map_verify_help(i, map, tmp);
		free_double_arr(tmp);
		i++;
	}
	wolf->map_len = map_len;
}

t_wolf	*parsemap(char **map)
{
	t_wolf	*wolf;
	char	**tmp;
	int		i;
	int		j;

	i = 1;
	wolf = malloc(sizeof(t_wolf));
	wolf->map = malloc(sizeof(int *) * (count_s(map)));
	map_verify(map, wolf);
	while (map[i])
	{
		tmp = ft_strsplit(map[i], ' ');
		check_map_line(tmp);
		j = 0;
		wolf->map[i - 1] = malloc(sizeof(int) * (count_s(tmp)));
		while (tmp[j])
		{
			wolf->map[i - 1][j] = ft_atoi(tmp[j]);
			j++;
		}
		free_double_arr(tmp);
		i++;
	}
	wolf->map_height = count_s(map) - 1;
	return (wolf);
}

t_list	*read_from_file(int fd)
{
	t_list	*list;
	t_list	*tmp;
	char	*line_from_file;

	list = 0;
	while (get_next_line(fd, &line_from_file))
	{
		tmp = malloc(sizeof(t_list));
		tmp->content = ft_strdup(line_from_file);
		tmp->next = 0;
		ft_lstpushback(&list, tmp);
		ft_strdel(&line_from_file);
	}
	ft_strdel(&line_from_file);
	close(fd);
	return (list);
}

char	**getmap(int fd)
{
	char	**map;
	t_list	*list;
	t_list	*tmp;
	int		i;

	list = read_from_file(fd);
	map = malloc(sizeof(char *) * (ft_lst_len_count(list) + 1));
	i = 0;
	tmp = list;
	while (tmp)
	{
		map[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	ft_lstdel(&list, del);
	map[i] = 0;
	if (count_s(map) < 3 || count_s(map) > 1001)
	{
		write(1, "Incorrect map size\n", 19);
		exit(0);
	}
	return (map);
}
