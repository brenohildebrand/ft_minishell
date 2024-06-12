/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_heredoc_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:45:53 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/12 13:00:03 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_heredoc_create(t_mini mini)
{
	mini->heredoc = mini_alloc(mini, sizeof(struct s_heredoc_process));
	mini->heredoc->redirs = NULL;
	mini->heredoc->buffer = NULL;
	mini->heredoc->counter = 0;
}
