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
		printf("max = %d\n", max);
		i = 0;
		while (ft_find_index(&i, stacks->a, stacks->nb_a, max))
		{
			ft_read_stacks(*stacks);
			printf("i = %d\n", i);
			if (i == 0)
			{
				printf("PB\n");
				ft_pb(stacks);
				i = 0;
			}
			else if (i == 1)
			{
				printf("SA\n");
				ft_sa(stacks);
				i = 0;
			}
			else if (i <= (stacks->nb_a) / 2)
			{
				printf("RA\n");
				ft_ra(stacks);
				i = 0;
			}
			else if (i > (stacks->nb_a) / 2)
			{
				printf("RRA\n");
				ft_rra(stacks);
				i = 0;
			}
		}
		max--;
	}
}
