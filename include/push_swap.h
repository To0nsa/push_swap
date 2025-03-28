/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:24:15 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/28 10:26:53 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file push_swap.h
 * @brief Header file for the push_swap project (42).
 *
 * Defines the core data structure and declares functions used in the
 * push_swap sorting algorithm. The goal of the program is to sort a list
 * of integers using only a limited set of stack operations (push, swap, rotate).
 *
 * This file includes parsing, error handling, operation implementations,
 * and multiple sorting strategies, including radix sort and small-size optimizations.
 *
 * @author
 * Nicolas Louis (nicolas.lovis@hotmail.fr)
 * @date
 * Created: 2024/12/11
 */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "libft.h"

/**
 * @brief Maximum size of the stacks.
 */
# define PS_SIZE_MAX	100000

/**
 * @struct s_array
 * @brief Core structure holding stack data and utility arrays.
 *
 * This structure simulates two stacks (A and B) using arrays.
 * It also stores the input arguments and the sorted target state.
 */
typedef struct s_array
{
	char	**args_array;				/**< Original input arguments as strings */
	int		a_size;						/**< Dynamic size of stack A */				
	int		a[PS_SIZE_MAX];				/**< Stack A */
	int		b_size;						/**< Dynamic size of stack B */	
	int		b[PS_SIZE_MAX];				/**< Stack B */
	int		sorted_values[PS_SIZE_MAX];	
}	t_array;

/** @defgroup utils Utility Functions
 *  @brief Function for error handling.
 *  @{
 */
void	perror_and_exit(void);
/** @} */

/** @defgroup parsing Argument Parsing
 *  @brief Functions for validating and converting CLI arguments.
 *  @{
 */
void	parse_arguments(t_array *array, int argc, char **argv);
/** @} */

/** @defgroup operation Stack Operations
 *  @brief Functions implementing allowing stack manipulations.
 *  @{
 */
void	sa(t_array *array);
void	sb(t_array *array);
void	ss(t_array *array);
void	pa(t_array *array);
void	pb(t_array *array);
void	ra(t_array *array);
void	rb(t_array *array);
void	rr(t_array *array);
void	rra(t_array *array);
void	rrb(t_array *array);
void	rrr(t_array *array);
/** @} */

/** @defgroup sorting Sorting Algorithms
 *  @brief Functions for dispatching and sorting small sets of values.
 *  @{
 */
void	sort_array(t_array *array);
void	sort_two(t_array *array);
void	sort_three(t_array *array);
void	sort_four_and_five(t_array *array);
/** @} */

/** @defgroup radix Radix Sort Logic
 *  @brief Functions for radix sort algorithm.
 *  @{
 */
void	radix_sort(t_array *array);
void	assign_indices(t_array *array);
void	give_values_back(t_array *array);
/** @} */

#endif