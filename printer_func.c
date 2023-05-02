#include "ds.h"

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

int	ft_putstr(char *s)
{
	if (s == NULL)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	print_lst(t_list *ref)
{
	t_node	*temp;

	temp = ref->head;
	ft_putstr("======= ENV_LIST =======\n");
	while (temp != NULL)
	{
		ft_putstr("\033[0;36mKEY:\033[0m ");
		ft_putstr(temp->key);
		ft_putchar('\n');
		ft_putstr("\033[0;32mVALUE:\033[0m ");
		ft_putstr(temp->value);
		ft_putchar('\n');
		ft_putchar('\n');
		temp = temp->next;
	}
}
