#include "ds.h"

int	find_equal(char	*s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		if (s[count] == '=')
			break;
		count++;
	}
	return (count);
}

t_node	*set_node(char *s)
{
	int		len;
	int		pos;
	t_node	*temp;

	pos = find_equal(s);
	len = ft_strlen(s) - pos - 1;
	temp = new_node(ft_substr(s, 0, pos), ft_substr(s, pos + 1, len));
	return (temp);
}

void	copy_env(t_list *env, char *envp[])
{
	int		i;
	t_node	*aux;

	i = 0;
	while (envp[i] != NULL)
	{
		aux = set_node(envp[i]);
		add_buttom(env, aux);
		i++;
	}
}
