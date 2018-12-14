#include "push_swap.h"

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

void		ft_left_hand_sort(t_stacks *stacks, int *steps, t_op **ops)
{
	int	max;
	int	tmp;
	int	i;

	max = 1;
	tmp = stacks->nb_a;
	while (max <= tmp)
	{
		i = 0;
		while (ft_find_index(&i, stacks->a, stacks->nb_a, max))
		{
			if (i == stacks->nb_a - 1)
			{
				ft_pb(stacks, ops);
				i = 0;
				(*steps)++;
			}
			else if (i == stacks->nb_a - 2)
			{
				ft_sa(stacks, ops);
				i = 0;
				(*steps)++;
			}
			else if (i >= (stacks->nb_a) / 2)
			{
				ft_ra(stacks, ops);
				i = 0;
				(*steps)++;
			}
			else if (i < (stacks->nb_a) / 2)
			{
				ft_rra(stacks, ops);
				i = 0;
				(*steps)++;
			}
		}
		max++;
	}
}

void		ft_insertion_sort(t_stacks *stacks, t_op **ops)
{
	int	steps;

	steps = 0;
	ft_left_hand_sort(stacks, &steps, ops);
	printf("%d coups !\n", steps);
	while (stacks->nb_b)
	{
		steps++;
		ft_pa(stacks, ops);
	}
	printf("%d coups !\n", steps);
}
