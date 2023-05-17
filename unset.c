#include "env.h"

static void	unset(t_dict *env, char *key)
{
	t_dict	*node;
	t_dict	*new;
	int		prev;

	node = compare_key(env, key);
	new = env;
	if (new == NULL || node == NULL)
		return ;
	prev = 0;
	while (new)
	{
		if (new == node || new->next == node)
		{
			if (prev == 0)
				env = node->next;
			new->next = node->next;
			del_one(node);
			break ;
		}
		prev = 1;
		new = new->next;
	}
	env->size--;
}

int	unset_builtins(int size, char *str[], t_info *data)
{
    int	i;

    i = 0;
	if (size <= 1)
        return (0);
    while (++i < size)
	{
		if (check_unset(str[i]))
			unset(data->env, str[i]);
	}
    print_list(data->env);
    return (0);
}