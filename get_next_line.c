/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:41:24 by ofranco           #+#    #+#             */
/*   Updated: 2017/09/16 19:59:10 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*ft_strcharcpy(char *src, char c)
{
	int		i;
	char	*cpy;

	i = 0;
	while (src[i] != c)
	{
		if (src[i] == '\0')
			break ;
		i++;
	}
	if ((cpy = (char*)malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	cpy = ft_strncpy(cpy, src, i);
	cpy[i]= '\0';
	return (cpy);
}

int		ft_chrono(int fd, char **buffer)
{
	int ret;

	if ((*buffer = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
		return (-2);
	ret = read(fd, *buffer, BUFF_SIZE);
	(*buffer)[ret] = '\0';
	return (ret);
}

int		ft_if_return(char *empty, char **line, char **leftover)
{
	if (ft_strchr(empty, '\n') != NULL)
	{
		//printf("empty =%s\n", empty);
		*line = ft_strcharcpy(empty, '\n');
		*leftover = ft_strdup(ft_strchr(empty, '\n') + 1);
		//printf("line =%s\n", *line);
		//printf("leftover =%s\n", *leftover);
		return (1);
	}
	return (0);
}

void	ft_remains(char *empty, char **leftover)
{
	if (ft_strchr(empty, '\n') != NULL)
		*leftover = ft_strdup(ft_strchr(empty, '\n') + 1);
	else 
		*leftover = NULL;
}

int		get_next_line(const int fd, char **line)
{
	static char	*leftover[5000];
	char		*str;
	char		*empty;
	int			read_value;

	if ((int)fd < 0)
		return (-1);
	empty = (leftover[fd] == NULL) ? "" : leftover[fd];
	if (ft_if_return(empty, line, &leftover[fd]) == 1)
	{
		return (1);
	}
	while ((read_value = ft_chrono(fd, &str)) > 0)
	{
		empty = ft_strjoin(empty, str);
		if (ft_strchr(empty, '\n') != NULL)
			break ;
	}
	if (read_value < 0 || fd < 0)
		return (-1);
	ft_remains(empty, &leftover[fd]);
	*line = ft_strcharcpy(empty, '\n');
	if (*line[0] == '\0' && read_value == 0 && leftover[fd] == NULL)
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	char *buffer;
	int fd;
	int result;

	if (argc > 2)
		return (7);
	fd = open(argv[1], O_RDONLY, S_IREAD);
	while ((result = get_next_line(fd, &buffer)) > 0)
	{
		printf("%s", buffer);
	}
	return (0);
}
