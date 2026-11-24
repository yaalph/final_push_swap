/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 01:10:53 by marvin            #+#    #+#             */
/*   Updated: 2026/11/24 19:09:29 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
double count_inversions_of_stack(t_stack** head){
    if(!head || !(*head)){
        return 0;
    }
    double mistakes = 0;
    double total_paires = 0;
    t_stack* tmp1 = *head;
    t_stack* tmp2 = NULL;

    while(tmp1 != NULL){
        tmp2 = tmp1->next;
        while(tmp2 != NULL){
            total_paires++;
            if(tmp1->value > tmp2->value){
                mistakes++;
            }
            tmp2 = tmp2->next;
        }
        tmp1 = tmp1->next;
    }
    if(total_paires == 0){
        return 0.0;
    }
    return mistakes / total_paires;
}