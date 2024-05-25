/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_context_new.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:13:38 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/25 18:23:18 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tokenizer_context	tokenizer_context_new(t_mini mini, t_cstring cursor)
{
	t_tokenizer_context	context;

	context = mini_alloc(mini, sizeof(struct s_tokenizer_context));
	context->start = 0;
	context->end = 0;
	context->cursor = cursor;
	context->mode = TOKENIZER_MODE_ORDINARY;
	context->completed = FALSE;
	return (context);
}
