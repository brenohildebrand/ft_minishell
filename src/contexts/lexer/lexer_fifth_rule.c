/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_fifth_rule.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:18:44 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/01 23:31:49 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

/**
 * 5th rule:
 * If the current character is an unquoted '$' or '`', the shell shall 
 * identify the start of any candidates for parameter expansion 
 * (Parameter Expansion), command substitution (Command Substitution), 
 * or arithmetic expansion (Arithmetic Expansion) from their introductory 
 * unquoted character sequences: '$' or "${", "$(" or '`', and 
 * "$((", respectively. The shell shall read sufficient input to determine 
 * the end of the unit to be expanded (as explained in the cited sections). 
 * While processing the characters, if instances of expansions or quoting are 
 * found nested within the substitution, the shell shall recursively process 
 * them in the manner specified for the construct that is found. The characters
 * found from the beginning of the substitution to its end, allowing for any 
 * recursion necessary to recognize embedded constructs, shall be included 
 * unmodified in the result token, including any embedded or enclosing 
 * substitution operators or quotes. The token shall not be delimited by the 
 * end of the substitution.
*/
t_none	lexer_fifth_rule(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;
	
	if (!lexer->is_quoted && lexer->cursor[0] == '$' && lexer->cursor[1] == '{')
	{
		lexer_delimit(mini);
		lexer_add_character(mini);
		while (lexer->cursor[0] != '}')
			lexer_add_character(mini);
		lexer_add_character(mini);
		lexer_delimit(mini);
		lexer->has_applied_rule = TRUE;
		printf("5h rule applied.\n");
	}
}
