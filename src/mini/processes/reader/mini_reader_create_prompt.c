/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_reader_create_prompt.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 09:50:51 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 22:39:19 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifdef ENABLE_LUA

t_none	mini_reader_create_prompt(t_mini mini)
{
	mini->reader->prompt = mini->config->prompt;
}

#else

t_none	mini_reader_create_prompt(t_mini mini)
{
	mini->reader->prompt = PROMPT;
}

#endif
