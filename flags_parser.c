/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 11:43:41 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/26 11:43:42 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_ops(stack_ops opcount)
{
	ft_putnbr(opcount.total);
	ft_putchar('\n', 2);
	ft_putstr("[bench] sa: ", 2);
	ft_putnbr(opcount.sa);
	ft_putstr(" sb: ", 2);
	ft_putnbr(opcount.sb);
	ft_putstr(" ss: ", 2);
	ft_putnbr(opcount.ss);
	ft_putstr(" pa: ", 2);
	ft_putnbr(opcount.pa);
	ft_putstr(" pb: ", 2);
	ft_putnbr(opcount.pb);
	ft_putstr("\n[bench] ra: ", 2);
	ft_putnbr(opcount.ra);
	ft_putstr(" rb: ", 2);
	ft_putnbr(opcount.rb);
	ft_putstr(" rr: ", 2);
	ft_putnbr(opcount.rr);
	ft_putstr(" rra: ", 2);
	ft_putnbr(opcount.rra);
	ft_putstr(" rrb: ", 2);
	ft_putnbr(opcount.rrb);
	ft_putstr(" rrr: ", 2);
	ft_putnbr(opcount.rrr);
	ft_putchar('\n', 2);
}

void	bench_stats(double disorder, char *strategy, stack_ops opcount,
		char *adp_what)
{
	ft_putstr("[bench] disorder: ", 2);
	print_double(disorder);
	ft_putstr("%\n", 2);
	ft_putstr("[bench] strategy: ", 2);
	print_strategy(strategy, adp_what);
	ft_putstr("[bench] total_ops: ", 2);
	print_ops(opcount);
}

char	*parse_flags_helper(char **av, t_everything *everything, int *i_comp,
		double disorder)
{
	char	*adp_what;

	adp_what = NULL;
	if (ft_strncmp(av[0], "--bench", ft_strlen("--bench") + 1) == 0)
		*i_comp = 1;
	if (ft_strncmp(av[*i_comp], "--simple", ft_strlen("--simple") + 1) == 0)
		selection_sort(everything);
	else if (ft_strncmp(av[*i_comp], "--medium", ft_strlen("--medium")
				+ 1) == 0)
		chunk_based(everything);
	else if (ft_strncmp(av[*i_comp], "--complex", ft_strlen("--complex")
				+ 1) == 0)
		radix_sort(everything);
	else if (ft_strncmp(av[*i_comp], "--adaptive", ft_strlen("--adaptive")
				+ 1) == 0)
		adp_what = adaptive_algo(everything);
	else
		error_handler(everything->a, everything->b, 0, NULL);
	bench_stats(disorder, av[*i_comp] + 2, everything->opcount, adp_what);
	return (adp_what);
}

void	parse_flags_body(t_everything *everything, int flags, char **av,
		int i_comp)
{
	double	disorder;
	char	*adp_what;

	disorder = count_inversions_of_stack(everything->a);
	if (flags == 2)
		parse_flags_helper(av, everything, &i_comp, disorder);
	else if (ft_strncmp(av[i_comp], "--simple", ft_strlen("--simple") + 1) == 0)
		selection_sort(everything);
	else if (ft_strncmp(av[i_comp], "--medium", ft_strlen("--medium") + 1) == 0)
		chunk_based(everything);
	else if (ft_strncmp(av[i_comp], "--complex", ft_strlen("--complex")
				+ 1) == 0)
		radix_sort(everything);
	else if (flags == 0 || ft_strncmp(av[i_comp], "--adaptive",
				ft_strlen("--adaptive") + 1) == 0 || ft_strncmp(av[i_comp],
				"--bench", ft_strlen("--bench") + 1) == 0)
	{
		adp_what = adaptive_algo(everything);
		if (ft_strncmp(av[i_comp], "--bench", ft_strlen("--bench") + 1) == 0)
			bench_stats(disorder, "adaptive", everything->opcount, adp_what);
	}
	else
		error_handler(everything->a, everything->b, 0, NULL);
}

void	parse_flags(char **av, t_everything *everything)
{
	int flags;

	flags = 0;
	while (av[flags] && ft_strncmp(av[flags], "--", 2) == 0)
	{
		if (ft_strncmp(av[flags], "--", 3) == 0)
			error_handler(everything->a, everything->b, 0, NULL);
		flags++;
	}
	if (flags > 2 || (flags == 2 && (ft_strncmp(av[0], "--bench",
					ft_strlen("--bench") + 1) && ft_strncmp(av[1], "--bench",
					ft_strlen("--bench") + 1))))
		error_handler(everything->a, everything->b, 0, NULL);
	parse_flags_body(everything, flags, av, 0);
}