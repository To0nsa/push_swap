/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_indices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:47:44 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/28 08:47:36 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file assign_indices.c
 * @brief Assigns normalized indices to stack A values for radix sort.
 *
 * This file includes functions to:
 * - Normalize values of stack A by assigning their sorted index
 * - Store original values for restoration after sorting
 *
 * Used primarily in radix sort to simplify bitwise sorting based on positive
 * index rather than raw value.
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
 * @brief Assigns a sorted index to each value in stack A.
 *
 * For each value in A, it looks up its sorted position in the copy and
 * replaces the original value with its index.
 *
 * @param array Pointer to the main stack structure.
 * @param copy Sorted copy of stack A values.
 *
 * @ingroup radix
 * @see assign_indices
 */
static void	assign_index(t_array *array, int *copy)
{
	int	i;
	int	j;

	i = 0;
	while (i < array->a_size)
	{
		j = 0;
		while (j < array->a_size)
		{
			if (array->a[i] == copy[j])
			{
				array->a[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}


/**
 * @brief Stores sorted values from stack A into a backup array.
 *
 * This allows restoring the original values after radix sort.
 *
 * @param array Pointer to the main stack structure.
 * @param copy Sorted copy of stack A values.
 *
 * @ingroup radix
 * @see assign_indices
 * @see give_values_back
 */
static void	store_values(t_array *array, int *copy)
{
	int	i;

	i = 0;
	while (i < array->a_size)
	{
		array->sorted_values[i] = copy[i];
		i++;
	}
}

/**
 * @brief Prepares stack A for radix sort by assigning index-based values.
 *
 * - Copies stack A
 * - Sorts the copy
 * - Replaces each element in A with its index in the sorted copy
 * - Stores the sorted version for later restoration
 *
 * @param array Pointer to the main stack structure.
 *
 * @ingroup radix
 * @see assign_index
 * @see store_values
 * @see ft_qsort
 * @see int_cmp
 */
void	assign_indices(t_array *array)
{
	int	array_a_copy[PS_SIZE_MAX];

	ft_memmove(array_a_copy, array->a, array->a_size * sizeof(int));
	ft_qsort(array_a_copy, array->a_size, sizeof(int), int_cmp);
	assign_index(array, array_a_copy);
	store_values(array, array_a_copy);
}

/**
 * @brief Restores the original values in stack A after sorting.
 *
 * Uses the previously stored `sorted_values` array to recover
 * the original pre-indexed data.
 *
 * @param array Pointer to the main stack structure.
 *
 * @ingroup radix
 * @see store_values
 */
void	give_values_back(t_array *array)
{
	int	i;

	i = 0;
	while (i < array->a_size)
	{
		array->a[i] = array->sorted_values[i];
		i++;
	}
}
