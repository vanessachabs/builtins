#include "env.h"

static void	write_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

t_dict	*new_env(char *key, char *value, int size)
{
	t_dict	*node;

	node = (t_dict *)malloc(sizeof(t_dict));
	node->key = ft_strdup(key);
	node->value = ft_strtrim(value, "'");
	node->next = NULL;
	node->size = size;
	return (node);
}

t_dict	*add_env(t_dict *env, char *key, char *value)
{
	t_dict	*new;

	new = new_env(key, value, 0);
	if (env == NULL)
		env = new;
	else
	{
		new->next = env;
		env = new;
	}
	return (env);
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
