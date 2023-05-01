/*biblioteca*/
#include "env.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <string.h>

# define KEY 0
# define VALUE 1

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
    struct s_dict   *next;
}   t_dict;

typedef struct  s_info
{
    int			output;
	int			input;
    t_dict      *env;
}   t_info;