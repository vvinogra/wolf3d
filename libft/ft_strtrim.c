/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:46:20 by vvinogra          #+#    #+#             */
/*   Updated: 2017/10/30 20:46:22 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	i;
	char	*str;
	size_t	m;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = -1;
	m = 0;
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	while ((s[++i] == ' ' || s[i] == '\t' || s[i] == '\n') && len > 0)
		len--;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (m < len)
	{
		str[m++] = s[i++];
	}
	str[m] = '\0';
	return (str);
}
