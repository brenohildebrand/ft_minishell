/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lib_ft_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:50:15 by eduardocoel       #+#    #+#             */
/*   Updated: 2024/06/13 20:10:48 by eduardocoel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i64	convert_str_to_long(const char *str, int base, int sign)
{
	t_i64	result;
	t_i64	digit;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		if (result > LONG_MAX / 10 || (result == LONG_MAX / 10
				&& digit > LONG_MAX % 10))
		{
			errno = ERANGE;
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		result = result * 10 + digit;
		str++;
	}
	return (result * sign);
}

t_i64	ft_strtol(t_cstring str, t_cstring_array endptr, t_i32 base)
{
	t_i64	result;
	int		sign;

	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (base == 10 || base == 0)
		result = convert_str_to_long(str, base, sign);
	else
	{
		errno = EINVAL;
		result = 0;
	}
	if (endptr)
		*endptr = (char *)str;
	return (result);
}
