/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:16:36 by dcarrilh          #+#    #+#             */
/*   Updated: 2022/11/23 15:58:08 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*first_line(char *file)
{
	size_t	size;
	char	*line;

	size = 0;
	if (!file[size])
		return (0);
	while (file[size] != '\n' && file[size])
		size++;
	line = ft_calloc((size + 2), sizeof(char));
	if (file[size] == '\n' || file[size] == '\0')
		ft_strlcpy(line, file, size + 1);
	if (file[size] == '\n')
		line[size++] = '\n';
	return (line);
}

static char	*new_file(char *file)
{
	size_t	size;
	char	*resto;

	size = 0;
	while (file[size] != '\n' && file[size])
		size++;
	if (!file[size])
	{
		free(file);
		return (0);
	}
	size++;
	resto = ft_substr(file, size, ft_strlen(file)-size);
	free(file);
	return (resto);
}

static char	*ini_file(int fd, char *file)
{
	char	*buff;
	ssize_t	readbytes;
	char	*temp;

	if (ft_strchr(file, '\n'))
		return (file);
	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	readbytes = 1;
	while (!ft_strchr(file, '\n') && readbytes > 0)
	{
		readbytes = read(fd, buff, BUFFER_SIZE);
		if (readbytes == -1)
		{
			free(file);
			free(buff);
			return (0);
		}
		buff[readbytes] = '\0';
		temp = file;
		file = ft_strjoin(temp, buff);
		free(temp);
	}
	free(buff);
	return (file);
}

char	*get_next_line(int fd)
{
	static char	*file[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || FOPEN_MAX < fd)
		return (0);
	if (!file[fd])
		file[fd] = ft_calloc(1, 1);
	file[fd] = ini_file(fd, file[fd]);
	if (!file[fd])
		return (0);
	line = first_line(file[fd]);
	file[fd] = new_file(file[fd]);
	return (line);
}

/*int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	fd1 = open("testes/test.txt", O_RDONLY);
	fd2 = open("testes/test2.txt", O_RDONLY);
	i = 1;
	while (i < 37)
	{
		line = get_next_line(fd1);
		printf("line [%d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	return (0);
}*/
