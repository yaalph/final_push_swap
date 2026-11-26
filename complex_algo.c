/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 11:43:21 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/26 11:43:22 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_putstr_nl(char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
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
	int size;

	assign_ranks(*everything->a);
	if (is_sorted(*everything->a))
		return ;
	size = ft_lstcount(*everything->a);
	sort_a(size, 1u << (ft_max_bit_count(*everything->a) - 1), everything);
	optimise_ops(everything);
}