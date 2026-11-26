/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_helper1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 20:01:28 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/26 11:43:26 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted(t_stack *s)
{
	if (!s)
		return (1);
	while (s->next)
	{
		if ((s->next)->rank < s->rank)
			return (0);
		s = s->next;
	}
	return (1);
}

int	ft_bit_count(unsigned int n)
{
	int	count;

	count = 0;
	while (n)
	{
		n >>= 1;
		count++;
	}
	return (count);
}

int	ft_max_bit_count(t_stack *s)
{
	int	max;
	int	bit_count;

	max = 0;
	while (s)
	{
		bit_count = ft_bit_count(s->rank);
		if (bit_count > max)
			max = bit_count;
		s = s->next;
	}
	return (max);
}

void	ft_ops_addback(t_operation **lst, t_operation *new)
{
	t_operation	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_operation	*ft_opnew(char *value)
{
	t_operation *new;

	new = malloc(sizeof(t_operation));
	if (!new)
		return (NULL);
	new->op = value;
	new->next = NULL;
	return (new);
}