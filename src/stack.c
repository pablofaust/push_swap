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

static void	ft_find_big(int *a, int *i, int nb)
{
	int		big;
	int		j;

	j = 0;
	big = 0;
	while (j < nb)
	{
		if (a[j] > big)
		{
			big = a[j];
			*i = j;
		}
		j++;
	}
}

void		ft_read(int *a, int *nb)
{
	int		j;

	j = 0;
	while (j < *nb)
	{
		printf("a[%d] = %d\n", j, a[j]);
		j++;
	}
	printf("\n\n");
}

void		ft_tabcpy(int *cpy, int *tab, int *nb)
{
	int		j;

	j = 0;
	while (j < *nb)
	{
		cpy[j] = tab[j];
		j++;
	}
}

static int	ft_index_stack(int *a, int big, int *nb)
{
	int		*tmp;
	int		nb_tmp;
	int		i;
	int		j;
	int		index;

	if (!(tmp = malloc(sizeof(int) * *nb)))
		return (0);
	ft_tabcpy(tmp, a, nb);
	nb_tmp = *nb;
	j = 0;
	index = *nb;
	while (j < *nb)
	{
		ft_find_big(tmp, &i, nb_tmp);
		a[i] = index;
		tmp[i] = '\0';
		j++;
		index--;
	}
	free(tmp);
	return (1);
}

int			ft_create_av_stack(int ac, int *a, char **av, int *nb)
{
	int		i;
	int		j;
	int		big;

	i = 1;
	*nb = ac - 1;
	j = *nb - 1;
	big = 0;
	while (av[i])
	{
		a[j] = ft_atoi(av[i]);
		if (ft_has_duplicate(a, a[j], j, *nb))
		{
			ft_putstr("Error\n");
			return (0);
		}
		if (a[j] > big)
			big = a[j];
		j--;
		i++;
	}
	if (!(ft_index_stack(a, big, nb)))
		return (0);
	return (1);
}
