/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_next_quote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:51:07 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 14:41:38 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"
#include "types.h"

void	move_to_next_quote(
	t_cstring line,
	t_i32 *index,
	t_i32 *single_quote,
	t_i32 *double_quote
){
	if (line[*index] == '\'')
	{
		(*single_quote)++;
		(*index)++;
		while (line[*index] && line[*index] != '\'')
			(*index)++;
		if (line[*index] == '\'')
			(*single_quote)--;
	}
	if (line[*index] == '\"')
	{
		(*double_quote)++;
		(*index)++;
		while (line[*index] && line[*index] != '\"')
			(*index)++;
		if (line[*index] == '\"')
			(*double_quote)--;
	}
}
