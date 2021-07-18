#include "get_next_line.h"
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*dst1;

	i = 0;
	if (!(dst) && !(src))
		return (0);
	src1 = (unsigned char *)src;
	dst1 = (unsigned char *)dst;
	while (i < n)
	{
		dst1[i] = src1[i];
		i++;
	}
	dst1[i] = '\0';
	return (dst1);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(count * size);
	if (!(str))
		return (0);
	while (i < count * size)
	{
		str[i] = '\0';
		i++;
	}
	return ((void *)str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_dlin(char const *ss)
{
	size_t	len;

	if (ss)
		len = ft_strlen(ss);
	else
		len = 0;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*itog;
	size_t	i;

	i = 0;
	if (!(s1) && !(s2))
		return (0);
	itog = malloc(sizeof(char) * (ft_dlin(s1) + ft_dlin(s2) + 1));
	if (!(itog))
		return (0);
	while (s1 && s1[i])
	{
		itog[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		itog[ft_dlin(s1) + i] = s2[i];
		i++;
	}
	itog[ft_dlin(s1) + i] = '\0';
	return (itog);
}
