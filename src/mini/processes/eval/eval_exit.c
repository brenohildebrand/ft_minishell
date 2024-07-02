/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 00:27:33 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/02 13:27:24 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <limits.h>

static t_i32	is_valid_number(t_cstring str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit((t_u8)*str))
			return (0);
		str++;
	}
	return (1);
}

static t_i64	get_exit_status(t_cstring arg, t_i32 *error)
{
	t_i64		status;
	t_cstring	endptr;

	status = 0;
	if (!is_valid_number(arg))
	{
		*error = 1;
		return (0);
	}
	status = ft_strtol(arg, &endptr, 10);
	if (*endptr != '\0' || ((status == LONG_MAX || status == LONG_MIN)
			&& errno == ERANGE))
	{
		*error = 1;
		return (0);
	}
	return (status);
}

t_i32	eval_exit(t_mini mini, t_i32 argc, t_i8 **argv, t_i8 **envp)
{
	t_i64	status;
	t_i32	error;

	(void)mini;
	(void)envp;
	status = 0;
	error = 0;
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
	{
		printf("exit\n");
	}
	if (argc > 2)
	{
		cstring_to_stdout("exit: too many arguments\n");
		return (FAILURE);
	}
	else if (argc == 2)
	{
		status = get_exit_status(argv[1], &error);
		if (error)
		{
			cstring_to_stdout("exit: numeric argument required\n");
			exit(SYNTAX_ERROR);
		}
	}
	exit(status % 256);
}
