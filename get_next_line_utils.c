#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (c > 256)
		c = c - 256;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*out;

	len = ft_strlen((char *)s);
	out = (char *)malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	out = ft_memcpy(out, s, len + 1);
	return (out);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	l1;
	size_t	l2;
	int		i;

	if (!s1)
		return (NULL);
	else
	{
		l1 = ft_strlen(s1);
		l2 = ft_strlen(s2);
		out = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
		if (!out)
			return (NULL);
		i = -1;
		while (s1[++i] != '\0')
			*(out + i) = *(s1 + i);
		i = i - 1;
		while (s2[++i - l1] != '\0')
			*(out + i) = *(s2 + i - l1);
		*(out + i) = '\0';
		return (out);
	}
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*out;
	unsigned int	i;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen((char *)s))
		return (ft_strdup(""));
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	out = (char *)malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		out[i] = *(s + start + i);
		i++;
	}
	out[i] = '\0';
	return (out);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}
