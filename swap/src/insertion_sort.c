#include "push_swap.h"

int		ft_is_sort(int *tab, int nb)
{
	int	i;

	i = 0;
	while (i + 1 < nb)
	{
		if (tab[i + 1] > tab[i])
			return (0);
		i++;
	}
	return (1);
}

int			ft_is_inferior(t_stacks *stacks)
{
	int		i;

	if (stacks->b[stacks->nb_b - 1] > stacks->a[stacks->nb_a - 1])
		return (0);
	i = 0;
	while (i < stacks->nb_b)
	{
		if (stacks->b[i] < stacks->a[stacks->nb_a - 1] && stacks->b[i] > stacks->b[stacks->nb_b - 1])
			return (0);
		i++;
	}
	return (1);
}

int			ft_no_inferior(t_stacks *stacks)
{
	int		i;

	i = 0;
	while (i < stacks->nb_b)
	{
		if (stacks->b[i] < stacks->a[stacks->nb_a - 1])
			return (0);
		i++;
	}
	i = 1;
	while (i < stacks->nb_b)
	{
		if (stacks->b[i] < stacks->b[0])
			return (0);
		i++;
	}
	return (1);
}

int			ft_inferior_index(t_stacks *stacks)
{
	int		tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = 0;
	while (i < stacks->nb_b)
	{
		if (stacks->b[i] < stacks->a[stacks->nb_a - 1] && stacks->b[i] > tmp)
		{ 
			tmp = stacks->b[i];
			printf("tmp = %d\n", tmp);
			j = i;
		}
		i++;
	}
	return (j);
}

int			ft_get_rotation(t_stacks *stacks)
{
	int		index;

	index = ft_inferior_index(stacks);
	printf("index = %d\n", index);
	if (index < stacks->nb_b / 2)
		return (-index - 1);
	else
		return (stacks->nb_b - index - 1);
}

void		ft_insertion_sort(t_stacks *stacks, t_op **ops)
{
	int		r;
	int		steps;

	r = 0;
	steps = 0;
	while (stacks->nb_b < 2)
	{
		printf("PB\n");
		ft_pb(stacks, ops);
		ft_read_stacks(*stacks);
		steps++;
	}
	if (stacks->b[1] < stacks->b[0])
	{
		printf("SB\n");
		ft_sb(stacks, ops);
		ft_read_stacks(*stacks);
		steps++;
	}
	while (stacks->nb_a > 1)
	{
		ft_read_stacks(*stacks);
		if (stacks->a[stacks->nb_a - 1] != stacks->nb_a && \
				stacks->a[stacks->nb_a - 1] > stacks->a[stacks->nb_a - 2] && \
				stacks->b[stacks->nb_b - 1] < stacks->b[stacks->nb_b - 2])
		{
			printf("SS\n");
			ft_ss(stacks, ops);
			ft_read_stacks(*stacks);
			steps++;
		}
		else if (stacks->b[stacks->nb_b - 1] < stacks->b[stacks->nb_b - 2] && \
				stacks->b[stacks->nb_b - 1] > stacks->b[0])
		{
			printf("SB\n");
			ft_sb(stacks, ops);
			ft_read_stacks(*stacks);
			steps++;
		}
		if (!(ft_is_inferior(stacks) || ft_no_inferior(stacks)))
		{
			r = ft_get_rotation(stacks);
			printf("r = %d\n", r);
			while (r < 0)
			{
				ft_rrb(stacks, ops);
				ft_read_stacks(*stacks);
				steps++;
				r++;
			}
			while (r > 0)
			{
				ft_rb(stacks, ops);
				ft_read_stacks(*stacks);
				steps++;
				r--;
			}
		}
		else
		{
			printf("PB\n");
			steps++;
			ft_pb(stacks, ops);
		}
	}
	printf("%d coups !\n", steps);
}
