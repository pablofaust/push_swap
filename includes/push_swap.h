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

int				ft_create_av_stack(int ac, int *a, char **av, int *nb);
void			ft_read_stacks(t_stacks stacks);
void			ft_sa(t_stacks *stacks);
void			ft_sb(t_stacks *stacks);
void			ft_ss(t_stacks *stacks);
void			ft_pa(t_stacks *stacks);
void			ft_pb(t_stacks *stacks);
void			ft_ra(t_stacks *stacks);
void			ft_rb(t_stacks *stacks);
void			ft_rr(t_stacks *stacks);
void			ft_rra(t_stacks *stacks);
void			ft_rrb(t_stacks *stacks);
void			ft_rrr(t_stacks *stacks);
#endif
