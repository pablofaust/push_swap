#include "../includes/push_swap.h"

int				main(int ac, char **av)
{
	t_stacks	stacks;

	if (ac < 2)
		return (0);
	if (!(stacks.a = malloc(sizeof(int) * ac - 1)))
		return (0);
	ft_create_av_stack(stacks.a, av);
	stacks.nb_a = ac - 1;
	ft_read_stacks(stacks);
	ft_sa(stacks);
	ft_read_stacks(stacks);
	return (1);
}
