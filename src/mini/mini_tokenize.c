/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokenize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:07:35 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/22 14:33:25 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_none	go_to_next_state(t_i32 *p_state, t_cstring *p_cursor)
{
	t_i32	(*transition_table)[8];

	transition_table = mini_get_transition_table();
}


t_none	mini_tokenize(t_mini mini)
{
	t_i32		state;
	t_cstring	cursor;

	state = 0;
	cursor = mini->line;
	while (cursor)
	{
		go_to_next_state(&state, &cursor);
		if (is_final_state(state))
		{
			token = token_new();
			mini_add_token(mini);
		}
	}
	if (mini_check_flag(mini, MINI_FLAG_STATEMENT_COMPLETED))
	{
		add_history(mini->statement);
		mini_free(mini, mini->statement);
		mini->statement = NULL;
	}
	#ifdef DEBUG
	#endif
}
