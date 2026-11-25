/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_instructions1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 01:13:17 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/25 13:10:19 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void reverse_rotate(t_stack **s)
{
    t_stack *last;
    t_stack *prev;

    if (!s || !*s || !(*s)->next)
        return;
    prev = NULL;
    last = *s;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *s;
    *s = last;
}

void rra(t_stack **a)
{
    reverse_rotate(a);
}

void rrb(t_stack **b)
{
    reverse_rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}