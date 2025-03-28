/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:24:46 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/27 14:27:42 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file rotate.c
 * @brief Implements rotate operations for push_swap.
 *
 * Defines the rotate logic and applies it to stacks A, B, or both. The rotate
 * operation shifts all elements up by one, moving the top element to the
 * bottom of the stack.
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
 * @brief Shifts all elements of a stack up by one position.
 *
 * The top element becomes the new bottom. No action is performed if the
 * stack has fewer than 2 elements.
 *
 * @param array The stack array to rotate.
 * @param size The number of elements in the stack.
 *
 * @ingroup operations
 */
void	rotate(int *array, int size)
{
	int	first;
	int	i;

	if (size > 1)
	{
		first = array[0];
		i = 0;
		while (i < size - 1)
		{
			array[i] = array[i + 1];
			i++;
		}
		array[size - 1] = first;
	}
}

/**
 * @brief Performs a rotate operation on stack A.
 *
 * Moves the top element of stack A to the bottom and prints the operation.
 *
 * @param array Pointer to the main stack structure.
 *
 * @ingroup operations
 * @see rotate
 */
void	ra(t_array *array)
{
	rotate(array->a, array->a_size);
	ft_putstr_fd("ra\n", 1);
}

/**
 * @brief Performs a rotate operation on stack B.
 *
 * Moves the top element of stack B to the bottom and prints the operation.
 *
 * @param array Pointer to the main stack structure.
 *
 * @ingroup operations
 * @see rotate
 */
void	rb(t_array *array)
{
	rotate(array->b, array->b_size);
	ft_putstr_fd("rb\n", 1);
}

/**
 * @brief Performs a rotate operation on both stacks A and B.
 *
 * Moves the top element of both stacks to the bottom and prints the
 * operation.
 *
 * @param array Pointer to the main stack structure.
 *
 * @ingroup operations
 * @see rotate
 */
void	rr(t_array *array)
{
	rotate(array->a, array->a_size);
	rotate(array->b, array->b_size);
	ft_putstr_fd("rr\n", 1);
}
