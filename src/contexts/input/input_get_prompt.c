/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_get_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:47:04 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/31 18:39:34 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

#ifdef ENABLE_LUA

t_none	input_get_prompt(t_mini mini)
{
	if (mini->is_multiline)
	{
		mini->input->prompt = MULTILINE_PROMPT;
	}
	else
	{
		mini->input->prompt = mini->config->prompt;
	}
}

#else

t_none	input_get_prompt(t_mini mini)
{
	if (mini->is_multiline)
	{
		mini->input->prompt = MULTILINE_PROMPT;
	}
	else
	{
		mini->input->prompt = PROMPT;
	}
}

#endif