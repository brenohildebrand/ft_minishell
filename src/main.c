/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:51:06 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/14 22:55:40 by eduardocoel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifdef ENABLE_DEBUGGER

t_i32	main(t_i32 argc, t_i8 **argv)
{
	t_mini	mini;

	printf("Mini is running in \033[94mDEBUG\033[0m mode.\n");
	mini = mini_create(argc, argv);
	while (42)
	{
		while (mini_is_complete(mini))
		{
			mini_read(mini);
			mini_tokenize(mini);
			mini_expand(mini);
			mini_parse(mini);
		}
		mini_heredoc(mini);
		mini_eval(mini);
		mini_reset(mini);
	}
}

#else

#endif
