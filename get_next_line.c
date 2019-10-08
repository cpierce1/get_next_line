/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:51:33 by cpierce           #+#    #+#             */
/*   Updated: 2019/10/07 21:06:13 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

char	*line_gen(char **info, const int fd)
{
	char		*data;
	char		*res;
	char		*tmp;
	int			len;

	data = ft_strdup(info[fd]);
	if ((len = ft_str_indexof(info[fd], '\n')) != -1)
	{
		res = ft_strsub(info[fd], 0, len);
		tmp = ft_strsub(info[fd], len + 1, ft_strlen(data) - len - 1);
		free(info[fd]);
		info[fd] = ft_strdup(tmp);
		free(tmp);
	}
	else
		return (ft_strdup(info[fd]));
	return (res);
}

int		get_next_line(const int fd, char **line)
{
	static char	*files[1024];
	char		buff[8 + 1];
	int			byts;
	char		*data;

	if (files[fd])
	{
		line[0] = line_gen(files, fd);
		return (1);
	}
	data = ft_strdup("");
	while ((byts = read(fd, buff, 8)))
	{
		buff[byts] = '\0';
		data = ft_strjoin(data, buff);
	}
	free(files[fd]);
	files[fd] = ft_strdup(data);
	free(data);
	line[0] = line_gen(files, fd);
	return (1);
}
