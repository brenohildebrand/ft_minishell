/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:05:27 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 22:06:06 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	parser_create(t_mini mini)
{
	mini->parser = mini_alloc(mini, sizeof(struct s_parser_context));
	mini->parser->whatever = 0;
}
