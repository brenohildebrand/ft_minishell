/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:51:06 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/01 15:50:04 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32	main(t_i32 argc, t_i8 **argv, t_i8 **envp)
{
	t_mini	mini;

	mini = mini_create(argc, argv, envp);
	while (42)
	{
		while (mini_is_complete(mini))
		{
			mini_read(mini);
			mini_tokenize(mini);
			mini_expand(mini);
			mini_parse(mini);
		}
		mini_handle_heredoc(mini);
		mini_eval(mini);
		mini_reset(mini);
	}
}
