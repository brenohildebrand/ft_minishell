/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_open_syntax.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:44:39 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/16 13:27:10 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "types.h"

t_i32	check_open_syntax(t_cstring line)
{
	t_i32	index;
	t_i32	brackets;
	t_i32	single_quote;
	t_i32	double_quote;

	index = 0;
	brackets = 0;
	single_quote = 0;
	double_quote = 0;
	while (line[index])
	{
		if (line[index] == '\'' || line[index] == '\"')
			move_to_next_quote(line, &index, &single_quote, &double_quote);
		if (line[index] == '(')
			brackets++;
		if (line[index] == ')')
			brackets--;
		index++;
	}
	if (brackets != 0 || single_quote != 0 || double_quote != 0)
		return (write(STDERR_FILENO, "Invalid syntax, check input for open \
quotes or brackets.\n", 58));
	return (SUCCESS);
}
