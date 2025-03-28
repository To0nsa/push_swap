/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:45:10 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/28 08:48:52 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file sort_array.c
 * @brief Sorting entry point for push_swap.
 *
 * Contains the main dispatcher function that selects an appropriate sorting
 * strategy based on the size of stack A.
 *
 * For:
 * - 2 elements: simple swap
 * - 3 elements: hardcoded mini-sort
 * - 4–5 elements: optimized small-sort logic
 * - 6+ elements: radix sort
 *
 * @author
 * Nicolas Louis (nicolas.lovis@hotmail.fr)
 * @date
 * Created: 2024/12/12
 *
 * @ingroup sorting
 */
#include "push_swap.h"

/**
 * @brief Sorts stack A using the most efficient strategy based on size.
 *
 * Chooses from different sorting algorithms depending on the number of
 * elements in stack A:
 * - 2 → `sort_two`
 * - 3 → `sort_three`
 * - 4–5 → `sort_four_and_five`
 * - 6+ → `radix_sort`
 *
 * @param array Pointer to the main stack structure.
 *
 * @ingroup sorting
 * @see sort_two
 * @see sort_three
 * @see sort_four_and_five
 * @see radix_sort
 */
void	sort_array(t_array *array)
{
	if (array->a_size == 2)
		sort_two(array);
	else if (array->a_size == 3)
		sort_three(array);
	else if (array->a_size <= 5)
		sort_four_and_five(array);
	else
		radix_sort(array);
}
