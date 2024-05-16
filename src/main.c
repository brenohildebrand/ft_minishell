/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:51:06 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/16 18:51:23 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"

t_i32	main(void)
{
	#ifdef DEBUG
		printf("\033[94mMinishell is running in DEBUG mode.\033[0m\n");
	#endif
	t_minishell	mini;

	mini = new_minishell();
	while (42)
	{
		mini->line = NULL;
		mini->line = readline(PROMPT);
		#ifdef DEBUG
			printf("\033[94m(line) %s\033[0m\n", mini->line);
		#endif
		if (mini->line == NULL)
		{
			write(STDOUT_FILENO, "exit\n", 5);
			destroy_minishell(mini);
			return (0);
		}
		else if (mini->line[0] != '\0')
		{
			add_history(mini->line);
			if (lexer(mini) == SUCCESS)
			{
				if (parser(mini) == SUCCESS)
					set_exit_status(mini, executor(mini));
			}
		}
		reset_minishell(mini);
	}
}
