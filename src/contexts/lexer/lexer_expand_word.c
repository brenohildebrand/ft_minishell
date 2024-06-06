/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_expand_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:49:10 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 13:08:01 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	lexer_expand_word(t_mini mini, t_list_node node)
{
	t_mini_token	token;

	token = (t_mini_token)node->value;	
	mini->str = cstring_get_subcstring(mini, token->value, 1, token->length);
	mini_free(mini, token->value);
	token->value = lexer_expand(mini, mini->str);
	mini_free(mini, mini->str);
}
