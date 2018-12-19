#include "push_swap.h"

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
			j = i;
		}
		i++;
	}
	return (j);
}

int			ft_superior_index(t_stacks *stacks, int *stack, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		if (stack[i] == stacks->max - 1)
			return (i);
		i++;
	}
	return (0);
}
