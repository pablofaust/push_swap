#include "push_swap.h"

void			ft_sort(t_stacks *stacks, t_op **ops)
{
	if (!(ft_tab_is_sort(stacks->a, stacks->nb_a)))
		ft_insertion_sort(stacks, ops);
}

int				main(int ac, char **av)
{
	t_stacks	stacks;
	t_op		*ops;

	if (ac < 2)
		return (0);
	if (!(stacks.a = malloc(sizeof(int) * ac - 1)))
		return (0);
	if (!(stacks.b = malloc(sizeof(int) * ac - 1)))
		return (0);
	if (!(ft_create_av_stack(ac, stacks.a, av, &stacks.nb_a)))
		return (0);
	stacks.max = ac - 1;
	ft_sort(&stacks, &ops);
	ft_read_stacks(stacks);
	//ft_put_ops(ops);
	return (1);
}
