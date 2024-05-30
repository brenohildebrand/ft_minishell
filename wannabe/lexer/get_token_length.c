/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:40:47 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 14:41:38 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"
#include "lexer.h"
#include "types.h"

t_i32	get_token_length(t_cstring line, t_i32 type)
{
	if (type == OPEN_PAREN || type == CLOSE_PAREN || type == PIPE \
		|| type == REDIR_IN || type == REDIR_OUT)
		return (1);
	else if (type == AND || type == OR || type == REDIR_APPEND \
		|| type == REDIR_HEREDOC)
		return (2);
	else if (type == WORD)
		return (get_word_length(line));
	return (0);
}
