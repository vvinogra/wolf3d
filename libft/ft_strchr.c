/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:07:05 by vvinogra          #+#    #+#             */
/*   Updated: 2017/10/27 18:07:06 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;
	char	m;

	str = (char *)s;
	i = 0;
	m = (char)c;
	while (str[i])
	{
		if (str[i] == m)
			return (&str[i]);
		i++;
	}
	if (str[i] == m)
		return (&str[i]);
	return (NULL);
}
