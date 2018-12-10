#include "../includes/push_swap.h"

void			ft_read_stacks(t_stacks stacks)
{
	t_stacks	ptr;
	int			i;

	ptr = stacks;
	if (ptr.a)
	{
		i = ptr.nb_a - 1;
		ft_putstr("STACK a :\n");
		while (i >= 0)
		{
			ft_putnbr(ptr.a[i--]);
			ft_putstr("\n");
		}
	}
	if (ptr.b)
	{
		i = 0;
		ft_putstr("STACK b :\n");
		while (i < ptr.nb_b)
		{
			ft_putnbr(ptr.b[i++]);
			ft_putstr("\n");
		}
	}
}

void		ft_create_av_stack(int *a, char **av)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (av[i])
		a[j++] = ft_atoi(av[i++]);
}
