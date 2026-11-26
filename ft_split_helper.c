/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 11:43:45 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/26 11:43:46 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	count_words(char const *s, char *charset, size_t end)
{
	size_t cnt;
	size_t i;

	cnt = 1;
	i = 0;
	while (i <= end && s[i])
	{
		if (ft_issep(charset, s[i]))
		{
			cnt++;
			while (i <= end && s[i] && ft_issep(charset, s[i]))
				i++;
		}
		else
			i++;
	}
	return (cnt);
}