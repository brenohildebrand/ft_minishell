/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_subcstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:29:40 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 14:41:38 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"
#include "lexer.h"

t_cstring	get_subcstring(
	t_minishell mini, 
	t_cstring line, 
	t_i32 start, 
	t_i32 length
){
	t_cstring	subcstring;
	
	subcstring = mini_alloc(mini, length + 1);
	subcstring[length] = '\0';
	while (length--)
	{
		subcstring[length] = line[start + length];
	}
	return (subcstring);
}
