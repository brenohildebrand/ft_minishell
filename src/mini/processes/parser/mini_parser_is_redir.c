/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parser_is_redir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:55:51 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/10 22:22:36 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	mini_parser_is_redir(t_mini mini)
{
	if (mini_parser_get_token(mini) == REDIR_IN)
		return (TRUE);
	else if (mini_parser_get_token(mini) == REDIR_OUT)
		return (TRUE);
	else if (mini_parser_get_token(mini) == REDIR_APPEND)
		return (TRUE);
	else if (mini_parser_get_token(mini) == REDIR_HEREDOC)
		return (TRUE);
	return (FALSE);	
}
