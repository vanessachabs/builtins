
#include "env.h"

static void	swap_node(t_dict *env, t_dict *next_dict)
{
	char	*key;
	char	*value;

	key = env->key;
	value = env->value;
	env->key = next_dict->key;
	env->value = next_dict->value;
	next_dict->key = key;
	next_dict->value = value;
}

static t_dict	*sort_dict(t_dict *env)
{
	t_dict	*new_node;

	new_node = env;
	while (new_node->next)
	{
		if (ft_strcmp(new_node->key, new_node->next->key) > 0)
		{
			swap_node(new_node, new_node->next);
			new_node = env;
		}
		else
			new_node = new_node->next;
	}
	return (env);
}

static t_dict	*copy_env_list(t_dict *env)
{
	t_dict	*new_node;
	t_dict	*tmp_node;

	new_node = new_env(env->key, env->value, 0);
	tmp_node = new_node;
	env = env->next;
	while (env)
	{
		tmp_node->next = new_env(env->key, env->value, 0);
		tmp_node = tmp_node->next;
		env = env->next;
	}
	return (new_node);
}

void	print_export(t_dict *env)
{
	t_dict	*node;
	t_dict	*tmp;
	t_dict	*env_sorted;

	tmp = copy_env_list(env);
	env_sorted = sort_dict(tmp);
	node = env_sorted;
	while (node)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(node->key , STDOUT_FILENO);
		if (node->value)
		{
			ft_putstr_fd("=\"", STDOUT_FILENO);
			ft_putstr_fd(node->value, STDOUT_FILENO);
			ft_putchar_fd('"', STDOUT_FILENO);
		}
		ft_putchar_fd('\n', STDOUT_FILENO);
		node = node->next;
	}
	free_env(env_sorted);
}
