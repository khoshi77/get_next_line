#include "get_next_line.h"

char	*read_some(int fd, char *rem_str)
{
	int		len;
	char	*buf;

	len = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_strchr(rem_str, '\n') && len != 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len < 0)
		{
			if (rem_str)
				free(rem_str);
			return (free(buf), NULL);
		}
		if (len == 0)
			break ;
		buf[len] = '\0';
		rem_str = ft_strjoin(rem_str, buf);
		if (!rem_str)
			return (free(buf), NULL);
	}
	free(buf);
	return (rem_str);
}

char	*get_line(char *rem_str, int *i)
{
	int		j;
	char	*line_str;

	if (!rem_str)
		return (NULL);
	if (!rem_str[*i])
		return (free(rem_str), NULL);
	while (rem_str[*i] && rem_str[*i] != '\n')
		(*i)++;
	line_str = malloc((*i) + 2);
	if (!line_str)
		return (free(rem_str), NULL);
	j = 0;
	while (j < *i)
	{
		line_str[j] = rem_str[j];
		j++;
	}
	if (rem_str[*i] == '\n')
		line_str[j++] = '\n';
	line_str[j] = '\0';
	return (line_str);
}

char	*get_rem(char *str, int *i, int *flag)
{
	int		j;
	int		k;
	int		l;
	char	*rem_str;

	k = *i + 1;
	j = 0;
	l = 0;
	if (str[(*i)] == '\0')
		return (free (str), NULL);
	while (str[++(*i)] != '\0')
		j++;
	rem_str = malloc(j + 1);
	if (!rem_str)
	{
		*flag = -1;
		return (free(str), NULL);
	}
	while (str[k])
		rem_str[l++] = str[k++];
	rem_str[l] = '\0';
	free (str);
	return (rem_str);
}

char	*get_next_line(int fd)
{
	static char		*rem_str;
	char			*str;
	int				i;
	int				flag;

	flag = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rem_str = read_some(fd, rem_str);
	if (!rem_str)
		return (NULL);
	i = 0;
	str = get_line(rem_str, &i);
	if (!str)
		return (NULL);
	rem_str = get_rem(rem_str, &i, &flag);
	if (flag == -1)
		return (free (str), NULL);
	return (str);
}

// int	main(){
// 	int fd;
// 	char *p;

//     fd = open("test.txt", O_RDONLY);
// 	//fd = 1;
//     while (1)
//     {
//         p = get_next_line(fd);
// 		if (!p)
// 			break ;
//         printf("output = %s", p);
// 	    free(p);
//     }
// }

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }