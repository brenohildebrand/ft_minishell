/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_context_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:56:22 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/27 12:59:02 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_context_init(t_mini mini, t_i32 argc, t_cstring *argv)
{
	const t_mini_context	context = mini->mini_context;

	context->argc = argc;
	context->argv = argv;
}
