/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:27:48 by gvarys            #+#    #+#             */
/*   Updated: 2021/10/18 19:06:51 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*ft_strdupbn(const char *s, int len)
{
	char	*ns;
	int		i;
	
	ns = (char *)malloc(len + 1);
	if (ns == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\n')
	{
		ns[i] = s[i];
		i++;
	}
	ns[i] = '\n';
	ns[i + 1] = '\0';
	return (ns);
}

char	*crtstr(size_t size)
{
	char	*str;

	str = (char *)malloc(size);
	while (*str)
	{
		*str = '\0';
	}
	return (str);
}

char	*get_line(char **save, int fd)
{
	int		i;
	char	*temp;
	char	*line;

	i = 0;
	while (save[fd][i] != '\n' && save[fd][i] != '\0')
		i++;
	if (save[fd][i] == '\n' && save[fd][0] != '\n')
	{
		line = ft_strdupbn(save[fd], i + 1);
		temp = ft_strdup(save[fd] + (i + 1));
		strdell(&save[fd]);
		save[fd] = temp;
		if (save[fd][0] == '\0')
			strdell(&save[fd]);
	}
	else if ((save[fd][i] == '\0' || save[fd][0] == '\n')  && save[fd][0] != '\0')
	{
		line = ft_strdup(save[fd]);
		if (line[0] == '\0')
			line = NULL;
		strdell(&save[fd]);
	}
	else
		line = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save[100000];
	char		buf[BUFFER_SIZE + 1];
	ssize_t		rd;
	char		*temp;

	if (fd < 0 || fd > 100000 || BUFFER_SIZE < 1)
		return (NULL);
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		buf[rd] = '\0';
		if (!save[fd])
			save[fd] = crtstr(1);
		temp = ft_strjoin(save[fd], buf);
		strdell(&save[fd]);
		save[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (rd < 0)
		return (NULL);
	return (get_line(save, fd));
}

// int main()
// {
// 	int i;

// 	i = open("text", O_RDONLY);
// 	printf("%s\n", get_next_line(i));
// 	printf("%s\n", get_next_line(i));
// 	printf("%s\n", get_next_line(i));
// 	close(i);
// 	getchar();
// }