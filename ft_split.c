/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:18:57 by olamrabt          #+#    #+#             */
/*   Updated: 2024/03/01 18:16:51 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int		i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (!size)
		return (src_len);
	while (--size && *src)
	{
		*dest = *src;
		src++;
		dest++;
		i++;
	}
	*dest = '\0';
	while (*(src++))
		i++;
	return (i);
}

static size_t	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_free(char **copy, size_t j)
{
	while (j--)
		free(copy[j]);
	free(copy);
	return (NULL);
}

static char	**str_split(char const *s, char c, size_t i, size_t len)
{
	size_t	j;
	char	**copy;

	j = 0;
	copy = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!copy)
		return (NULL);
	while (j < count_words(s, c))
	{
		len = 0;
		while (s[i] == c)
			i++;
		while (s[i + len] && s[i + len] != c)
			len++;
		copy[j] = (char *)malloc((len + 1) * sizeof(char));
		if (!copy[j])
			return (ft_free(copy, j));
		ft_strlcpy(copy[j], (s + i), len + 1);
		i += len;
		j++;
	}
	copy[j] = NULL;
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!s || !*s)
		return (NULL);
	return (str_split(s, c, i, len));
}
