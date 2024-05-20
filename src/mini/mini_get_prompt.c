/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_get_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:47:04 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/20 18:50:29 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static t_cstring	get_cwd(t_mini mini)
// {
// 	t_cstring		cwd;
// 	t_u32			cwd_size;

// 	cwd_size = 1024;
// 	cwd = malloc(cwd_size);
// 	mini_assert(mini, cwd != NULL, "Memory allocation error.\n");
// 	while (getcwd(cwd, cwd_size) == NULL)
// 	{
// 		cwd_size *= 2;
// 		cwd = malloc(cwd_size);
// 		mini_assert(mini, cwd != NULL, "Memory allocation error.\n");
// 	}
// 	return (cwd);
// }

/**
 * The prompt will have the following format:
 * $(USER)@$(NAME):$(PWD)$
*/
t_cstring	mini_get_prompt(t_mini mini)
{
	t_cstring	prompt;
	t_cstring	user;
	t_cstring	name;
	t_cstring	pwd;

	pwd = cstring_copy(mini, getenv("PWD"));
	user = cstring_copy(mini, getenv("USER"));
	name = cstring_copy(mini, getenv("NAME"));
	prompt = NULL;
	prompt = cstring_join(mini, prompt, cstring_copy(mini, "\033[1;32m"));
	prompt = cstring_join(mini, prompt, user);
	prompt = cstring_join(mini, prompt, cstring_copy(mini, "@"));
	prompt = cstring_join(mini, prompt, name);
	prompt = cstring_join(mini, prompt, cstring_copy(mini, "\033[0m"));
	prompt = cstring_join(mini, prompt, cstring_copy(mini, ":"));
	prompt = cstring_join(mini, prompt, cstring_copy(mini, "\033[1;34m"));
	prompt = cstring_join(mini, prompt, pwd);
	prompt = cstring_join(mini, prompt, cstring_copy(mini, "\033[0m"));
	prompt = cstring_join(mini, prompt, cstring_copy(mini, "$"));
	prompt = cstring_join(mini, prompt, cstring_copy(mini, " "));
	return (prompt);
}
