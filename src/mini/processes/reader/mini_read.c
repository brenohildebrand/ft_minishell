/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:23:30 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/16 17:51:15 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_read(t_mini mini)
{
	mini_reader_readline(mini);
	mini_reader_update_statement(mini);
	mini_reader_assume_statement_is_complete(mini);
	printf("\033[94m[%s:%d]\n(statement)\033[0m %s\n", __func__, __LINE__, mini->reader->statement);
}
