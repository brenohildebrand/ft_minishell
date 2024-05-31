/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_context_new.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:13:38 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/25 18:23:18 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_lexer_context	lexer_context_new(t_mini mini)
{
	t_lexer_context	context;

	context = mini_alloc(mini, sizeof(struct s_lexer_context));
	return (context);
}
