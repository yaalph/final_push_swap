/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:56:00 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/10 16:56:01 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pushswap.h"

int main(int ac, char **av){
	t_everything	everything;
	t_stack			*a;
	t_stack			*b;

	(void)ac;
	a = NULL;
	b = NULL;
	everything = (t_everything){0};
	everything.a = &a;
	everything.b = &b;
	parser(av, &everything);
    printf("\n-----------------\nlist a after being sorted:\nfirst node:\n");
    ft_print_list(*(everything.a));
	del_ops(&everything.ops);
	del_stack(everything.a);
	del_stack(everything.b);
	return (0);
}

