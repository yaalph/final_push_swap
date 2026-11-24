
#include "pushswap.h"

char *adaptive_algo(t_stack** stacka, t_stack** stackb, int size, stack_ops* my_ops)
{
    if (!stacka || !stackb || !(*stacka))
        return NULL;

    double s_disorder = count_inversions_of_stack(stacka);

    if ((s_disorder * 100) < 20){
        simple_algo(stacka, stackb, size, my_ops);
        return "simple";
    }
    else if ((s_disorder * 100) >= 20 && (s_disorder * 100) < 50){
        sort_stack(stacka, stackb, size, my_ops);
        return "medium";
    }
    else
        radix_sort(stacka, stackb);
    return "complex";
}