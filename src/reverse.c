#include "../includes/push_swap.h"

void		ft_rra(t_stacks *stacks)
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
}

void		ft_rrb(t_stacks *stacks)
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
}

void		ft_rrr(t_stacks *stacks)
{
	ft_rra(stacks);
	ft_rrb(stacks);
}
