/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_eval_echo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:55:05 by eduardocoel       #+#    #+#             */
/*   Updated: 2024/06/17 15:06:40 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32	mini_eval_echo(t_mini mini, t_i32 argc, t_i8 **argv, t_i8 **envp)
{
	t_i32	i;
	t_bool	n;

	(void)mini;
	(void)argc;
	(void)envp;
	i = 1;
	n = FALSE;
	if (argv[1] && cstring_compare(argv[1], "-n") == 0)
	{
		n = TRUE;
		i = 2;
	}
	while (argv[i])
	{
		cstring_to_stdout(argv[i]);
		if (argv[i + 1])
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
	if (!n)
		write(1, "\n", 1);
	return (0);
}
