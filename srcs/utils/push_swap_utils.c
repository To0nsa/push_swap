/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:36:37 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/28 08:51:48 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file push_swap_utils.c
 * @brief Utility functions for error handling in push_swap.
 *
 * Provides simple helpers like error printing and controlled exits.
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
 * @brief Prints an error message and exits the program.
 *
 * Prints "Error" to standard error and terminates the program
 * with a failure exit status.
 *
 * @ingroup utils
 */
void	perror_and_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
