/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_reader_create_multiline_prompt.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:38:37 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 22:39:20 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifdef ENABLE_LUA

t_none	mini_reader_create_multiline_prompt(t_mini mini)
{
	mini->reader->multiline_prompt = mini->config->multiline_prompt;
}

#else

t_none	mini_reader_create_multiline_prompt(t_mini mini)
{
	mini->reader->multiline_prompt = MULTILINE_PROMPT;
}

#endif