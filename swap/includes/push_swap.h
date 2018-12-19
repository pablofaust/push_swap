#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "stdio.h"

typedef struct		s_stacks
{
	int				*a;
	int				*b;
	int				nb_a;
	int				nb_b;
	int				max;
}					t_stacks;

typedef struct		s_op
{
	char			op[2];
	struct s_op		*next;
}					t_op;

int				ft_create_av_stack(int ac, int *a, char **av, int *nb);
void			ft_read_stacks(t_stacks stacks);
void			ft_sa(t_stacks *stacks, t_op **ops);
void			ft_sb(t_stacks *stacks, t_op **ops);
void			ft_ss(t_stacks *stacks, t_op **ops);
void			ft_pa(t_stacks *stacks, t_op **ops);
void			ft_pb(t_stacks *stacks, t_op **ops);
void			ft_ra(t_stacks *stacks, t_op **ops);
void			ft_rb(t_stacks *stacks, t_op **ops);
void			ft_rr(t_stacks *stacks, t_op **ops);
void			ft_rra(t_stacks *stacks, t_op **ops);
void			ft_rrb(t_stacks *stacks, t_op **ops);
void			ft_rrr(t_stacks *stacks, t_op **ops);
void			ft_insertion_sort(t_stacks *stacks, t_op **ops);
void			ft_big_sort(t_stacks *stacks, t_op **ops);
void			ft_add_op(t_op **ops, char *op);
void			ft_put_ops(t_op *ops);
void			ft_read(int *a, int *nb);
void			ft_small_sort(t_stacks *stacks, t_op **ops);
int				ft_is_inferior(t_stacks *stacks);
int				ft_no_inferior(t_stacks *stacks);
int				ft_inferior_index(t_stacks *stacks);
int				ft_inferior_index(t_stacks *stacks);
int				ft_superior_index(t_stacks *stacks, int *stack, int nb);
#endif
