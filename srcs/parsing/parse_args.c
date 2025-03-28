/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:50:58 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/28 09:02:42 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse_args.c
 * @brief Validates and parses program arguments into stack A.
 *
 * Handles both split-string and multiple-argument formats. Performs strict
 * error checking for invalid characters, overflows, duplicates, and sorts.
 *
 * Converts ASCII strings into integers using a custom `ft_atoi_strict` and
 * ensures uniqueness and valid bounds before initializing stack A.
 *
 * @author
 * Nicolas Louis (nicolas.lovis@hotmail.fr)
 * @date
 * Created: 2024/12/12
 *
 * @ingroup parsing
 */
#include "push_swap.h"

/**
 * @brief Checks for integer overflow before updating the parsed value.
 *
 * @param num Current parsed number.
 * @param digit The next digit character.
 * @param sign The sign of the number (1 or -1).
 * @return true if overflow would occur, false otherwise.
 *
 * @ingroup parsing
 * @see ft_atoi_strict
 */
static bool	ft_check_overflow(long long num, char digit, int sign)
{
	long long	cutoff;

	if (sign == 1)
		cutoff = INT_MAX / 10;
	else
		cutoff = (-(long long)INT_MIN) / 10;
	if (sign == 1)
	{
		if (num > cutoff || (num == cutoff && (digit - '0') > (INT_MAX % 10)))
			return (true);
	}
	else
	{
		if (-num > -((long long)INT_MIN / 10)
			|| (-num == -((long long)INT_MIN / 10)
				&& (digit - '0') > ((-(long long)INT_MIN) % 10)))
			return (true);
	}
	return (false);
}

/**
 * @brief Converts a string to an integer with overflow detection.
 *
 * Uses `ft_check_overflow` to validate input and supports `+` and `-` signs.
 * Returns a sentinel value (`ATOI_ERROR`) on overflow and sets an error flag.
 *
 * @param str The input string to parse.
 * @param error Pointer to a boolean that is set on error.
 * @return Parsed long long value.
 *
 * @ingroup parsing
 * @see ft_check_overflow
 */
long long	ft_atoi_strict(const char *str, bool *error)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	*error = false;
	while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		if (ft_check_overflow(num, *str, sign))
		{
			*error = true;
			return (ATOI_ERROR);
		}
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}


/**
 * @brief Converts argument strings into integers and validates them.
 *
 * - Ensures strings are numeric
 * - Uses `ft_atoi_strict` for safe conversion
 * - Validates int range
 * - Stores result in `array->a`
 *
 * @param array Pointer to the main stack structure.
 * @param args_array Parsed string array to convert.
 *
 * @ingroup parsing
 * @see ft_atoi_strict
 * @see perror_and_exit
 */
static void	convert_ascii_to_int(t_array *array, char **args_array)
{
	int			i;
	int			j;
	bool		error_flag;
	long long	result;

	i = 0;
	while (i < array->a_size)
	{
		j = 0;
		if (args_array[i][j] == '-' || args_array[i][j] == '+')
			j++;
		if (args_array[i][j] == '\0')
			perror_and_exit();
		while (args_array[i][j])
		{
			if (!ft_isdigit(args_array[i][j]))
				perror_and_exit();
			j++;
		}
		result = ft_atoi_strict(args_array[i], &error_flag);
		if (error_flag || result > INT_MAX || result < INT_MIN)
			perror_and_exit();
		array->a[i] = (int)result;
		i++;
	}
}

/**
 * @brief Checks if stack A contains only unique values.
 *
 * Compares every pair in the array and returns false if duplicates
 * are found.
 *
 * @param array Pointer to the main stack structure.
 * @return true if all values are unique, false otherwise.
 *
 * @ingroup parsing
 */
static int	is_unique(t_array *array)
{
	int	i;
	int	j;

	i = 0;
	while (i < array->a_size)
	{
		j = i + 1;
		while (j < array->a_size)
		{
			if (array->a[i] == array->a[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

/**
 * @brief Main argument parsing and validation function.
 *
 * - Accepts both quoted strings and multiple arguments
 * - Converts input to integers
 * - Validates format, uniqueness, and range
 * - Sets up `array->a` and `array->a_size`
 *
 * Exits on failure. If the array is already sorted, the program exits
 * immediately to save operations.
 *
 * @param array Pointer to the main stack structure.
 * @param argc Argument count.
 * @param argv Argument values.
 *
 * @ingroup parsing
 * @see convert_ascii_to_int
 * @see is_unique
 * @see ft_is_array_sorted
 */
void	parse_arguments(t_array *array, int argc, char **argv)
{
	if (argc < 2)
		exit(EXIT_FAILURE);
	if (argc == 2)
	{
		array->args_array = ft_split(argv[1], ' ');
		if (!array->args_array)
		{
			ft_free_array_size((void *)array->args_array, array->a_size);
			perror_and_exit();
		}
	}
	else if (argc > 2)
		array->args_array = argv + 1;
	while (array->args_array[array->a_size])
		array->a_size++;
	if (array->a_size > PS_SIZE_MAX)
		perror_and_exit();
	convert_ascii_to_int(array, array->args_array);
	if (argc == 2)
		ft_free_array_size((void *)array->args_array, array->a_size);
	if (is_unique(array) == false)
		perror_and_exit();
	if (ft_is_array_sorted(array->a, array->a_size))
		exit(EXIT_FAILURE);
}
