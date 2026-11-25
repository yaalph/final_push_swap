/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 04:22:44 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/25 20:40:38 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


int top_ascending(t_stack *a, int n){
	while(--n){
		if(a->rank > a->next->rank)
			return 0;
		a = a->next;
	}
	return 1;
}

int top_descending(t_stack *b, int n){
	while(--n){
		if(b->rank < b->next->rank)
			return 0;
		b = b->next;
	}
	return 1;
}

void	ops_adding_helper(t_everything *everything, char *opr)
{
	t_operation	*nw;

	nw = ft_opnew(opr);
	if (!nw)
	{
		del_ops(&everything->ops);
		del_stack(everything->a);
		del_stack(everything->b);
		exit(1);
	}
	ft_ops_addback(&everything->ops, nw);
}

void	sort_a(int n, unsigned int mask, t_everything *everything);


void	sort_b_base_cases(t_everything *everything, int n)
{
	if (n <= 0)
		return ;
	if (n == 2 && (*everything->b)->rank < ((*everything->b)->next)->rank)
	{
		sb(everything->b);
		ops_adding_helper(everything, "sb");
	}
	while (n--)
	{
		pa(everything->a, everything->b);
		ops_adding_helper(everything, "pa");
	}
}

void	sort_b_loop(t_everything *everything, unsigned int mask, int *zeroes,
		int *ones)
{
	if ((*everything->b)->rank & mask)
	{
		pa(everything->a, everything->b);
		ops_adding_helper(everything, "pa");
		(*ones)++;
	}
	else
	{
		rb(everything->b);
		ops_adding_helper(everything, "rb");
		(*zeroes)++;
	}
}

void	sort_b(int n, unsigned int mask, t_everything *everything)
{
	int	zeroes;
	int	ones;
	int	all;
	int	i;

	zeroes = 0;
	ones = 0;
	all = 0;
	if (n <= 2 || top_descending(*(everything->b), n))
		return (sort_b_base_cases(everything, n));
	if (n == ft_lstcount(*everything->b))
		all = 1;
	while (n--)
		sort_b_loop(everything, mask, &zeroes, &ones);
	i = 0;
	while (!all && i++ < zeroes)
	{
		rrb(everything->b);
		ops_adding_helper(everything, "rrb");
	}
	sort_a(ones, mask >> 1, everything);
	sort_b(zeroes, mask >> 1, everything);
}

void	sort_a_loop(t_everything *everything, unsigned int mask, int *zeroes,
		int *ones)
{
	if (!((*everything->a)->rank & mask))
	{
		pb(everything->a, everything->b);
		ops_adding_helper(everything, "pb");
		(*zeroes)++;
	}
	else
	{
		ra(everything->a);
		ops_adding_helper(everything, "ra");
		(*ones)++;
	}
}

void	sort_a_base_cases(t_everything *everything, int n)
{
	if (n <= 1)
		return ;
	if (n == 2)
	{
		if ((*everything->a)->rank > ((*everything->a)->next)->rank)
		{
			sa(everything->a);
			ops_adding_helper(everything, "sa");
		}
		return ;
	}
}

void	sort_a(int n, unsigned int mask, t_everything *everything)
{
	int	zeroes;
	int	ones;
	int	all;
	int	i;

	zeroes = 0;
	ones = 0;
	all = 0;
	if (n <= 2 || top_ascending(*(everything->a), n))
		return (sort_a_base_cases(everything, n));
	if (n == ft_lstcount(*everything->a))
		all = 1;
	while (n--)
		sort_a_loop(everything, mask, &zeroes, &ones);
	i = 0;
	while (!all && i++ < ones)
	{
		rra(everything->a);
		ops_adding_helper(everything, "rra");
	}
	sort_a(ones, mask >> 1, everything);
	sort_b(zeroes, mask >> 1, everything);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char	*merge(char *x, char *y)
{
	if ((!ft_strcmp(x, "sa") && !ft_strcmp(y, "sb")) || (!ft_strcmp(x, "sb")
			&& !ft_strcmp(y, "sa")))
		return ("ss");
	if ((!ft_strcmp(x, "ra") && !ft_strcmp(y, "rb")) || (!ft_strcmp(x, "rb")
			&& !ft_strcmp(y, "ra")))
		return ("rr");
	if ((!ft_strcmp(x, "rra") && !ft_strcmp(y, "rrb")) || (!ft_strcmp(x, "rrb")
			&& !ft_strcmp(y, "rra")))
		return ("rrr");
	return (NULL);
}


void add_opcount(t_everything *everything, char *opr)
{
    if (ft_strncmp(opr, "pa", 3) == 0)
        (everything->opcount).pa++;
    else if (ft_strncmp(opr, "pb", 3) == 0)
        (everything->opcount).pb++;
    else if (ft_strncmp(opr, "sa", 3) == 0)
        (everything->opcount).sa++;
    else if (ft_strncmp(opr, "sb", 3) == 0)
        (everything->opcount).sb++;
    else if (ft_strncmp(opr, "ss", 3) == 0)
        (everything->opcount).ss++;
    else if (ft_strncmp(opr, "ra", 3) == 0)
        (everything->opcount).ra++;
    else if (ft_strncmp(opr, "rb", 3) == 0)
        (everything->opcount).rb++;
    else if (ft_strncmp(opr, "rr", 3) == 0)
        (everything->opcount).rr++;
    else if (ft_strncmp(opr, "rra", 4) == 0)
        (everything->opcount).rra++;
    else if (ft_strncmp(opr, "rrb", 4) == 0)
        (everything->opcount).rrb++;
    else if (ft_strncmp(opr, "rrr", 4) == 0)
        (everything->opcount).rrr++;
    else
        return ;
    (everything->opcount).total++;
}

void ft_putstr_nl(char *s){
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

void optimise_ops_helper(t_everything *everything){
	if (!everything->ops)
		return ;
	if (!everything->ops->next)
	{
		ft_putstr_nl(everything->ops->op);
        add_opcount(everything, everything->ops->op);
		return ;
	}
}



// int	pair(char *x, char *y, char *p, char *q)
// {
// 	return ((!ft_strcmp(x, p) && !ft_strcmp(y, q))
// 		|| (!ft_strcmp(x, q) && !ft_strcmp(y, p)));
// }

// int	opposites(char *x, char *y)
// {
// 	return (pair(x, y, "pa", "pb") || pair(x, y, "ra", "rra")
// 		|| pair(x, y, "rb", "rrb") || (!ft_strcmp(x, "sa")
// 			&& !ft_strcmp(y, "sa")) || (!ft_strcmp(x, "sb")
// 			&& !ft_strcmp(y, "sb")));
// }
// void	ops_lst_addback(t_operation **lst, t_operation *new)
// {
// 	t_operation	*tmp;

// 	if (!lst || !new)
// 		return ;
// 	if (!*lst)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	tmp = *lst;
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	tmp->next = new;
// }


// t_operation	*ops_lstnew(char *op)
// {
// 	t_operation	*new;

// 	new = malloc(sizeof(t_operation));
// 	if (!new)
// 		return (NULL);
// 	new->op = op;
// 	new->next = NULL;
// 	return (new);
// }

// t_operation *cancel_ops(t_operation *ops){
// 	t_operation *new;
// 	new = NULL;
// 	t_operation *tmp;
// 	t_operation *atmp;
// 	while(ops && ops->next){
// 		if(!opposites(ops->op, ops->next->op)){
// 			tmp = ops_lstnew(ops->op);
// 			ops_lst_addback(&new, tmp);
// 			atmp = ops->next;
// 			free(ops);
// 		}
// 	}
// }



void	optimise_ops(t_everything *everything)
{
	char	*m;
	t_operation	*current;

	if (!everything->ops || !everything->ops->next)
		return optimise_ops_helper(everything);



	

		
	current = everything->ops;
	while (current)
	{
		m = NULL;
		if (current->next)
			m = merge(current->op, current->next->op);
		if (m)
		{
			ft_putstr_nl(m);
			add_opcount(everything, m);
			current = current->next->next;
		}
		else
		{
			ft_putstr_nl(current->op);
			add_opcount(everything, current->op);
			current = current->next;
		}
	}
}

void	assign_ranks(t_stack *s)
{
	t_stack	*i;
	int		r;
	t_stack	*j;

	i = s;
	while (i)
	{
		j = s;
		r = 0;
		while (j)
		{
			if (j->value < i->value)
				r++;
			j = j->next;
		}
		i->rank = r;
		i = i->next;
	}
}


void	radix_sort(t_everything *everything)
{
	int	size;

	assign_ranks(*everything->a);
	if (is_sorted(*everything->a))
		return ;
	size = ft_lstcount(*everything->a);
	sort_a(size, 1u << (ft_max_bit_count(*everything->a) - 1), everything);
	optimise_ops(everything);
}
