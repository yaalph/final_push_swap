/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 11:43:06 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/26 11:43:07 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	error_handler(t_stack **a, t_stack **b, int from_split, char **words)
{
	int	i;

	i = 0;
	if (from_split)
	{
		while (words[i])
			free(words[i++]);
		free(words);
	}
	if (a)
		del_stack(a);
	if (b)
		del_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	del_ops(t_operation **ops)
{
	t_operation	*tmp;

	if (!ops)
		return ;
	while (*ops)
	{
		tmp = (*ops)->next;
		free(*ops);
		*ops = tmp;
	}
}

void	del_stack(t_stack **s)
{
	t_stack	*tmp;

	if (!s)
		return ;
	while (*s)
	{
		tmp = (*s)->next;
		free(*s);
		*s = tmp;
	}
}

void	free_words(char **words)
{
	int i;

	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
}