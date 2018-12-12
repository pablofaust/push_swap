#include "../includes/push_swap.h"

void		ft_sa(t_stacks *stacks)
{
	int		ptr;

	if (stacks->a)
	{
		if (stacks->nb_a < 2)
			return ;
		ptr = stacks->a[0];	
		stacks->a[0] = stacks->a[1];
		stacks->a[1] = ptr;
	}
}

void		ft_sb(t_stacks *stacks)
{
	int		ptr;

	if (stacks->b)
	{
		if (stacks->nb_b < 2)
			return ;
		ptr = stacks->b[0];	
		stacks->b[0] = stacks->b[1];
		stacks->b[1] = ptr;
	}
}

void		ft_ss(t_stacks *stacks)
{
	ft_sa(stacks);
	ft_sb(stacks);
}
