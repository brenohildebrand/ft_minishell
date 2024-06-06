/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:51:06 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 00:34:10 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifdef ENABLE_DEBUGGER

t_i32	main(void)
{
	t_mini	mini;

	printf("Mini is running in \033[94mDEBUG\033[0m mode.\n");
	mini = mini_create();
	while (42)
	{
		while (!mini->reader->is_complete)
		{
			mini_reader(mini);
			mini_lexer(mini);
			mini_expansion(mini);
			mini_parser(mini);
		}
		mini_eval(mini);
	}
}

#else

t_i32	main(void)
{
	t_mini	mini;

	mini = mini_create();
	while (42)
	{
		while (!mini->reader->is_complete)
		{
			mini_reader(mini);
			mini_lexer(mini);
			mini_expansion(mini);
			mini_parser(mini);
		}
		mini_eval(mini);
	}
}

#endif
