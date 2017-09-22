#include "get_next_line.h"
#include <stdio.h>

int	ft_strfindchr(char *str,char c)
{
	int	i;

	if (c == '\0')
		return (ft_strlen(str));
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		else
			i++;
	}
	return (-1);
}

int	ft_transfer(char *src,char **dest)
{
	int	pos;
	int	i;
	char	*tmp;

	//printf("entree dans ft_transfer\n");
	pos = ft_strfindchr(src, '\n');
	tmp = *dest;
	if (pos==-1)
	{
		*dest = ft_strjoin(*dest,src);
		free(tmp);
		src[0] = '\0';
		//printf("return 0\n");
		return (0);
	} 
	else 
	{
		src[pos] = '\0';
		*dest = ft_strjoin(*dest,src);
		free(tmp);
		pos++;
		i = 0;
		while(src[pos] != '\0')
		{
			src[i] = src[pos];
			i++;
			pos++;
		}
		src[i] = '\0';
		//printf("Return 1\n");
		return (1);
	}
}

/*int	ft_halfs(char *buffer, char *line, int fd)
{
	int read_ret;

	if (ft_transfer(buffer, &line))
		return (1);
	while ((read_ret = read(fd, &buffer, BUFF_SIZE)) > 0)
	{
		printf("avant buffer: read_ret ==%d\n", read_ret);
		buffer[read_ret] = '\0';
		printf("apres buffer\n");
		if (ft_transfer(buffer, &line))
		{	
			return (1);
		}
	}
	if (read_ret == 0)
	{
		return (ft_strlen(line) == 0 ? 0 : 1);
	}
	return (-5);
}*/

int	get_next_line(const int fd, char **line)
{
	static char	*buffer;
	static int	current_fd = -1;
	int 	read_ret;

	if (fd < 0 || !line)
		return (-1);
	if (!buffer && (buffer = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
		return (-1);
	printf("len =%lu\n", ft_strlen(buffer));
	if (fd != current_fd)
		buffer[0] = '\0';
	current_fd = fd;
	*line = ft_strnew(0);
	//if ((read_ret = ft_halfs(buffer, *line, fd)) >= 0)
	//	return (read_ret);
	if (ft_transfer(buffer,line))
	return (1);
	while ((read_ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
	buffer[read_ret] = '\0';
	if (ft_transfer(buffer, line))
	return (1);
	}
	if (read_ret == 0)
	return (ft_strlen(*line) == 0 ? 0 : 1);
	free(*line);
	*line = NULL;
	return (-1);
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
		printf("result = %d\n", result);
		printf("%s\n", buffer);
	}
	return (0);
}
