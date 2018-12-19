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
		ft_rrb(stacks, ops);
		//ft_read_stacks(*stacks);
		(*steps)++;
		r++;
	}
	while (r > 0)
	{
		ft_rb(stacks, ops);
		//ft_read_stacks(*stacks);
		(*steps)++;
		r--;
	}
	while (stacks->nb_b)
	{
		ft_pa(stacks, ops);
		//ft_read_stacks(*stacks);
		(*steps)++;
	}
}

void		ft_first_pushs(t_stacks *stacks, t_op **ops, int *steps)
{
	while (stacks->a[stacks->nb_a - 1] == stacks->max || stacks->a[stacks->nb_a - 2] == stacks->max)
	{
		ft_ra(stacks, ops);
		//ft_read_stacks(*stacks);
		(*steps)++;
	}
	while (stacks->nb_b < 2)
	{
		ft_pb(stacks, ops);
		//ft_read_stacks(*stacks);
		steps++;
	}
}

void		ft_insertion_sort(t_stacks *stacks, t_op **ops)
{
	int		r;
	int		steps;

	r = 0;
	steps = 0;
	ft_read_stacks(*stacks);
	ft_first_pushs(stacks, ops, &steps);
	while (stacks->nb_a > 1)
	{
		/*if (stacks->a[stacks->nb_a - 1] != stacks->nb_a && \
				stacks->a[stacks->nb_a - 1] > stacks->a[stacks->nb_a - 2] && \
				stacks->b[stacks->nb_b - 1] < stacks->b[stacks->nb_b - 2])
		{
			ft_ss(stacks, ops);
			ft_read_stacks(*stacks);
			steps++;
		}*/
		if ((!(ft_is_inferior(stacks) || ft_no_inferior(stacks))) && stacks->a[stacks->nb_a - 1] != stacks->max)
		{
			r = ft_get_rotation(stacks, '<', stacks->a, stacks->nb_a);
			while (r < 0)
			{
				ft_rrb(stacks, ops);
				//ft_read_stacks(*stacks);
				steps++;
				r++;
			}
			while (r > 0)
			{
				ft_rb(stacks, ops);
				//ft_read_stacks(*stacks);
				steps++;
				r--;
			}
		}
		if ((ft_is_inferior(stacks) || ft_no_inferior(stacks)) && stacks->a[stacks->nb_a - 1] != stacks->max)
		{
			steps++;
			ft_pb(stacks, ops);
			//ft_read_stacks(*stacks);
		}		
		if (stacks->a[stacks->nb_a - 1] == stacks->max && stacks->nb_a > 1)
		{
			ft_sa(stacks, ops);
			//ft_read_stacks(*stacks);
			steps++;
		}
		if (stacks->b[stacks->nb_b - 1] < stacks->b[stacks->nb_b - 2] && \
				stacks->b[stacks->nb_b - 1] > stacks->b[0])
		{
			ft_sb(stacks, ops);
			//ft_read_stacks(*stacks);
			steps++;
		}
	}
	ft_pushback(stacks, ops, &steps);
	printf("%d coups !\n", steps);
}
