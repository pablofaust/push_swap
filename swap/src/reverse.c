#include "push_swap.h"

void		ft_rra(t_stacks *stacks, t_op **ops)
{
	int		i;
	int		tmp;
	int		tmp2;

	if (stacks->nb_a < 2)
		return ;
	tmp = stacks->a[stacks->nb_a - 1];
	stacks->a[stacks->nb_a - 1] = stacks->a[0];
	i = stacks->nb_a - 2;
	while (i >= 0)
	{
		tmp2 = stacks->a[i];
		stacks->a[i] = tmp;
		tmp = tmp2;
		i--;
	}
	ft_add_op(ops, "rra");
}

void		ft_rrb(t_stacks *stacks, t_op **ops)
{
	int		i;
	int		tmp;
	int		tmp2;

	if (stacks->nb_b < 2)
		return ;
	tmp = stacks->b[stacks->nb_b - 1];
	stacks->b[stacks->nb_b - 1] = stacks->b[0];
	i = stacks->nb_b - 2;
	while (i >= 0)
	{
		tmp2 = stacks->b[i];
		stacks->b[i] = tmp;
		tmp = tmp2;
		i--;
	}
	ft_add_op(ops, "rrb");
}

void		ft_rrr(t_stacks *stacks, t_op **ops)
{
	ft_rra(stacks, ops);
	ft_rrb(stacks, ops);
}
