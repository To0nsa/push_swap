/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:29:51 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/28 08:41:24 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file sort_small_array.c
 * @brief Implements sorting logic for small stack sizes (≤ 5 elements).
 *
 * Contains logic to efficiently sort stacks of 2, 3, 4, or 5 elements
 * using a minimal number of operations. This is used instead of radix
 * sort for small input sizes to reduce operation count.
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
 * @brief Sorts two elements in stack A.
 *
 * Performs a single swap if necessary.
 *
 * @param array Pointer to the main stack structure.
 *
 * @ingroup sorting
 * @see sa
 */
void	sort_two(t_array *array)
{
	sa(array);
}

/**
 * @brief Sorts three elements in stack A.
 *
 * Applies conditional logic to perform the minimal number of
 * operations needed to sort three elements.
 *
 * @param array Pointer to the main stack structure.
 *
 * @ingroup sorting
 * @see sa
 * @see ra
 * @see rra
 */
void	sort_three(t_array *array)
{
	if (array->a[0] > array->a[1] && array->a[1] < array->a[2]
		&& array->a[0] < array->a[2])
		sa(array);
	else if (array->a[0] > array->a[1] && array->a[1] > array->a[2]
		&& array->a[0] > array->a[2])
	{
		sa(array);
		rra(array);
	}
	else if (array->a[0] > array->a[1] && array->a[1] < array->a[2]
		&& array->a[0] > array->a[2])
		ra(array);
	else if (array->a[0] < array->a[1] && array->a[1] > array->a[2]
		&& array->a[0] > array->a[2])
		rra(array);
	else if (array->a[0] < array->a[1] && array->a[1] > array->a[2]
		&& array->a[0] < array->a[2])
	{
		sa(array);
		ra(array);
	}
}

/**
 * @brief Finds the index of the smallest value in an array.
 *
 * @param array Pointer to the array.
 * @param size Number of elements in the array.
 * @return Index of the smallest value, or -1 if array is empty.
 *
 * @ingroup sorting
 * @see rotate_min_to_top
 */
static int	find_min_index(int *array, int size)
{
	int	min;
	int	min_index;
	int	i;

	if (size <= 0)
		return (-1);
	min = array[0];
	min_index = 0;
	i = 1;
	while (i < size)
	{
		if (array[i] < min)
		{
			min = array[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

/**
 * @brief Rotates the smallest value in stack A to the top.
 *
 * Chooses the shortest rotation direction based on the index of
 * the smallest value.
 *
 * @param array Pointer to the main stack structure.
 *
 * @ingroup sorting
 * @see find_min_index
 * @see ra
 * @see rra
 */
static void	rotate_min_to_top(t_array *array)
{
	int	min_index;

	min_index = find_min_index(array->a, array->a_size);
	if (min_index <= array->a_size / 2)
	{
		while (min_index > 0)
		{
			ra(array);
			min_index--;
		}
	}
	else
	{
		while (min_index < array->a_size)
		{
			rra(array);
			min_index++;
		}
	}
}

/**
 * @brief Sorts 4 or 5 elements in stack A using optimized logic.
 *
 * Pushes the smallest elements to stack B, sorts the remaining
 * 3 elements, and restores the pushed elements.
 *
 * @param array Pointer to the main stack structure.
 *
 * @ingroup sorting
 * @see sort_three
 * @see rotate_min_to_top
 * @see pb
 * @see pa
 */
void	sort_four_and_five(t_array *array)
{
	int	push_count;

	push_count = array->a_size - 3;
	while (push_count > 0)
	{
		rotate_min_to_top(array);
		pb(array);
		push_count--;
	}
	sort_three(array);
	while (array->b_size > 0)
		pa(array);
}
