/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:06:10 by ofranco           #+#    #+#             */
/*   Updated: 2017/02/15 21:07:59 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{

}

int	main(int argc, char *argv)
{
	int fd;
	char *buffer;
	
	fd = open(argv[1], O_RDONLY, S_IREAD);
	while (get_next_line(fd, &buffer) == 1)
	{
		ft_putstr(buffer);
	}
	if (get_next_line(fd, &buffer) == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	return (0);
}
