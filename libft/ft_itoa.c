/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 13:55:05 by vvinogra          #+#    #+#             */
/*   Updated: 2017/12/24 17:37:04 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count(int n)
{
	int count;

	count = 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void		recursion(int *i, int n, char *str)
{
	if (n == -2147483648)
	{
		str[(*i)++] = '-';
		str[(*i)++] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		n = -n;
		str[(*i)++] = '-';
	}
	if (n >= 10)
	{
		recursion(i, n / 10, str);
		recursion(i, n % 10, str);
	}
	else
	{
		str[*i] = n + 48;
		(*i)++;
	}
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = 0;
	if (n < 0)
		str = (char *)malloc(sizeof(char) * (count(n) + 2));
	else
		str = (char *)malloc(sizeof(char) * (count(n) + 1));
	if (!str)
		return (NULL);
	recursion(&i, n, str);
	str[i] = '\0';
	return (str);
}
