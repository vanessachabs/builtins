#include "env.h"

static void	write_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}
&& environ[index] != '='

static t_dict  create_env(void)
{
    t_dict   *dict;

    dict = (t_dict *) malloc(sizeof(t_dict));
	if (dict == NULL)
        write_error();
    return (dict);
}

void    add_env(t_dict  *env_aux, char *envi)
{   
    t_dict new_env = create_env();
    if (env_aux == NULL)
    {
        env_aux = new_env;
        new_env->key = NULL;
        new_env->value = NULL;
        new_env->next = NULL;
    }
    else
    {
        new_env->key = get_key();
        new_env->value = get_value();

    }

}
static  t_dict  *dup_envp(char *environ[])
{
    int     index;
    t_dict  *env_aux;

    index = 0;
    env_aux = NULL;
    while(environ[index])
    {
        add_env(env_aux,environ[index]);
    }
    

}

t_info *init_info(char *envp[])
{
    t_info  *info;

    info = (t_info *) malloc(sizeof(t_info));
	if (info == NULL)
		write_error();
    info->output = STDOUT_FILENO;
	info->input = STDIN_FILENO;
    info->env = dup_envp(envp);
    return (info);
}
