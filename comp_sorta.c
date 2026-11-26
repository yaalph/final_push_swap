/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_sorta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 11:43:13 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/26 11:43:14 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	top_ascending(t_stack *a, int n)
{
	while (--n)
	{
		if (a->rank > a->next->rank)
			return (0);
		a = a->next;
	}
	return (1);
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

void	sort_a(int n, unsigned int mask, t_everything *everything)
{
	int zeroes;
	int ones;
	int all;
	int i;

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