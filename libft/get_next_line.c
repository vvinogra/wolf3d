/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:29:57 by vvinogra          #+#    #+#             */
/*   Updated: 2017/11/17 16:29:58 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*str_cpy_till_line(char *str)
{
	int		i;
	char	*s;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	s = ft_strnew(i);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char		*join(char *str, char *buf)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	s = ft_strdup(str);
	ft_strdel(&str);
	str = (char *)malloc(sizeof(char) * (ft_strlen(buf) + len + 1));
	if (str == 0)
		return (0);
	ft_strcpy(str, s);
	ft_strdel(&s);
	while (buf[i])
	{
		str[i + len] = buf[i];
		i++;
	}
	str[i + len] = '\0';
	return (str);
}

static int		read_from_file(t_file *file, char **line)
{
	int		ret;

	if (file->tem != 0)
	{
		file->str = ft_strsub(file->leaks, 1, ft_strlen(file->leaks));
		ft_strdel(&file->leaks);
		file->tem = ft_strchr(file->str, '\n');
	}
	else
		file->str = ft_strnew(0);
	while ((ret = read(file->fd, file->buf, BUFF_SIZE)))
	{
		file->buf[ret] = '\0';
		file->str = join(file->str, file->buf);
		if ((file->tem = ft_strchr(file->str, '\n')))
			break ;
	}
	ft_strdel(&file->buf);
	*line = str_cpy_till_line(file->str);
	if (file->tem != 0)
		file->leaks = ft_strdup(file->tem);
	ft_strdel(&file->str);
	if (file->tem == NULL && ret == 0 && *line[0] == '\0')
		return (0);
	return (1);
}

static	t_file	*find_fd(t_file **file, int fd)
{
	t_file *temp;

	temp = *file;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	temp = (t_file *)malloc(sizeof(t_file));
	temp->tem = 0;
	temp->fd = fd;
	temp->next = *file;
	*file = temp;
	return (temp);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*files = 0;
	t_file			*file;

	if (fd < 0 || !line || BUFF_SIZE <= 0 || read(fd, *line, 0) == -1)
		return (-1);
	file = find_fd(&files, fd);
	if (!(file->buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (read_from_file(file, line) == 1)
		return (1);
	return (0);
}
