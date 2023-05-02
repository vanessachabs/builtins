#include "ds.h"

t_node	*new_node(char *key, char *value)
{
	t_node	*ref;

	ref = malloc(sizeof(t_node));
	if (!ref)
		return (NULL);
	ref->key = key;
	ref->value = value;
	ref->next = NULL;
	ref->prev = NULL;
	return (ref);
}

void	empty_list(t_list *lst, t_node *node)
{
	lst->head = node;
	lst->tail = node;
}

void	add_buttom(t_list *lst, t_node *node)
{
	t_node	*last;

	if (node == NULL)
		return ;
	if (lst->head == NULL && lst->tail == NULL)
		empty_list(lst, node);
	else
	{
		last = lst->tail;
		last->next = node;
		node->prev = last;
		lst->tail = node;
		node->next = NULL;
	}
}

void	add_top(t_list *lst, t_node *node)
{
	t_node	*first;

	if (node == NULL)
		return ;
	if (lst->head == NULL && lst->tail == NULL)
		empty_list(lst, node);
	else
	{
		first = lst->head;
		first->prev = node;
		node->next = first;
		lst->head = node;
		node->prev = NULL;
	}
}
