#include "get_next_line.h"

static char	*ft_read_line(int fd, char **remainder)
{
	ssize_t	bytes_read;
	char	buffer[BUFFER_SIZE + 1];
	char	*newline;
	char	*start;
	char	*line;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read >= 0)
	{
		if (bytes_read)
		{
			buffer[bytes_read] = '\0';
			*remainder = ft_strjoin(*remainder, buffer);
		}
		start = *remainder;
		newline = ft_strchr(*remainder, '\n');
		if (newline)
		{
			*newline = '\0';
			line = malloc(newline - start + 2);
			if (!line)
				return (NULL);
			ft_strncpy(line, start, newline - start);
			line[newline - start] = '\n';
			line[newline - start + 1] = '\0';
			return (line);
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read_line(fd, &remainder);
	if (remainder && remainder[0] != '\0')
	{
		remainder = ft_strdup(remainder + ft_strlen(line));
	}
	else
	{
		free(remainder);
		remainder = NULL;
	}
	return (line);
}
