#include "push_swap.h"

void		ft_big_sort(t_stacks *stacks, t_op **ops)
{
	int		loops;
	int		i;

	(void)ops;
	loops = (stacks->nb_a % 20) ? stacks->nb_a / 20 + 1 : stacks->nb_a / 20;
	printf("loops = %d\n", loops);
	i = 1;
	while (i <= loops)
	{
		



	}
}
