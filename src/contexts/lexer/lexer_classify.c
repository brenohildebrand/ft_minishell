/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_classify.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:28:20 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/04 10:20:52 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_i32	lexer_classify(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;

	if (lexer->state == 100)
		return (MINI_TOKEN_WORD);
	else if (lexer->state == 101)
		return (MINI_TOKEN_GT);
	else if (lexer->state == 102)
		return (MINI_TOKEN_DGT);
	else if (lexer->state == 103)
		return (MINI_TOKEN_LT);
	else if (lexer->state == 104)
		return (MINI_TOKEN_DLT);
	else if (lexer->state == 105)
		return (MINI_TOKEN_PIPE);
	else if (lexer->state == 106)
		return (MINI_TOKEN_DQUOTES);
	else if (lexer->state == 107)
		return (MINI_TOKEN_SQUOTES);
	else
	{
		write(STDERR_FILENO, "What the heck?!\n", 17);
		mini_quit(mini);
	}
	return (0);
}
