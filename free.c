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


void	free_env(t_dict *env)
{
	t_dict	*node;

	while (env)
	{
		node = env->next;
		free(env->key);
		free(env->value);
		free(env);
		env = node;
	}
}

