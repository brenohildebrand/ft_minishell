/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_get_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:47:04 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/22 11:33:33 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	multiline_flag_is_on(t_mini mini)
{
	return (mini->flags & MINI_FLAG_MULTILINE);
}

#ifdef CUSTOM_PROMPT

// The custom prompt has the following format: '$(USER)@$(NAME):$(PWD)$ '.
static t_cstring	get_custom_prompt(t_mini mini)
{
	const t_cstring	user = cstring_copy(mini, getenv("USER"));
	const t_cstring	name = cstring_copy(mini, getenv("NAME"));
	const t_cstring	hostname = cstring_copy(mini, getenv("HOSTNAME"));
	const t_cstring	pwd = cstring_copy(mini, getenv("PWD"));
	t_cstring		prompt;

	prompt = NULL;
	prompt = cstring_join(mini, prompt, cstring_copy(mini, "\033[1;32m"));
	prompt = cstring_join(mini, prompt, user);
	if (name != NULL)
	{
		prompt = cstring_join(mini, prompt, cstring_copy(mini, "@"));
		prompt = cstring_join(mini, prompt, name);
	}
	else if (hostname != NULL)
	{
		prompt = cstring_join(mini, prompt, cstring_copy(mini, "@"));
		prompt = cstring_join(mini, prompt, hostname);
	}
	prompt = cstring_join(mini, prompt, cstring_copy(mini, "\033[0m"));
	prompt = cstring_join(mini, prompt, cstring_copy(mini, ":"));
	prompt = cstring_join(mini, prompt, cstring_copy(mini, "\033[1;34m"));
	prompt = cstring_join(mini, prompt, pwd);
	prompt = cstring_join(mini, prompt, cstring_copy(mini, "\033[0m"));
	prompt = cstring_join(mini, prompt, cstring_copy(mini, "$"));
	prompt = cstring_join(mini, prompt, cstring_copy(mini, " "));
	return (prompt);
}

t_cstring	mini_get_prompt(t_mini mini)
{
	t_cstring	prompt;

	if (multiline_flag_is_on(mini))
	{
		prompt = MULTILINE_PROMPT;
	}
	else
	{
		prompt = get_custom_prompt(mini);
	}
	return (prompt);
}

#else

t_cstring	mini_get_prompt(t_mini mini)
{
	t_cstring	prompt;

	if (multiline_flag_is_on(mini))
	{
		prompt = MULTILINE_PROMPT;
	}
	else
	{
		prompt = PROMPT;
	}
	return (prompt);
}

#endif