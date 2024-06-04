/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_expand_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:49:10 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/04 12:08:38 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

// $? is the exit status
// env variables, $? or empty

t_none	lexer_expand_word(t_mini mini, t_list_node node)
{
	const t_lexer	lexer = mini->lexer;
	t_mini_token	token;

	token = (t_mini_token)node->value;	
	mini->str = cstring_get_subcstring(mini, token->value, 1, token->length);
	mini_free(mini, node->value);
	node->value = lexer_expand(mini->str);
}
