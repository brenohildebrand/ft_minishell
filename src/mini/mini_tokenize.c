/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokenize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:07:35 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/14 23:52:43 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_tokenize(t_mini mini)
{
	t_mini_list		list;

	mini_lexer_automaton(mini);
	list = mini->lexer->tokens;
	printf("\033[94m[%s:%d]\n(tokens)\033[0m ", __func__, __LINE__);
	while (list)
	{
		printf("%s", list->token);
		if (list->next)
			printf(", ");
		list = list->next;
	}
	printf("\n");
}
