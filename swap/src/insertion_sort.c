#include "push_swap.h"

int			ft_get_rotation(t_stacks *stacks, char c, int *stack, int nb)
{
	int		index;

	index = 0;
	if (c == '<')
		index = ft_inferior_index(stacks);
	else if (c == '>')
		index = ft_superior_index(stacks, stack, nb);
	if (index < stacks->nb_b / 2)
		return (-index - 1);
	else
		return (stacks->nb_b - index - 1);
}

void		ft_pushback(t_stacks *stacks, t_op **ops, int *steps)
{
	int		r;

	r = ft_get_rotation(stacks, '>', stacks->b, stacks->nb_b);
	while (r < 0)
	{
		printf("RRB\n");
		ft_rrb(stacks, ops);
		ft_read_stacks(*stacks);
		(*steps)++;
		r++;
	}
	while (r > 0)
	{
		printf("RB\n");
		ft_rb(stacks, ops);
		ft_read_stacks(*stacks);
		(*steps)++;
		r--;
	}
	while (stacks->nb_b)
	{
		printf("PA\n");
		ft_pa(stacks, ops);
		ft_read_stacks(*stacks);
		(*steps)++;
	}
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
		if (stacks->a[stacks->nb_a - 1] != stacks->nb_a && \
				stacks->a[stacks->nb_a - 1] > stacks->a[stacks->nb_a - 2] && \
				stacks->b[stacks->nb_b - 1] < stacks->b[stacks->nb_b - 2])
		{
			printf("SS\n");
			ft_ss(stacks, ops);
			ft_read_stacks(*stacks);
			steps++;
		}
		if (stacks->a[stacks->nb_a - 1] == stacks->max)
		{
			printf("a = %d\n", stacks->a[stacks->nb_a - 1]);
			printf("SA\n");
			ft_sa(stacks, ops);
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
			r = ft_get_rotation(stacks, '<', stacks->a, stacks->nb_a);
			printf("r = %d\n", r);
			while (r < 0)
			{
				printf("RRB\n");
				ft_rrb(stacks, ops);
				ft_read_stacks(*stacks);
				steps++;
				r++;
			}
			while (r > 0)
			{
				printf("RB\n");
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
			ft_read_stacks(*stacks);
		}
	}
	ft_pushback(stacks, ops, &steps);
	printf("%d coups !\n", steps);
}
