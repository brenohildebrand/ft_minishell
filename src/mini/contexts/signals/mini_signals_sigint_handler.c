/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_signals_sigint_handler.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:12 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/12 15:19:30 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_signals_sigint_handler(t_mini mini)
{
	(void)mini;
	mini_reset(mini);
}
