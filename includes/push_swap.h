#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libs/libft/includes/libft.h"
# include "stdio.h"

typedef struct		s_stacks
{
	int				*a;
	int				*b;
	int				nb_a;
	int				nb_b;
}					t_stacks;

void			ft_create_av_stack(int *a, char **av);
void			ft_read_stacks(t_stacks stacks);
void			ft_sa(t_stacks stacks);
#endif
