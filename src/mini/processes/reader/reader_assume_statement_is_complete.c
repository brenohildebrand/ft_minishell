/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_assume_statement_is_complete.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:50:53 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:09:15 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "minishell.h"

t_none	reader_assume_statement_is_complete(t_mini mini)
{
	mini->shared->is_statement_complete = TRUE;
}
