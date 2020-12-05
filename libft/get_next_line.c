/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koparker_get_next_line.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <koparker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 22:57:29 by koparker          #+#    #+#             */
/*   Updated: 2019/09/23 20:02:35 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** task-specific strjoin function.
** In the first call of the gnl-function holder is empty,
** so it's strduped with buf value. In other cases it joins
** existing holder and new buf.
*/

static char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*res;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(res = ft_strnew(len1 + len2 + 2)))
		return (NULL);
	while (i < (len1 + len2))
	{
		if (i < len1)
			res[i] = s1[i];
		else if (i - len1 < len2)
			res[i] = s2[i - len1];
		i++;
	}
	return (res);
}

static void	read_line(int fd, char **holder, char *buf)
{
	int		ret;
	char	*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = holder[fd];
		holder[fd] = ft_strjoin_gnl(tmp, buf);
		free(tmp);
		if (ft_strchr(holder[fd], '\n') != NULL)
			break ;
	}
}

static int	write_line(int fd, char **holder, char **line)
{
	char	*tmp;
	char	*tmp2;
	size_t	idx;

	if ((tmp = ft_strchr(holder[fd], '\n')) != NULL)
	{
		idx = tmp - holder[fd];
		*line = ft_strsub(holder[fd], 0, idx);
		tmp2 = holder[fd];
		holder[fd] = ft_strdup(&tmp2[idx] + 1);
		free(tmp2);
		return (1);
	}
	if (*holder[fd])
	{
		*line = ft_strdup(holder[fd]);
		free(holder[fd]);
		holder[fd] = NULL;
		return (1);
	}
	free(holder[fd]);
	holder[fd] = NULL;
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char		*holder[MAX_FDS];
	char			*buf;

	if (fd < 0 || read(fd, NULL, 0) < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if (!(buf = ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	read_line(fd, holder, buf);
	free(buf);
	if (holder[fd])
		return (write_line(fd, holder, line));
	return (0);
}
