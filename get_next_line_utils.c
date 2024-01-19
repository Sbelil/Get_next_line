/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelil <sbelil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:24:59 by sbelil            #+#    #+#             */
/*   Updated: 2024/01/16 13:06:19 by sbelil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	count;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	count = -1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = malloc(s1_len + s2_len + 1);
	if (!res)
		return (NULL);
	while (++count < s1_len)
		res[count] = s1[count];
	while (count < s1_len + s2_len)
	{
		res[count] = s2[count - s1_len];
		count++;
	}
	res[count] = '\0';
	return (res);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_len;
	size_t	end;
	size_t	count;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	end = 0;
	count = 0;
	if (start < s_len)
		end = s_len - start;
	if (end > len)
		end = len;
	res = (char *)malloc(sizeof(char) * (end + 1));
	if (!res)
		return (NULL);
	while (count < end)
	{
		res[count] = s[start + count];
		count++;
	}
	res[count] = '\0';
	return (res);
}

char	*ft_strchr(char *s, int c)
{
	char	*count;

	count = (char *) s;
	while (*count)
	{
		if (*count == (char) c)
			return (count);
		count++;
	}
	if (*count == (char) c)
		return (count);
	return (NULL);
}

char	*ft_strdup(char *s1)
{
	char	*res;
	size_t	count;

	count = 0;
	res = (char *)malloc((ft_strlen(s1) * sizeof(char)) + 1);
	if (!res)
		return (NULL);
	while (s1[count])
	{
		res[count] = s1[count];
		count++;
	}
	res[count] = '\0';
	return (res);
}
