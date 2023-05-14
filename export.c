#include "env.h"

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

t_dict	*compare_key(t_dict *env, char *key)
{
	t_dict	*node;

	node = env;
	while (node)
	{
		if (ft_strncmp(node->key, key, ft_strlen(key)) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}

static void	append_env(t_dict *env, char *key, char *value, char *str)
{
	while(env->next)
		env = env->next;
	if (value == NULL && ft_strchr(str, '='))
		value = "";
	env->next = new_env(key, value, env->size);
	env->size++;
}

static void	modify_env(t_dict *env, char *value, char *str)
{
	if (value)
	{
		free(env->value);
		env->value = ft_strdup(value);
	}
	else if (ft_strchr(str, '='))
	{
		free(env->value);
		env->value = ft_strdup("");
	}
}

static void	add_export(t_dict *env, char *str)
{
	char	**dict_split;
	t_dict	*new;

	if (!ft_isalpha(str[0]) && str[0] != '_')
	{
		export_error(str);
		return ;
	}
	dict_split = ft_split(str, '=');
	new = compare_key(env, dict_split[0]);
	if (new == NULL && check_export(dict_split[0], str))
		append_env(env, dict_split[0], dict_split[1], str);
	else if (new != NULL)
		modify_env(new, dict_split[1], str);
	free_array(dict_split);
}

/*
 * Input			:int size - amount of arguments
 *					:char **argv - arguments (command export and/or enviroment variable)
 *					:Example: argv[0] = export - argv[1] = students;
 * size=1			:argument 1 (export)
 * size=2			:argument 1 + argument 2 (environment variable)
 * ...
 * Output			:print environment variables in order with 'declare -x'
 * 					:or
 * 					:add a new environment variable (if true)
 */
int	export_builtins(int size, char *str[], t_info *data)
{
	int		i;

	i = 2;
	if (size == 2)
	{
		printf("ÉÉÉ");
		return (0);
	}
   //print_list(data->env);
	while (i < size)
	{
        add_export(data->env, str[i]);
        i++;
    }	
	return (0);
}