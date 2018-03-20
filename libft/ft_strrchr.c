/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:10:48 by vvinogra          #+#    #+#             */
/*   Updated: 2017/10/27 19:10:49 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*str_re;
	size_t	i;
	char	sym;

	str = (char *)s;
	i = 0;
	str_re = NULL;
	sym = (char)c;
	while (str[i])
	{
		if (str[i] == sym)
			str_re = &str[i];
		i++;
	}
	if (str[i] == sym)
		str_re = &str[i];
	return (str_re);
}
