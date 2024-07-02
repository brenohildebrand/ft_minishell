/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:20:50 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 19:57:35 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini	mini_create(t_i32 argc, t_i8 **argv, t_i8 **envp)
{
	t_mini	mini;

	mini = malloc(sizeof(struct s_mini));
	mini_assert(mini, mini != NULL, MINI_ERROR);
	shared_create(mini, argc, argv, envp);
	signals_create(mini);
	reader_create(mini);
	lexer_create(mini);
	expansion_create(mini);
	parser_create(mini);
	heredoc_create(mini);
	eval_create(mini);
	return (mini);
}
