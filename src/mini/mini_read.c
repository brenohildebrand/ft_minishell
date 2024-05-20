/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:11:49 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/20 18:26:30 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_read(t_mini mini)
{
	const t_cstring	prompt = mini_get_prompt(mini);

	mini->line = readline(prompt);
	memtree_insert(&(mini->memtree), NULL, mini->line);
	#ifdef DEBUG
		printf("\033[94m(line) %s\033[0m\n", mini->line);
	#endif
}
