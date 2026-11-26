/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_optimizer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 11:43:34 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/26 11:43:35 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	add_opcount(t_everything *everything, char *opr)
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

void	cancel_ops_if_condition(t_everything *everything, t_operation *ops,
		t_operation **new, t_operation **tmp)
{
	*tmp = ops_lstnew(ops->op);
	if (!*tmp)
	{
		while (ops)
		{
			*tmp = ops->next;
			free(ops);
			ops = *tmp;
		}
		while (*new)
		{
			*tmp = (*new)->next;
			free(*new);
			*new = *tmp;
		}
		error_handler(everything->a, everything->b, 0, NULL);
	}
	ops_lst_addback(new, *tmp);
}

void	cancel_ops_else_condition(int *cancelled, t_operation **atmp,
		t_operation **ops)
{
	*cancelled = 1;
	*atmp = (*ops)->next;
	free(*ops);
	*ops = *atmp;
}

t_operation	*cancel_ops(t_operation *ops, t_everything *everything)
{
	t_operation	*new;
	t_operation	*tmp;
	t_operation	*atmp;
	int			cancelled;

	cancelled = 1;
	while (cancelled)
	{
		cancelled = 0;
		new = NULL;
		while (ops && ops->next)
		{
			if (!opposites(ops->op, ops->next->op))
				cancel_ops_if_condition(everything, ops, &new, &tmp);
			else
				cancel_ops_else_condition(&cancelled, &atmp, &ops);
			atmp = ops->next;
			free(ops);
			ops = atmp;
		}
		if (ops)
			ops_lst_addback(&new, ops);
		ops = new;
	}
	return (ops);
}

void	optimise_ops(t_everything *everything)
{
	char *m;
	t_operation *current;

	if (!everything->ops || !everything->ops->next)
		return (optimise_ops_helper(everything));
	everything->ops = cancel_ops(everything->ops, everything);
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