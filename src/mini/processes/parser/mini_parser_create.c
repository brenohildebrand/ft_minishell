/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parser_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 00:28:15 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 00:29:19 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_parser_create(t_mini mini)
{
	mini->parser = mini_alloc(mini, sizeof(struct s_parser_process));
	mini->parser->tree = NULL;
}
