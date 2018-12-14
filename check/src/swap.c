#include "push_swap.h"

void		ft_sa(t_stacks *stacks, t_op **ops)
{
	int		ptr;

	if (stacks->a)
	{
		if (stacks->nb_a < 2)
			return ;
		ptr = stacks->a[stacks->nb_a - 1];	
		stacks->a[stacks->nb_a - 1] = stacks->a[stacks->nb_a - 2];
		stacks->a[stacks->nb_a - 2] = ptr;
	}
	ft_add_op(ops, "sa");
}

void		ft_sb(t_stacks *stacks, t_op **ops)
{
	int		ptr;

	if (stacks->b)
	{
		if (stacks->nb_b < 2)
			return ;
		ptr = stacks->b[stacks->nb_b - 1];	
		stacks->b[stacks->nb_b - 1] = stacks->b[stacks->nb_b - 2];
		stacks->b[stacks->nb_b - 2] = ptr;
	}
	ft_add_op(ops, "sb");
}

void		ft_ss(t_stacks *stacks, t_op **ops)
{
	ft_sa(stacks, ops);
	ft_sb(stacks, ops);
}
