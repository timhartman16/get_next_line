#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*ft_strchr(char *s, int c)
{ 
	int		i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	if (s && s[i] == c)
		return (&s[i]);
	return (0);
}

static int	ft_zapolnenie(char **line, char **ostatok, char *mesto_n,
							int b_read)
{
	char	*temp;

	if (b_read == -1)
		return (-1);
	if (mesto_n != NULL)
	{
		*line = ft_calloc(1, ((mesto_n - *ostatok) + 1));
		*line = ft_memcpy(*line, *ostatok, (mesto_n - *ostatok));
		temp = ft_calloc(1, (ft_strlen(mesto_n) + 1));
		temp = ft_memcpy(temp, (mesto_n + 1), ft_strlen(mesto_n));
		free(*ostatok);
		*ostatok = temp;
		return (1);
	}
	if (*ostatok != NULL)
	{
		*line = *ostatok;
		*ostatok = NULL;
	}
	else
		*line = ft_calloc(1, 1);
	return (0);
}

char	*ft_ft(char *buffer, char *ostatok, int b_read, char *temp)
{
	if (ostatok == NULL)
	{
		temp = ft_calloc(1, (b_read) + 1);
		temp = ft_memcpy(temp, buffer, b_read);
	}
	else
	{
		temp = ft_strjoin(ostatok, buffer);
		free(ostatok);
	}
	return (temp);
}

int	get_next_line(int fd, char **line)
{
	char			*buffer;
	static char		*ostatok;
	int				b_read;
	char			*mesto_n;
	char			*temp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	mesto_n = ft_strchr(ostatok, '\n');
	while (mesto_n == 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read <= 0)
			break ;
		buffer[b_read] = '\0';
		temp = ft_ft(buffer, ostatok, b_read, temp);
		ostatok = temp;
		mesto_n = ft_strchr(ostatok, '\n');
	}
	free(buffer);
	return (ft_zapolnenie(line, &ostatok, mesto_n, b_read));
}
