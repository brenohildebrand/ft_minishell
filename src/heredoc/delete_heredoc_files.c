/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_heredoc_files.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:46:52 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/16 20:48:50 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32	delete_heredoc_files(t_minishell mini)
{
	t_cstring	file_name;
	t_i32		*counter;

	heredoc_counter = get_heredoc_counter();
	while ((*heredoc_counter) >= 0)
	{
		file_name = mini_strjoin(mini, "/tmp/.heredoc", ft_itoa((*heredoc_counter)--));
		unlink(file_name);
	}
	return (SUCCESS);
}
