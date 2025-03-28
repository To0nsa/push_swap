/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:20:10 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/27 14:22:44 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file push.c
 * @brief Implementation of push operations for stack A and B.
 *
 * This file defines the logic for the `pa` and `pb` operations, which move
 * the top element from one stack to the other. A static helper function,
 * `push`, performs the core memory manipulations and is used by both.
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
 * @brief Push the top element from one stack to another.
 *
 * This function copies the top element from `src` to `dst`, adjusts the
 * memory layout using `ft_memmove` for both source and destination, and
 * updates their respective sizes.
 *
 * @param src Pointer to source stack array.
 * @param dst Pointer to destination stack array.
 * @param size_src Pointer to the size of the source stack.
 * @param size_dst Pointer to the size of the destination stack.
 *
 * @note No operation is performed if the source stack is empty.
 *
 * @ingroup operations
 * @see pa
 * @see pb
 */
static void	push(int *src, int *dst, int *size_src, int *size_dst)
{
	if (*size_src > 0)
	{
		if (*size_dst > 0)
			ft_memmove(&dst[1], dst, (*size_dst) * sizeof(int));
		dst[0] = src[0];
		if (*size_src > 1)
			ft_memmove(src, &src[1], (*size_src - 1) * sizeof(int));
		(*size_src)--;
		(*size_dst)++;
	}
}

/**
 * @brief Push the top element from stack B to stack A.
 *
 * This function performs the `pa` operation and logs it to standard output.
 *
 * @param array Pointer to the stack structure.
 *
 * @ingroup operations
 * @see push
 */
void	pa(t_array *array)
{
	push(array->b, array->a, &array->b_size, &array->a_size);
	ft_putstr_fd("pa\n", 1);
}

/**
 * @brief Push the top element from stack A to stack B.
 *
 * This function performs the `pb` operation and logs it to standard output.
 *
 * @param array Pointer to the stack structure.
 *
 * @ingroup operations
 * @see push
 */
void	pb(t_array *array)
{
	push(array->a, array->b, &array->a_size, &array->b_size);
	ft_putstr_fd("pb\n", 1);
}
