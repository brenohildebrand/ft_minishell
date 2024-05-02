/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:28:57 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/02 14:34:51 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "types.h"

t_i32	get_token_type(t_cstring line)
{
	if (ft_strncmp(line, "&&", 2) == 0)
		return (AND);
	else if (ft_strncmp(line, "||", 2) == 0)
		return (OR);
	else if (ft_strncmp(line, "|", 1) == 0)
		return (PIPE);
	else if (ft_strncmp(line, "(", 1) == 0)
		return (OPEN_PAREN);
	else if (ft_strncmp(line, ")", 1) == 0)
		return (CLOSE_PAREN);
	else if (ft_strncmp(line, ">>", 2) == 0)
		return (REDIR_APPEND);
	else if (ft_strncmp(line, "<<", 2) == 0)
		return (REDIR_HEREDOC);
	else if (ft_strncmp(line, "<", 1) == 0)
		return (REDIR_IN);
	else if (ft_strncmp(line, ">", 1) == 0)
		return (REDIR_OUT);
	else if (ft_strncmp(line, " ", 1) == 0)
		return (SPACES);
	else if (ft_strncmp(line, "\0", 1) == 0)
		return (END);
	else
		return (WORD);
}
