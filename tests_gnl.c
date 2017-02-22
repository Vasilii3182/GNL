/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_gnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 17:26:40 by ofranco           #+#    #+#             */
/*   Updated: 2017/02/22 21:06:15 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

int ft_chrono(int fd, int size, char **buffer)
{
	int ret;

	if ((*buffer = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (-2);
	ret = read(fd, *buffer, size);
	(*buffer)[size] = '\0';
	return (ret);
}

int get_next_line(const int fd, char **line)
{
	static char *leftover[5000];
	char *str;
	char *truc;
	char *empty;
	int read_value;
	char *tmp;

	
	empty = (leftover[fd] == NULL) ? "" : leftover[fd];
	if ((truc = (ft_strchr(empty, '\n'))) != NULL)
	{
		*truc = '\0';
		*line = ft_strdup(empty);
		leftover[fd] = ft_strdup(truc + 1);
		free(empty);
		return (0);
	}
	while ((read_value = ft_chrono(fd, BUFF_SIZE, &str)) > 0)
	{
		truc = ft_strchr(str, '\n');
		if (truc != NULL)
			*truc = '\0';
		tmp = empty;
		empty = ft_strjoin(empty, str);
		if (leftover[fd] != NULL)
			free(tmp);
		if (truc != NULL)
			break;
	}
	if (read_value == -2)
		return (-1);
	leftover[fd] = ft_strdup(truc + 1);
	free(str);
	*line = empty;
	return (0);
}

int main (int argc, char **argv)
{
	char *buffer;
	int fd;
	if (argc > 2)
	{
		printf("bah non.\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY, S_IREAD);
	/*while (get_next_line(fd, &buffer) == 1)
	  {
	  printf("lecture en cours...\n");
	  printf("%s\n", buffer);
	  ft_putstr(buffer);
	  }*/
	if (get_next_line(fd, &buffer) == 0)
	{
		printf("lecture terminee !\n");
		printf("%s\n", buffer);
	}
	if (get_next_line(fd, &buffer) == 0)
	{
		printf("lecture terminee !\n");
		printf("%s\n", buffer);
		return (0);
	}
	return (0);
}
