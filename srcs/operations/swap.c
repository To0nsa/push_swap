/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:20:45 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/27 14:29:02 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file swap.c
 * @brief Implements swap operations for push_swap.
 *
 * Defines the swap logic and applies it to stacks A, B, or both. The swap
 * operation exchanges the first two elements at the top of the stack.
 *
 * @author
 * Nicolas Louis (nicolas.lovis@hotmail.fr)
 * @date
 * Created: 2024/12/12
 *
 * @ingroup operations
 */
#include "push_swap.h"

/**
 * @brief Swaps the first two elements of a stack.
 *
 * If the stack has fewer than two elements, no operation is performed.
 *
 * @param array The stack array to modify.
 * @param size The number of elements in the stack.
 *
 * @ingroup operations
 */
static void	swap(int *array, int size)
{
	int	temp;

	if (size > 1)
	{
		temp = array[0];
		array[0] = array[1];
		array[1] = temp;
	}
}

/**
 * @brief Performs a swap on the top two elements of stack A.
 *
 * Executes the `sa` operation and logs it to standard output.
 *
 * @param array Pointer to the main stack structure.
 *
 * @ingroup operations
 * @see swap
 */
void	sa(t_array *array)
{
	swap(array->a, array->a_size);
	ft_putstr_fd("sa\n", 1);
}

/**
 * @brief Performs a swap on the top two elements of stack B.
 *
 * Executes the `sb` operation and logs it to standard output.
 *
 * @param array Pointer to the main stack structure.
 *
 * @ingroup operations
 * @see swap
 */
void	sb(t_array *array)
{
	swap(array->b, array->b_size);
	ft_putstr_fd("sb\n", 1);
}

/**
 * @brief Performs a swap on both stacks A and B simultaneously.
 *
 * Executes the `ss` operation and logs it to standard output.
 *
 * @param array Pointer to the main stack structure.
 *
 * @ingroup operations
 * @see swap
 */
void	ss(t_array *array)
{
	swap(array->a, array->a_size);
	swap(array->b, array->b_size);
	ft_putstr_fd("ss\n", 1);
}
