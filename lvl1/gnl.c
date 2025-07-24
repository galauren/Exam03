#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#if BUFFER_SIZE < 0
# undef BUFFER_SIZE
# define BUFFER_SIZE 0
#endif

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	dest[i] = '\0';
	while (--i >= 0)
	{
		dest[i] = src[i];
	}
	return (dest);
}

char	*gnl(int fd)
{
	static int	buffer_read = 0;
	static int	buffer_pos = 0;
	static char	buffer[BUFFER_SIZE];
	char		line[10000];
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_read == 0)
				break ;
		}
		line[i++] = buffer[buffer_pos++];
		if (line[i - 1] == '\n')
			break ;
	}
	if (i == 0)
		return (NULL);
	line[i] = '\0';
	return (ft_strdup(line));
}
int main()
{
	char	*line;
	int		i = 0;

	line = gnl(0);
	while (line)
	{
		printf("line[%d]%s", i++, line);
		free(line);
		line = gnl(0);
	}
	return (0);
}
