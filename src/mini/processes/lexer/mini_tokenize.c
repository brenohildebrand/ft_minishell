/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokenize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:07:35 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/17 13:59:38 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_tokenize(t_mini mini)
{
	mini_lexer_automaton(mini);
	printf("\033[94m[%s:%d]\n(tokens)\033[0m ", __func__, __LINE__);
	mini_list_print(mini);
}
