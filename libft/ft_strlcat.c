/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:27:17 by vvinogra          #+#    #+#             */
/*   Updated: 2017/11/17 14:39:08 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t m;

	i = 0;
	j = 0;
	m = ft_strlen(dst);
	while (dst[i])
		i++;
	while (i + 1 < size)
	{
		dst[i++] = src[j++];
	}
	if (size > m)
		return (m + ft_strlen(src));
	return (ft_strlen(src) + size);
}
