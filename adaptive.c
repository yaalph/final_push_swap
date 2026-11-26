
// #include "pushswap.h"

// char	*adaptive_algo(t_everything *everything)
// {
// 	if (!everything->a || !everything->b || !(*everything->a))
// 		return (NULL);

// 	double s_disorder = count_inversions_of_stack(everything->a);

// 	if ((s_disorder * 100) < 20)
// 	{
// 		selection_sort(everything);
// 		return ("simple");
// 	}
// 	else if ((s_disorder * 100) >= 20 && (s_disorder * 100) < 50)
// 	{
// 		chunk_based(everything);
// 		return ("medium");
// 	}
// 	else
// 		radix_sort(everything);
// 	return ("complex");
// }