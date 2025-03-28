/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:26:58 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/27 14:25:58 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file reverse_rotate.c
 * @brief Implements reverse rotate operations for push_swap.
 *
 * Defines the reverse rotation logic and applies it to stacks A, B, or both.
 * The reverse rotation shifts all elements down by one, moving the last
 * element to the top.
 *
 * @author
 * Nicolas Louis (nicolas.lovis@hotmail.fr)
 * @date
 * Created: 2024/12/12
 *
 * @ingroup operations
 */
#include <push_swap.h>

/**
 * @brief Shifts all elements of a stack down by one position.
 *
 * The last element becomes the new top. No action is performed if the
 * stack has fewer than 2 elements.
 *
 * @param array The stack array to reverse rotate.
 * @param size The number of elements in the stack.
 *
 * @ingroup operations
 */
void	reverse_rotate(int *array, int size)
{
	int	last;
	int	i;

	if (size > 1)
	{
		last = array[size - 1];
		i = size - 1;
		while (i > 0)
		{
			array[i] = array[i - 1];
			i--;
		}
		array[0] = last;
	}
}

/**
 * @brief Performs a reverse rotation on stack A.
 *
 * Moves the bottom element of stack A to the top and prints the operation.
 *
 * @param array Pointer to the main stack structure.
 *
 * @ingroup operations
 * @see reverse_rotate
 */
void	rra(t_array *array)
{
	reverse_rotate(array->a, array->a_size);
	ft_putstr_fd("rra\n", 1);
}


/**
 * @brief Performs a reverse rotation on stack B.
 *
 * Moves the bottom element of stack B to the top and prints the operation.
 *
 * @param array Pointer to the main stack structure.
 *
 * @ingroup operations
 * @see reverse_rotate
 */
void	rrb(t_array *array)
{
	reverse_rotate(array->b, array->b_size);
	ft_putstr_fd("rrb\n", 1);
}

/**
 * @brief Performs a reverse rotation on both stacks A and B.
 *
 * Moves the bottom element of both stacks to the top and prints the
 * operation.
 *
 * @param array Pointer to the main stack structure.
 *
 * @ingroup operations
 * @see reverse_rotate
 */
void	rrr(t_array *array)
{
	reverse_rotate(array->a, array->a_size);
	reverse_rotate(array->b, array->b_size);
	ft_putstr_fd("rrr\n", 1);
}
