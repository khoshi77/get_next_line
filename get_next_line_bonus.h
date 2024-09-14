#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_SIZE
#  define FD_SIZE 1024
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s, int c);
char	*read_some(int fd, char *rem_str);
char	*get_line(char *str, int *i);
char	*get_rem(char *str, int *i, int *flag);
char	*get_next_line(int fd);

#endif
