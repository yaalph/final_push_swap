/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_sortb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 11:43:17 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/26 11:43:18 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	top_descending(t_stack *b, int n)
{
	while (--n)
	{
		if (b->rank < b->next->rank)
			return (0);
		b = b->next;
	}
	return (1);
}
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
	int zeroes;
	int ones;
	int all;
	int i;

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