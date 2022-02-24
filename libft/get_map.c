/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:24:19 by jperales          #+#    #+#             */
/*   Updated: 2022/02/23 13:08:11 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	ft_check(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_join(char	*line, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i])
		i++;
	str = malloc(i + 2);
	i = 0;
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(line);
	return (str);
}

int	ft_checking(int fd, char **line, int *readed)
{
	*readed = 1;
	if (fd < 0)
	{
		*line = NULL;
		return (0);
	}
	*line = malloc(1);
	*line[0] = '\0';
	return (1);
}

char	*get_map(int fd)
{
	char	buffer;
	char	*line;
	int		readed;

	ft_checking(fd, &line, &readed);
	while (!ft_check(line) && readed > 0)
	{
		readed = read(fd, &buffer, 1);
		if (readed == 0)
		{
			if (line[0] == '\0')
			{
				free(line);
				return (NULL);
			}
			return (line);
		}
		if (readed < 0)
		{
			free(line);
			return (NULL);
		}
		line = ft_join(line, buffer);
	}
	return (line);
}
