#include "../includes/push_swap.h"

void			ft_read_stacks(t_stacks stacks)
{
	t_stacks	ptr;
	int			i;

	ptr = stacks;
	printf("nb_a = %d, nb_b = %d\n", ptr.nb_a, ptr.nb_b);
	if (ptr.nb_a > 0)
	{
		i = ptr.nb_a - 1;
		ft_putstr("STACK a :\n");
		while (i >= 0)
		{
			ft_putnbr(ptr.a[i--]);
			ft_putstr("\n");
		}
	}
	ft_putstr("\n");
	if (ptr.nb_b > 0)
	{
		i = ptr.nb_b - 1;
		ft_putstr("STACK b :\n");
		while (i >= 0)
		{
			ft_putnbr(ptr.b[i--]);
			ft_putstr("\n");
		}
	}
	ft_putstr("\n");
	ft_putstr("\n");
}

int			ft_has_duplicate(int *a, int nb, int j, int len)
{
	int		i;

	i = len;
	while (i > j)
	{
		if (a[i--] == nb)
			return (1);
	}
	return (0);
}

int			ft_create_av_stack(int ac, int *a, char **av, int *nb)
{
	int		i;
	int		j;

	i = 1;
	j = ac - 2;
	*nb = ac - 1;
	while (av[i])
	{
		a[j] = ft_atoi(av[i]);
		if (ft_has_duplicate(a, a[j], j, *nb))
		{
			ft_putstr("Error\n");
			return (0);
		}
		j--;
		i++;
	}
	return (1);
}
