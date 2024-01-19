/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelil <sbelil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:25:02 by sbelil            #+#    #+#             */
/*   Updated: 2024/01/14 12:03:11 by sbelil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(int fd, char *str)
{
	char	*to_read;
	ssize_t	r;
	char	*tmp;

	if (!str)
		str = ft_strdup("");
	to_read = malloc((size_t)BUFFER_SIZE + 1);
	if (!to_read)
		return (free(str), NULL);
	while (str && !ft_strchr(str, '\n'))
	{
		tmp = str;
		r = read(fd, to_read, BUFFER_SIZE);
		if (!r)
			break ;
		if (r == -1)
			return (free(to_read), free(str), NULL);
		to_read[r] = '\0';
		str = ft_strjoin(str, to_read);
		free(tmp);
	}
	return (free(to_read), str);
}

static t_resume	ft_resume(char *str)
{
	t_resume	ret;
	size_t		len;
	size_t		size_r;

	len = ft_strlen(str);
	size_r = 0;
	while (str[size_r] != '\n' && str[size_r])
		size_r++;
	if (!str[size_r])
		return (ret.sub1 = ft_strdup(str), free(str), ret.sub2 = NULL, ret);
	ret.sub1 = ft_substr(str, 0, size_r + 1);
	if (!ret.sub1)
		return (free(str), str = NULL, ret);
	ret.sub2 = ft_substr(str, size_r + 1, len);
	free(str);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	t_resume	ret;

	if (fd < 0)
		return (NULL);
	storage = ft_read_line(fd, storage);
	if (!storage)
		return (NULL);
	if (!storage[0])
		return (free(storage), storage = NULL, NULL);
	ret = ft_resume(storage);
	storage = ret.sub2;
	return (ret.sub1);
}
