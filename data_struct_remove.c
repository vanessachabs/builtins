#include "ds.h"

t_node	*remove_top(t_list *lst)
{
	t_node	*temp;
	t_node	*aux;

	if (lst->head == lst->tail)
	{
		if (lst->head == NULL)
			return (NULL);
		else
		{
			temp = lst->head;
			lst->head = NULL;
			lst->tail = NULL;
		}
	}
	else
	{
		temp = lst->head;
		aux = temp->next;
		lst->head = aux;
		aux->prev = NULL;
		temp->next = NULL;
	}
	return (temp);
}

t_node	*remove_buttom(t_list *lst)
{
	t_node	*temp;
	t_node	*aux;

	if (lst->head == lst->tail)
	{
		if (lst->tail == NULL)
			return (NULL);
		else
		{
			temp = lst->tail;
			lst->head = NULL;
			lst->tail = NULL;
		}
	}
	else
	{
		temp = lst->tail;
		aux = temp->prev;
		lst->tail = aux;
		aux->next = NULL;
		temp->prev = NULL;
	}
	return (temp);
}

void	del_one(t_node *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

void	del_lst(t_list *lst)
{
	t_node	*temp;
	t_node	*aux;

	temp = lst->head;
	while (temp != NULL)
	{
		aux = temp->next;
		del_one(temp);
		temp = aux;
	}
	lst->head = NULL;
	lst->tail = NULL;
}
