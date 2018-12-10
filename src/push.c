#include "../includes/push_swap.h"

void		ft_pa(t_stacks *stacks)
{
	int		*tmp;

	if (stacks->nb_b < 1)
		return ;
	stacks->a[stacks->nb_a] = stacks->b[stacks->nb_b - 1];
	stacks->b[stacks->nb_b - 1] = '\0';
	stacks->nb_a++;
	stacks->nb_b--;
}

void		ft_pb(t_stacks *stacks)
{
	int		*tmp;

	if (stacks->nb_a < 1)
		return ;
	stacks->b[stacks->nb_b] = stacks->a[stacks->nb_a - 1];
	stacks->a[stacks->nb_a - 1] = '\0';
	stacks->nb_b++;
	stacks->nb_a--;
}
