/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heredoc_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:37:05 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/20 12:05:27 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "token.h"

t_i32	create_heredoc_file(t_minishell mini, t_token token)
{
	static t_i32	counter = 0;
	t_i32			fd;
	t_i32			is_expandable;
	t_cstring		file_name;

	// setup_signal_handler(heredoc_signal_handler);
	is_expandable = 0;
	file_name = mini_strjoin(mini, "/tmp/.heredoc", ft_itoa(counter));
	counter++;
	fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
		return (set_exit_status(handle_error("failed to create heredoc")));
	if (!ft_strchr(token->value, '\"') && !ft_strchr(token->value, '\''))
		is_expandable = 1;
	token->value = remove_quotes(token->value);
	while (42)
		if (write_input_to_heredoc(fd, token->value, is_expandable) == SUCCESS)
			break ;
	if (*get_exit_status() == SIGINT + 128)
		return (set_exit_status(SIGINT + 128));
	close(fd);
	token->value = file_name;
	return (SUCCESS);
}
