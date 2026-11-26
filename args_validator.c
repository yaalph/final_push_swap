/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 11:42:58 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/26 11:43:03 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_duplicate(t_stack *a, int n)
{
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}
int	parse_digits(char *s, int i, int sign, int *out)
{
	int	n;

	n = 0;
	while (s[i] == '0')
		i++;
	while (ft_isdigit(s[i]))
	{
		if (n < INT_MIN / 10 || (n == INT_MIN / 10 && s[i] - '0' > 8))
			return (0);
		n = n * 10 - (s[i++] - '0');
	}
	if (s[i])
		return (0);
	if (sign == 1 && n == INT_MIN)
		return (0);
	if (sign == 1)
		n *= -1;
	*out = n;
	return (1);
}

int	parse_int(char *s, int *out)
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(s[i]))
		return (0);
	return (parse_digits(s, i, sign, out));
}

void	validate_split_words(char **words, t_stack **a, t_stack **b)
{
	int n;
	int j;
	t_stack *new;

	n = 0;
	j = 0;
	while (words[j])
	{
		if (!parse_int(words[j], &n))
			error_handler(a, b, 1, words);
		if (a && *a && is_duplicate(*a, n))
			error_handler(a, b, 1, words);
		new = ft_lstnew(n);
		if (!new)
			error_handler(a, b, 1, words);
		ft_lst_addback(a, new);
		j++;
	}
}