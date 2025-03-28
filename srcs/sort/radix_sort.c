/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:21:51 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/28 08:45:11 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file radix_sort.c
 * @brief Implements radix sort for push_swap.
 *
 * This file contains the radix sort logic used to efficiently sort stacks
 * larger than 5 elements using bitwise operations and stack manipulation.
 * The algorithm uses index-based binary sorting by pushing/pulling elements
 * between stacks A and B based on individual bit values.
 *
 * @author
 * Nicolas Louis (nicolas.lovis@hotmail.fr)
 * @date
 * Created: 2024/12/12
 *
 * @ingroup radix
 */
#include "push_swap.h"

/**
 * @brief Pushes all elements from stack B back to stack A.
 *
 * Called after one full round of radix bit processing.
 *
 * @param array Pointer to the main stack structure.
 *
 * @ingroup radix
 * @see pa
 */
static void	push_all_from_b_to_a(t_array *array)
{
	while (array->b_size != 0)
		pa(array);
}

/**
 * @brief Processes elements in stack B for the next bit level.
 *
 * Elements with a 0 in the next bit stay in B (via rotate),
 * and those with a 1 move to A.
 *
 * @param array Pointer to the main stack structure.
 * @param next_bit The bit position to test.
 * @param bit_count Maximum number of bits needed for the sort.
 *
 * @ingroup radix
 * @see rb
 * @see pa
 */
static void	process_array_b_for_next_bit(t_array *array, int next_bit,
																int bit_count)
{
	int	size;

	size = array->b_size;
	while (size > 0 && next_bit <= bit_count)
	{
		if (((array->b[0] >> next_bit) & 1) == 0)
			rb(array);
		else
			pa(array);
		size--;
	}
}

/**
 * @brief Moves elements from stack A to B based on bit value.
 *
 * Elements with a 0 in the current bit go to B, and those with a 1
 * are rotated within A.
 *
 * @param array Pointer to the main stack structure.
 * @param bit The bit position to test.
 *
 * @ingroup radix
 * @see pb
 * @see ra
 * @see ft_is_array_sorted
 */
static void	move_elements_from_a_based_on_bit(t_array *array, int bit)
{
	int	size;

	size = array->a_size;
	while (size > 0 && !ft_is_array_sorted(array->a, array->a_size))
	{
		if (((array->a[0] >> bit) & 1) == 0)
			pb(array);
		else
			ra(array);
		size--;
	}
}

/**
 * @brief Calculates the number of bits required for radix sort.
 *
 * The number of bits corresponds to the number needed to represent
 * the largest index.
 *
 * @param size Number of elements in the stack.
 * @return Number of bits required to sort.
 *
 * @ingroup radix
 */
static int	calculate_bit_count(int size)
{
	int	bit_count;

	bit_count = 0;
	while (size > 1)
	{
		size >>= 1;
		bit_count++;
	}
	return (bit_count);
}

/**
 * @brief Sorts the stack using radix sort and stack operations.
 *
 * This function:
 * - Assigns index-based values to elements
 * - Loops through each bit position to distribute elements
 * - Collects them back into A, sorted
 *
 * @param array Pointer to the main stack structure.
 *
 * @ingroup radix
 * @see assign_indices
 * @see give_values_back
 * @see move_elements_from_a_based_on_bit
 * @see process_array_b_for_next_bit
 * @see push_all_from_b_to_a
 */
void	radix_sort(t_array *array)
{
	int	bit;
	int	bit_count;

	assign_indices(array);
	bit_count = calculate_bit_count(array->a_size);
	bit = 0;
	while (bit <= bit_count)
	{
		move_elements_from_a_based_on_bit(array, bit);
		process_array_b_for_next_bit(array, bit + 1, bit_count);
		bit++;
	}
	push_all_from_b_to_a(array);
	give_values_back(array);
}
