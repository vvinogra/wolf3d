/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:36:47 by vvinogra          #+#    #+#             */
/*   Updated: 2018/03/13 17:20:12 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		file_valid(int argc, char **argv)
{
	int		fd;
	int		ch;

	if (argc != 2)
	{
		write(1, "Usage: ./wolf3d <file>\n", 23);
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "./wolf3d: ", 10);
		perror(argv[1]);
		exit(0);
	}
	ch = open(argv[1], O_DIRECTORY);
	if (ch > 0)
	{
		close(ch);
		ft_putstr(argv[1]);
		write(1, " is a directory\n", 16);
		exit(0);
	}
	return (fd);
}

int		main(int argc, char **argv)
{
	t_wolf	*wolf;
	int		fd;
	char	**map;

	fd = file_valid(argc, argv);
	map = getmap(fd);
	wolf = init(map);
	get_player_info(map, wolf);
	init_im(wolf);
	play_music(wolf);
	mlx_hook(wolf->win, 17, 1L << 17, exit_x, wolf);
	mlx_hook(wolf->win, 2, 1L << 0, hook, wolf);
	mlx_hook(wolf->win, 3, 1L << 1, exposehook, wolf);
	mlx_loop_hook(wolf->mlx, loop_hook, wolf);
	mlx_loop(wolf->mlx);
}
