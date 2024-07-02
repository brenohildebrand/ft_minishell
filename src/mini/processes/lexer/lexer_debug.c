/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 07:33:11 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:14:11 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	lexer_debug(t_mini mini)
{
	printf("\033[94m[%s:%d]\n(tokens)\033[0m ", __func__, __LINE__);
	mini_list_print(mini);
}
