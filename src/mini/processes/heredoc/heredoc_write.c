/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:34:10 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 23:04:21 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	heredoc_write(t_mini mini)
{
	t_cstring	filename;
	t_cstring	filepath;
	t_i32		fd;
	t_i32		bytes_written;

	filename = cstring_join(mini, cstring_copy(mini, "mini.heredoc."), u8_to_cstring(mini, mini->heredoc->counter++));
	filepath = cstring_join(mini, cstring_copy(mini, "/tmp/"), filename);
	fd = open(filepath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	mini_assert(mini, fd != -1, MINI_ERROR);
	bytes_written = write(fd, mini->heredoc->buffer, cstring_get_length(mini->heredoc->buffer));
	if (bytes_written == -1 || bytes_written != cstring_get_length(mini->heredoc->buffer))
		close(fd);
	mini_assert(mini, bytes_written != -1, MINI_ERROR);
	mini_assert(mini, bytes_written == cstring_get_length(mini->heredoc->buffer), MINI_ERROR);
	close(fd);
	mini_free(mini, filepath);
}
