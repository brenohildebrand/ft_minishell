/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:51:06 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/03 14:52:22 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

#ifdef ENABLE_DEBUGGER

t_i32	main(t_i32 argc, t_cstring_array argv)
{
	t_mini	mini;

	printf("Mini is running in \033[94mDEBUG\033[0m mode.\n");
	mini = mini_create(argc, argv);
	while (42)
	{
		while (!mini->input->is_complete)
		{
			mini_read(mini);
			mini_tokenize(mini);
			mini_expand(mini);
			mini_parse(mini);
		}
		mini_execute(mini);
	}
}

#else

t_i32	main(t_i32 argc, t_cstring_array argv)
{
	t_mini	mini;

	mini = mini_create(argc, argv);
	while (42)
	{
		while (!mini->input->is_complete)
		{
			mini_read(mini);
			mini_tokenize(mini);
			mini_expand(mini);
			mini_parse(mini);
		}
		mini_execute(mini);
	}
}

#endif
