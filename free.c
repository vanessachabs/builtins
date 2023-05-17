#include "env.h"

void	free_array(char **tab)
{
	size_t	i;
	char *s;

	i = 0;
	while (tab[i])
	{
		s = tab[i];
		free(s);
		i++;
	}
	free(tab);
	tab = NULL;
}

void	del_one(t_dict *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

void	del_lst(t_dict *env)
{
	t_dict	*node;

	while (env)
	{
		node = env->next;
		del_one(env);
		env = node;
	}
}
