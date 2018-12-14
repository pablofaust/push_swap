#include "push_swap.h"
#include "get_next_line.h"

int				ft_check_op(char *op)
{
	if (op[0] == '\0')
		return (1);
	if (ft_strcmp("sa", op) != 0 && \
		ft_strcmp("sb", op) != 0 && \
		ft_strcmp("ss", op) != 0 && \
		ft_strcmp("pa", op) != 0 && \
		ft_strcmp("pb", op) != 0 && \
		ft_strcmp("ra", op) != 0 && \
		ft_strcmp("rb", op) != 0 && \
		ft_strcmp("rr", op) != 0 && \
		ft_strcmp("rra", op) != 0 && \
		ft_strcmp("rrb", op) != 0 && \
		ft_strcmp("rrr", op) != 0)
	{
		ft_putstr("Error\n");
		return (-1);
	}
	else
		return (1);
}

void			ft_do_op(t_stacks *stacks, char *op, t_op **ops)
{
	if (ft_strcmp("sa", op) == 0)
		ft_sa(stacks, ops);
	else if (ft_strcmp("sb", op) == 0)
		ft_sb(stacks, ops);
	else if (ft_strcmp("ss", op) == 0)
		ft_ss(stacks, ops);
	else if (ft_strcmp("pa", op) == 0)
		ft_pa(stacks, ops);
	else if (ft_strcmp("pb", op) == 0)
		ft_pb(stacks, ops);
	else if (ft_strcmp("ra", op) == 0)
		ft_ra(stacks, ops);
	else if (ft_strcmp("rb", op) == 0)
		ft_rb(stacks, ops);
	else if (ft_strcmp("rr", op) == 0)
		ft_rr(stacks, ops);
	else if (ft_strcmp("rra", op) == 0)
		ft_rra(stacks, ops);
	else if (ft_strcmp("rrb", op) == 0)
		ft_rrb(stacks, ops);
	else if (ft_strcmp("rrr", op) == 0)
		ft_rrr(stacks, ops);
}

void			ft_stack_is_sort(t_stacks stacks)
{
	int		i;

	if (stacks.nb_b != 0)
	{
		ft_putstr("KO\n");
		return ;
	}
	else
	{
		i = 1;
		while (i < stacks.nb_a)
		{
			if (stacks.a[i - 1] > stacks.a[i])
			{
				ft_putstr("KO\n");
				return ;
			}
			i++;
		}
		ft_putstr("OK\n");
		return ;
	}
}

int				main(int ac, char **av)
{
	t_stacks	stacks;
	char		*op;
	t_op		*ops;

	if (ac < 2)
		return (0);
	if (!(stacks.a = malloc(sizeof(int) * ac - 1)))
		return (0);
	if (!(stacks.b = malloc(sizeof(int) * ac - 1)))
		return (0);
	ft_create_av_stack(ac, stacks.a, av, &stacks.nb_a);
	while (get_next_line(1, &op))
	{
		if (!(ft_check_op(op)))
			return (0);
		ft_do_op(&stacks, op, &ops);
		if (op[0] == '\0')
			break ;
		ft_read_stacks(stacks);
	}
	ft_stack_is_sort(stacks);
	return (1);
}
