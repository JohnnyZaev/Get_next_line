/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:27:39 by gvarys            #+#    #+#             */
/*   Updated: 2021/10/18 13:54:26 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	strdell(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
}

char	*ft_strdup(const char *s)
{
	char	*ns;
	int		i;

	ns = (char *)malloc(ft_strlen(s) + 1);
	if (ns == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ns[i] = s[i];
		i++;
	}
	ns[i] = '\0';
	return (ns);
}

char	*ft_strchr(const char *str, int c)
{
	char	*temp;

	temp = (char *)str;
	while (*temp != '\0')
	{
		if (*temp == (char)c)
			return (temp);
		temp++;
	}
	if (*temp == (char)c)
		return (temp);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ns;
	int		i;
	int		j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	ns = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ns == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		ns[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		ns[i++] = s2[j++];
	ns[i] = '\0';
	return (ns);
}
