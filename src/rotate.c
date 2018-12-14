#include "../includes/push_swap.h"

void		ft_ra(t_stacks *stacks, t_op **ops)
{
	int		i;
	int		tmp;
	int		tmp2;

	if (stacks->nb_a < 2)
		return ;
	tmp = stacks->a[0];
	stacks->a[0] = stacks->a[stacks->nb_a - 1];
	i = 1;
	while (i < stacks->nb_a)
	{
		tmp2 = stacks->a[i];
		stacks->a[i] = tmp;
		tmp = tmp2;
		i++;
	}
	ft_add_op(ops, "ra");
}

void		ft_rb(t_stacks *stacks, t_op **ops)
{
	int		i;
	int		tmp;
	int		tmp2;

	if (stacks->nb_b < 2)
		return ;
	tmp = stacks->b[0];
	stacks->b[0] = stacks->b[stacks->nb_b - 1];
	i = 1;
	while (i < stacks->nb_b)
	{
		tmp2 = stacks->b[i];
		stacks->b[i] = tmp;
		tmp = tmp2;
		i++;
	}
	ft_add_op(ops, "rb");
}

void		ft_rr(t_stacks *stacks, t_op **ops)
{
	ft_ra(stacks, ops);
	ft_rb(stacks, ops);
}
