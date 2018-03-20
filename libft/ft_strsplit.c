/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:48:21 by vvinogra          #+#    #+#             */
/*   Updated: 2017/10/31 17:48:22 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			count++;
		}
		i++;
	}
	if (s[i - 1] == c)
		return (count);
	return (count + 1);
}

static int	count_sym(char const *s, char c, int i)
{
	int count;

	count = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	return (count);
}

static void	*helper(char c, char const *s, char **str)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			k = 0;
			str[j] = (char *)malloc(sizeof(char) * (count_sym(s, c, i) + 1));
			if (str[j] == NULL)
				return (NULL);
			while (s[i] != c && s[i])
				str[j][k++] = s[i++];
			str[j++][k] = '\0';
		}
	}
	str[j] = NULL;
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char **str;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (str == NULL)
		return (NULL);
	helper(c, s, str);
	return (str);
}
