#include "../includes/push_swap.h"

static void	ft_find_biggest(int *i, int *tab, int n, int max)
{
	printf("max = %d\n", max);
	while (tab[*i] != max)
		(*i)++;
}

void		ft_insertion_sort(t_stacks *stacks)
{
	int		i;
	int		max;	

	i = 0;
	max = stacks->nb_a;
	while (stacks->nb_a > 1)
	{
		ft_read(stacks->a, &stacks->nb_a);
		ft_find_biggest(&i, stacks->a, stacks->nb_a, max);
		printf("i = %d\n", i);
		if (i == 0)
		{
			ft_pb(stacks);
			max--;
		}
		else if (i == 1)
		{
			printf("SA\n");	
			ft_sa(stacks);
		}
		else if (i <= (stacks->nb_a - 1) / 2)
			ft_ra(stacks);
		else if (i > (stacks->nb_a - 1) / 2)
			ft_rra(stacks);
	}
}
