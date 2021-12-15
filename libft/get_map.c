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

char	*ft_join(char	*line, char	c)
{
	int	i;
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

char	*get_map(int	fd)
{
	char	buffer;
	char	*line;
	int	readed;

	if (fd < 0)
		return(NULL);
	line = malloc(1);
	line[0] = '\0';
	readed = 1;
	while (!ft_check(line) && readed > 0)
	{
		readed = read(fd, &buffer,1);
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
