/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_reader_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 00:16:00 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 09:50:43 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_reader_create(t_mini mini)
{
	mini->reader = mini_alloc(mini, sizeof(struct s_reader_process));
	mini->reader->line = NULL;
	mini->reader->prompt = mini_reader_create_prompt(mini);
	mini->reader->is_complete = FALSE;
	mini->reader->is_multiline = FALSE;
}
