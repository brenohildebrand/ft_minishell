/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_reset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:55:00 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 23:03:05 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	heredoc_reset(t_mini mini)
{
	t_cstring	filename;
	t_cstring	filepath;

	while (mini->heredoc->counter > 0)
	{
		filename = cstring_join(mini, cstring_copy(mini, "mini.heredoc."), u8_to_cstring(mini, --mini->heredoc->counter));
		filepath = cstring_join(mini, cstring_copy(mini, "/tmp/"), filename);
		mini_assert(mini, unlink(filepath) != 0, MINI_ERROR);
	}
}
