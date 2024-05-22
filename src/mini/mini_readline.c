/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_readline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:23:30 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/22 13:18:07 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_readline(t_mini mini)
{
	const t_cstring	prompt = mini_get_prompt(mini);

	mini->line = readline(prompt);
	if (mini->line != NULL)
		memtree_insert(&(mini->memtree), NULL, mini->line);
	mini->statement = cstring_join(mini, mini->statement, cstring_copy(mini, mini->line));
	#ifdef DEBUG
		printf("\033[94m[%s:%d]\033[0m %s\n", __func__, __LINE__, mini->line);
	#endif
	if (mini->line == NULL)
	{
		cstring_to_stdout("\033[33mAn empty line with only EOF was entered. I'm quitting.\033[0m\n");
		mini_quit(mini);
	}
}
