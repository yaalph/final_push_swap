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
    t_everything everything;
    everything = (t_everything){0};
    // ft_print_list(a);
    // ft_print_list(b);
    // radix_sort(&a, &b);
    
    // ft_print_list(a);
    // ft_print_list(b);


	del_ops(&everything.ops);
	del_stack(&everything.a);
	del_stack(&everything.b);

}