/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:29:38 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/28 08:54:03 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief Entry point of the push_swap program.
 *
 * Initializes the main stack structure, parses command-line arguments,
 * and triggers the appropriate sorting logic based on stack size.
 *
 * @author
 * Nicolas Louis (nicolas.lovis@hotmail.fr)
 * @date
 * Created: 2024/12/12
 *
 * @ingroup utils
 */
#include "push_swap.h"

/**
 * @brief Main function of the push_swap program.
 *
 * Initializes the stack structure, parses arguments, and sorts the stack
 * using the most efficient strategy available.
 *
 * @param argc Argument count.
 * @param argv Argument values.
 * @return Always returns EXIT_SUCCESS.
 *
 * @ingroup utils
 * @see parse_arguments
 * @see sort_array
 */
int	main(int argc, char **argv)
{
	t_array	array;

	ft_memset(&array, 0, sizeof(t_array));
	parse_arguments(&array, argc, argv);
	sort_array(&array);
	return (EXIT_SUCCESS);
}
