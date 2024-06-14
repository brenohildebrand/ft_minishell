/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:59:37 by eduardocoel       #+#    #+#             */
/*   Updated: 2024/06/14 19:48:39 by eduardocoel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

t_i32	mini_eval_exit(t_mini mini, t_i32 argc, t_i8 **argv)
{
	t_i64	status;
	t_i32	error;

	(void) mini;
	status = 0;
	error = 0;
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
	{
		printf("exit\n");
	}
	if (argc > 2)
	{
		fprintf(stderr, "exit: too many arguments\n");
		return (FAILURE);
	}
	else if (argc == 2)
	{
		status = get_exit_status(argv[1], &error);
		if (error)
		{
			fprintf(stderr, "exit: %s: numeric argument required\n", argv[1]);
			exit(SYNTAX_ERROR);
		}
	}
	exit(status % 256);
}
