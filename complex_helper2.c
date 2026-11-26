/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_helper2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 11:43:31 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/26 11:43:32 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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