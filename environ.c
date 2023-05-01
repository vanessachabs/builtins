#include "env.h"

static void	write_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}
&& environ[index] != '='

/*Alovando memória para o novo nó*/
static t_dict  create_env(void)
{
    t_dict   *dict;

    dict = (t_dict *) malloc(sizeof(t_dict));
	if (dict == NULL)
        write_error();
    return (dict);
}

/*Adicionando as keys e values no nó*/
void    add_env(t_dict  *env_aux, char *key, char *value)
{   
    t_dict new_env = create_env();
    new_env->key = key;
    new_env->value = value;
    if (env_aux == NULL)
    {
        
        new_env->next = NULL;
        env_aux = new_env;
    }
    else
    {
        new_env->key = get_key(envi);
        if (new_env->key == NULL)
            return (NULL);
        new_env->value = get_value(envi);
        if (new_env->value == NULL)
            return (NULL);
        new_env->next = env_aux;
        env_aux = new_env
    }

/*Fazer uma cópia do envp. Lembrando que as variáveis de ambientes
Tem formato key=value*/
static  t_dict  *dup_envp(char *environ[])
{
    int     index;
    char    **dict_split;
    t_dict  *env_aux;

    index = 0;
    env_aux = NULL;
    while (environ[index])
    {
        dict_split = ft_split(environ[index], '=');
        add_env(env_aux, dict_split[0], dict_split[1]);
        index++;
    }
    return (env_aux)   
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
