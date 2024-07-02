/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 07:31:42 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:09:50 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	reader_debug(t_mini mini)
{
	printf("\033[94m[%s:%d]\n(statement)\033[0m %s\n", __func__, __LINE__, mini->reader->statement);
}
