/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_create_multiline_prompt.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:38:37 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:09:31 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	reader_create_multiline_prompt(t_mini mini)
{
	mini->reader->multiline_prompt = MULTILINE_PROMPT;
}
