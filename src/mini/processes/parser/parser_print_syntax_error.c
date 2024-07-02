/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_print_syntax_error.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:34:42 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/01 10:34:33 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	parser_print_syntax_error(t_mini mini)
{
	cstring_to_stderr("mini: syntax error near unexpected token '");
	cstring_to_stderr(mini->parser->unexpected_token);
	cstring_to_stderr("'\n");
}
