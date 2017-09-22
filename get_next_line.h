/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:47:38 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/22 20:56:48 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# include <fcntl.h>
# include <stdlib.h>
# include "./libft/includes/libft.h"

# define BUFF_SIZE 5

int	get_next_line(const int fd, char **line);

#endif
