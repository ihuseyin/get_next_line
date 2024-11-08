#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

size_t  ft_strlen(const char *str);
char  *ft_strncpy(char *dst, const char *src, size_t n);
char  *ft_strchr(const char *s, int c);
char  *ft_strdup(const char *s);
char  *ft_strjoin(char *s1, const char *s2);
char  *get_next_line(int fd);

#endif
