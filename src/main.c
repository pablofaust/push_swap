#include "../includes/push_swap.h"

void			ft_sort(t_stacks *stacks)
{
	if (stacks->nb_a <= 20)
		ft_insertion_sort(stacks);
}

int				main(int ac, char **av)
{
	t_stacks	stacks;

	if (ac < 2)
		return (0);
	if (!(stacks.a = malloc(sizeof(int) * ac - 1)))
		return (0);
	if (!(ft_create_av_stack(ac, stacks.a, av, &stacks.nb_a)))
		return (0);
	if (!(stacks.b = malloc(sizeof(int) * ac - 1)))
		return (0);
	ft_sort(&stacks);
	ft_read_stacks(stacks);
	return (1);
}
