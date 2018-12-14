#include "../includes/push_swap.h"

t_op		*ft_create_op(char *op)
{
	t_op	*tmp;

	if (!(tmp = malloc(sizeof(t_op))))
		return (NULL);
	ft_strcpy(tmp->op, op);
	tmp->next = NULL;
	return (tmp);
}

void		ft_add_op(t_op **ops, char *op)
{
	t_op	*tmp;

	tmp = *ops;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_op(op);
	}
	else
		*ops = ft_create_op(op);
}

void		ft_put_ops(t_op *ops)
{
	while (ops)
	{
		ft_putstr(ops->op);
		ft_putchar('\n');
		ops = ops->next;
	}
}
