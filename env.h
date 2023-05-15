#ifndef ENV_H
# define ENV_H

/*biblioteca*/
#include "env.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <string.h>
#include <errno.h>

# define ERROR_EXPORT -1
# define SUCESS_EXPORT 1

typedef struct s_token
{
	int				token;
	void			*word;
	struct s_data	*next;
}					t_token;

typedef struct s_dict
{
    char            *key;
    char            *value;
    int             size;
    struct s_dict   *next;
}   t_dict;

typedef struct  s_info
{
    int			output;
	int			input;
    t_dict      *env;
}   t_info;

t_info  *init_info(char *envp[]);
char	**ft_split(char const *s, char c);
void    print_list(t_dict *env);
void	free_array(char **tab);
void	free_env(t_dict *env);
int	    check_export(char *key, char *str);
void	export_error(char *str);
int	    export_builtins(int size, char *str[], t_info *data);
void	print_export(t_dict *env);
t_dict	*new_env(char *key, char *value, int size);

int	    ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
int	    ft_isalpha(int c);
int	    ft_isalnum(int c);
#endif