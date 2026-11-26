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


char *adaptive_algo(t_everything *everything);
void	ft_lst_addback(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int value);
int	ft_lstcount(t_stack *lst); // is it used?
int	is_duplicate(t_stack *a, int n);
int	parse_digits(char *s, int i, int sign, int *out);
int	parse_int(char *s, int *out);
void	validate_split_words(char **words, t_stack **a, t_stack **b);
void	error_handler(t_stack **a, t_stack **b, int from_split, char **words);
void del_ops(t_operation **ops);
void del_stack(t_stack **s);
void	free_words(char **words);
void	ops_lst_addback(t_operation **lst, t_operation *new);
t_operation	*ops_lstnew(char *op);
void	optimise_ops_helper(t_everything *everything);
int	pair(char *x, char *y, char *p, char *q);
int opposites(char *x, char *y);
int	top_ascending(t_stack *a, int n);
void	sort_a_base_cases(t_everything *everything, int n);
void	sort_a_loop(t_everything *everything, unsigned int mask, int *zeroes,
		int *ones);
void	sort_a(int n, unsigned int mask, t_everything *everything);
int	top_descending(t_stack *b, int n);
void	sort_b_base_cases(t_everything *everything, int n);
void	sort_b_loop(t_everything *everything, unsigned int mask, int *zeroes,
		int *ones);
void	sort_b(int n, unsigned int mask, t_everything *everything);
void	ft_putstr_nl(char *s);
void	assign_ranks(t_stack *s);
void	radix_sort(t_everything *everything);
int is_sorted(t_stack *s);
int ft_bit_count(unsigned int n);
int ft_max_bit_count(t_stack *s);
void	ft_ops_addback(t_operation **lst, t_operation *new);
t_operation	*ft_opnew(char* value);
void	ops_adding_helper(t_everything *everything, char *opr);
int	ft_strcmp(const char *s1, const char *s2);
char	*merge(char *x, char *y);
void	add_opcount(t_everything *everything, char *opr);
void	cancel_ops_if_condition(t_everything *everything, t_operation *ops,
		t_operation **new, t_operation **tmp);
void	cancel_ops_else_condition(int *cancelled, t_operation **atmp,
		t_operation **ops);
t_operation	*cancel_ops(t_operation *ops, t_everything *everything);
void	optimise_ops(t_everything *everything);
double count_inversions_of_stack(t_stack** head);
void	print_ops(stack_ops opcount);
void	bench_stats(double disorder, char *strategy, stack_ops opcount,
		char *adp_what);
char	*parse_flags_helper(char **av, t_everything *everything, int *i_comp,
		double disorder);
void	parse_flags_body(t_everything *everything, int flags, char **av,
		int i_comp);
void	parse_flags(char **av, t_everything *everything);
char	**ft_split(char const *s, char *charset);
size_t	count_words(char const *s, char *charset, size_t end);
void chunk_based(t_everything *everything);
void	ft_putnbr(int n);
void	ft_putchar(char c, int fd);
void	print_strategy(char *s, char *adp_what);
void	first_upper(char *s);
void	print_double(double n);
int	ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr(char *s, int fd);
void	parser(char **av, t_everything *everything);
void selection_sort(t_everything *everything);
int	ft_issep(char *charset, char c);