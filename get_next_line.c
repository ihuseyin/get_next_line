#include "get_next_line.h"

static char	*ft_read_line(char **remainder)
{
	char	*newline;
	char	*start;
	char	*line;

	if (!*remainder)
		return (NULL);
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
	return (NULL);
}

static void	ft_read_remainder(int fd, char **remainder)
{
	ssize_t	bytes_read;
	char	buffer[BUFFER_SIZE + 1];

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		*remainder = ft_strjoin(*remainder, buffer);
	}
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		*new_remainder;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read_remainder(fd, &remainder);
	line = ft_read_line(&remainder);
	if (line == NULL && remainder)
	{
		line = ft_strdup(remainder);
		free(remainder);
		remainder = NULL;
	}
	else if (remainder && remainder[0] != '\0')
	{
		new_remainder = ft_strdup(remainder + ft_strlen(line));
		free(remainder);
		remainder = new_remainder;
	}
	return (line);
}
