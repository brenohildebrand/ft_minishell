/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokenizer_ninth_rule.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:35:42 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/25 20:36:36 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * 9th rule:
 * If the current character is a '#', it and all subsequent characters up to,
 * but excluding, the next <newline> shall be discarded as a comment. The
 * <newline> that ends the line is not considered part of the comment.
*/
t_none	mini_tokenizer_ninth_rule(t_mini mini, t_tokenizer_context context)
{
	(void)mini;
	(void)context;
}
