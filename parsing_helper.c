/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 11:44:20 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/26 11:44:21 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_double(double n)
{
	long	v;

	v = (long)(n * 10000 + 0.5);
	ft_putnbr(v / 100);
	ft_putchar('.', 2);
	if (v % 100 < 10)
		ft_putchar('0', 2);
	ft_putnbr(v % 100);
}

void	first_upper(char *s)
{
	char	c;

	c = *s - ('a' - 'A');
	write(2, &c, 1);
	ft_putstr(s + 1, 2);
}

void	print_strategy(char *s, char *adp_what)
{
	first_upper(s);
	if (!adp_what)
		return ;
	if (ft_strncmp(s, "adaptive", ft_strlen("adaptive") + 1) == 0)
	{
		if (ft_strncmp(adp_what, "simple", ft_strlen("simple") + 1) == 0)
			ft_putstr(" / O(n²)\n", 2);
		else if (ft_strncmp(adp_what, "medium", ft_strlen("medium") + 1) == 0)
			ft_putstr(" / O(n√n)\n", 2);
		else if (ft_strncmp(adp_what, "complex", ft_strlen("complex") + 1) == 0)
			ft_putstr(" / O(n log n)\n", 2);
	}
	else if (ft_strncmp(s, "simple", ft_strlen("simple") + 1) == 0)
		ft_putstr(" / O(n²)\n", 2);
	else if (ft_strncmp(s, "medium", ft_strlen("medium") + 1) == 0)
		ft_putstr(" / O(n√n)\n", 2);
	else if (ft_strncmp(s, "complex", ft_strlen("complex") + 1) == 0)
		ft_putstr(" / O(n log n)\n", 2);
}

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == INT_MIN)
	{
		write(2, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-', 2);
	}
	if (n < 10)
	{
		ft_putchar(n + '0', 2);
		return ;
	}
	ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0', 2);
}