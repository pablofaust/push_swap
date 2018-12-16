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

int		ft_is_sort(int *tab, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void		ft_small_sort(t_stacks *stacks, t_op **ops)
{
	int 	steps;

	(void)ops;
	steps = 0;
	while (!(ft_is_sort(stacks->a, stacks->nb_a)))
	{
		ft_read(stacks->a, &stacks->nb_a);
		if (stacks->a[stacks->nb_a - 1] > stacks->a[0])
		{
			printf("rra\n");
			ft_rra(stacks, ops);
		}
		else if (stacks->a[0] > stacks->a[1])
		{
			printf("sa\n");
			ft_sa(stacks, ops);
		}
		else
		{
			printf("ra\n");
			ft_ra(stacks, ops);
		}
	}
	ft_putstr("sorted\n");
}
