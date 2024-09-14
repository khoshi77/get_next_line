#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*p;
	int		i;

	p = malloc(sizeof (char) * (ft_strlen(s) + 1));
	if (!p)
		return (NULL);
	else
	{
		i = 0;
		while (s[i])
		{
			p[i] = s[i];
			i++;
		}
		p[i] = '\0';
	}
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (free(s1), NULL);
	p = malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (p == NULL)
		return (free(s1), NULL);
	else
	{
		i = -1;
		while (s1[++i])
			p[i] = s1[i];
		j = 0;
		while (s2[j])
			p[i++] = s2[j++];
		p[i] = '\0';
	}
	free(s1);
	return (p);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	if ((char)c == s[i])
		return (1);
	return (0);
}
