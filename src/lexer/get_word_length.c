/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:35:15 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/02 14:40:41 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "types.h"

t_i32	get_word_length(t_cstring line)
{
	t_i32	len;

	len = 0;
	while (get_token_type(line + len) == WORD)
	{
		if (line[len] == '\'')
		{
			len++;
			while (line[len] != '\'')
				len++;
		}
		if (line[len] == '\"')
		{
			len++;
			while (line[len] != '\"')
				len++;
		}
		len++;
	}
	return (len);
}
