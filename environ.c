#include "env.h"

static void	write_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}


/*Alovando memória para o novo nó*/
static t_dict  *create_env(void)
{
    t_dict   *dict;

    dict = (t_dict *) malloc(sizeof(t_dict));
	if (dict == NULL)
        write_error();
    return (dict);
}

/*Adicionando as keys e values no nó*/
static t_dict   *add_env(t_dict  *env_aux, char *key, char *value)
{   
    t_dict *new_env = create_env();
    new_env->key = key;
    new_env->value = value;
    if (env_aux == NULL)
    {
        env_aux = new_env;
        new_env->next = NULL; 
    }
    else
    {
        new_env->next = env_aux;
        env_aux = new_env;
    }
    return (env_aux);
}

/*Fazer uma cópia do envp. Lembrando que as variáveis de ambientes
Tem formato key=value 
Criar new_env aqui e passar como argumento para add_env*/
static  t_dict  *dup_envp(char *environ[])
{
    int     index;
    char    **dict_split;
    t_dict  *env_aux;

    index = 0;
    env_aux = NULL;
    dict_split = NULL;
    while (environ[index])
    {
        dict_split = ft_split(environ[index], '=');
        env_aux = add_env(env_aux, dict_split[0], dict_split[1]);
        dict_split = NULL;
        index++;
    }
    env_aux->size = index;
    return (env_aux);
}

void	print_list(t_dict *env)
{
	t_dict *tmp;

	tmp = env;
	while (tmp)
	{
		if (tmp->value)
		{
			ft_putstr_fd(tmp->key, 1);
			ft_putchar_fd('=', 1);
			ft_putstr_fd(tmp->value, 1);
			ft_putchar_fd('\n', 1);
		}
		tmp = tmp->next;
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
