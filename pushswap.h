/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 01:12:37 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/09 01:12:37 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
# include <limits.h>
# include <stdint.h>
// #include "libft/libft.h"


typedef struct s_stack
{
	int				value;
	int index;
	unsigned int rank;
	int chunk;
	struct s_stack	*next;
}	t_stack;

typedef struct s_operation{
	char *op;
	struct s_operation *next;
}	t_operation;

typedef struct s_opcount
{
	int	pa;
	int	pb;
	int	sa;
	int	sb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int total;
}	stack_ops;

typedef struct s_everything
{
	t_stack **a;
	t_stack **b;
	t_operation *ops;
	stack_ops opcount;
}	t_everything;


void	ft_lst_addback(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int value);
int	ft_atoi(const char *str);
void	ft_print_list(t_stack *lst);
int	ft_lstcount(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);



void	selection_sort(t_everything *everyting);
void	assign_ranks(t_stack *s);
void	chunking(t_stack **a, t_stack **b);
void	ft_print_list_with_ranks(t_stack *lst);
void	chunk_based(t_everything *everything);
void	radix_sort(t_everything *everything);
char	**ft_split(char const *s, char *charset);
char	*ft_strjoin(char const *s1, char const *s2);
void	del_stack(t_stack **s);
void	error_handler();
void parser(char **av, t_everything *everything);
size_t	ft_strlen(const char *s);
void del_stack(t_stack **s);
int ft_strcmp(const char *s1, const char *s2);
double count_inversions_of_stack(t_stack** head);
char *adaptive_algo(t_everything *everything);
int is_sorted(t_stack *s);
int ft_bit_count(unsigned int n);
int ft_max_bit_count(t_stack *s);
void	ft_ops_addback(t_operation **lst, t_operation *new);
void del_ops(t_operation **ops);
void del_stack(t_stack **s);
t_operation	*ft_opnew(char* value);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void ft_putstr(char *s, int fd);
void ft_putchar(char c, int fd);
void ft_putnbr(int n);