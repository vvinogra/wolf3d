/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 20:21:28 by vvinogra          #+#    #+#             */
/*   Updated: 2017/10/26 20:21:29 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*src1;
	size_t	i;

	i = 0;
	src1 = (char *)src;
	while (src1[i])
	{
		dst[i] = src1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
