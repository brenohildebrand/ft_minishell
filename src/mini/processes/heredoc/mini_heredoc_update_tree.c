/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_heredoc_update_tree.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:36:22 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/12 13:21:37 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_heredoc_update_tree(t_mini mini)
{
	t_cstring	filename;
	t_cstring	filepath;

	mini_free(mini, mini->heredoc->redirs->next->token);	
	mini->heredoc->redirs->next->token = NULL;
	filename = mini_cstring_join(mini, mini_cstring_copy(mini, "mini.heredoc."), mini_u8_to_cstring(mini, mini->heredoc->counter - 1));
	filepath = mini_cstring_join(mini, mini_cstring_copy(mini, "/tmp/"), filename);
	mini->heredoc->redirs->next->token = filepath;
	mini_free(mini, filepath);
}