/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 11:44:25 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/26 11:44:26 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	parser(char **av, t_everything *everything)
{
	char	**sub_args;
	char	**argv;

	argv = av;
	av++;
	if (!*av)
		exit(0);
	while (*av && ft_strncmp(*av, "--", 2) == 0)
		av++;
	if (!*av)
		error_handler(everything->a, everything->b, 0, NULL);
	while (*av)
	{
		sub_args = ft_split(*av, " \t");
		if (!sub_args)
			error_handler(everything->a, everything->b, 0, NULL);
		if (!*sub_args)
			error_handler(everything->a, everything->b, 1, sub_args);
		validate_split_words(sub_args, everything->a, everything->b);
		free_words(sub_args);
		av++;
	}
	parse_flags(argv + 1, everything);
}
