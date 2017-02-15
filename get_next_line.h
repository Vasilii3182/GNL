/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:08:42 by ofranco           #+#    #+#             */
/*   Updated: 2017/02/15 18:05:17 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# include <fcntl.h>
# include <stdlib.h>
# define BUFF_SIZE 32

int	get_next_line(const int fd, char **line);

#endif