/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_opt_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 11:43:10 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/26 11:43:11 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ops_lst_addback(t_operation **lst, t_operation *new)
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

t_operation	*ops_lstnew(char *op)
{
	t_operation	*new;

	new = malloc(sizeof(t_operation));
	if (!new)
		return (NULL);
	new->op = op;
	new->next = NULL;
	return (new);
}

void	optimise_ops_helper(t_everything *everything)
{
	if (!everything->ops)
		return ;
	if (!everything->ops->next)
	{
		ft_putstr_nl(everything->ops->op);
		add_opcount(everything, everything->ops->op);
		return ;
	}
}

int	pair(char *x, char *y, char *p, char *q)
{
	return ((!ft_strcmp(x, p) && !ft_strcmp(y, q)) || (!ft_strcmp(x, q)
			&& !ft_strcmp(y, p)));
}

int	opposites(char *x, char *y)
{
	return (pair(x, y, "pa", "pb") || pair(x, y, "ra", "rra") || pair(x, y,
			"rb", "rrb") || pair(x, y, "ss", "ss") || pair(x, y, "rr", "rrr")
		|| (!ft_strcmp(x, "sa") && !ft_strcmp(y, "sa")) || (!ft_strcmp(x, "sb")
			&& !ft_strcmp(y, "sb")));
}