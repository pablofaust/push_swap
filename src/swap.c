#include "../includes/push_swap.h"

void		ft_sa(t_stacks stacks)
{
	int		ptr;

	if (stacks.a)
	{
		if (stacks.nb_a < 2)
			return ;
		ptr = stacks.a[stacks.nb_a - 1];	
		stacks.a[stacks.nb_a - 1] = stacks.a[stacks.nb_a - 2];
		stacks.a[stacks.nb_a - 2] = ptr;
	}
}
