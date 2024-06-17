/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:20:50 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/17 13:51:16 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini	mini_create(t_i32 argc, t_i8 **argv, t_i8 **envp)
{
	t_mini	mini;

	mini = malloc(sizeof(struct s_mini));
	mini_assert(mini, mini != NULL, MINI_ERROR);
	mini_shared_create(mini, argc, argv, envp);
	mini_config_create(mini);
	mini_signals_create(mini);
	mini_reader_create(mini);
	mini_lexer_create(mini);
	mini_expansion_create(mini);
	mini_parser_create(mini);
	mini_heredoc_create(mini);
	mini_eval_create(mini);
	return (mini);
}
