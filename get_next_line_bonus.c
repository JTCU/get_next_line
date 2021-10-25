#include "get_next_line.h"

void	ft_strdel(char **s, int fd)
{
	if (s != NULL && s[fd] != NULL)
	{
		free(s[fd]);
		s[fd] = NULL;
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_gnl_getline(char **s, int fd)
{
	int		l;
	char	*tmp;
	char	*line;

	l = 0;
	while (s[fd][l] != '\n' && s[fd][l] != '\0')
		l++;
	if (s[fd][l] == '\n')
	{
		line = ft_substr(s[fd], 0, l);
		tmp = ft_strdup((const char *)&s[fd][l + 1]);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(s, fd);
	}
	else
	{
		line = ft_strdup((const char *)s[fd]);
		ft_strdel(s, fd);
	}
	return (line);
}

char	*ft_gnl_output(char **s, int ret, int fd)
{
	if (ret < 0)
		return (NULL);
	if (ret == 0 && s[fd] == NULL)
		return (NULL);
	return (ft_gnl_getline(s, fd));
}

char	*get_next_line(int fd)
{
	int			ret;
	static char	*s[4096];
	char		*tmp;
	char		buff[BUFF_SIZE];

	if (!fd)
		return (NULL);
	ret = read(fd, buff, BUFF_SIZE);
	while (ret > 0)
	{
		buff[ret] = '\0';
		if (!s[fd])
			s[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr((const char *)s[fd], '\n'))
			break ;
		ret = read(fd, buff, BUFF_SIZE);
	}
	return (ft_gnl_output(s, ret, fd));
}
