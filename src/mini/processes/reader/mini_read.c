/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:23:30 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:40:57 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_read(t_mini mini)
{
	reader_readline(mini);
	reader_update_statement(mini);
	reader_assume_statement_is_complete(mini);
	reader_debug(mini);
}
