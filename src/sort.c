#include "../includes/push_swap.h"

static int	ft_find_index(int *i, int *tab, int n, int find)
{
	while (*i < n)
	{
		if (tab[*i] == find)
			return (1);
		(*i)++;
	}
	return (0);
}

void		ft_insertion_sort(t_stacks *stacks)
{
	int		max;
	int		i;

	max = stacks->nb_a;
	while (max)
	{
		i = 0;
		while (ft_find_index(&i, stacks->a, stacks->nb_a, max))
		{
			if (i == stacks->nb_a - 1)
			{
				ft_pb(stacks);
				i = 0;
			}
			else if (i == stacks->nb_a - 2)
			{
				ft_sa(stacks);
				i = 0;
			}
			else if (i >= (stacks->nb_a) / 2)
			{
				ft_ra(stacks);
				i = 0;
			}
			else if (i < (stacks->nb_a) / 2)
			{
				ft_rra(stacks);
				i = 0;
			}
		}
		max--;
	}
}
