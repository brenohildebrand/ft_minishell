/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parser_next_token.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:40:18 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/10 14:40:59 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_parser_next_token(t_mini mini)
{
	if (mini->parser->cursor == NULL)
		return ;
	mini->parser->cursor = mini->parser->cursor->next;
}
