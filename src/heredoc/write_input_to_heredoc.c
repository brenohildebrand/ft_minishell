/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_input_to_heredoc.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:49:38 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/16 21:27:58 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32	write_input_to_heredoc(
	t_minishell mini,
	int fd,
	char *end_condition,
	int is_expandable
){
	t_cstring	line;

	line = readline("> ");
	if (!line)
	{
		if (get_exit_status(mini) == SIGINT + 128)
			return (set_exit_status(mini, SIGINT + 128));
	}
	if (ft_strcmp(line, end_condition) == SUCCESS)
		return (SUCCESS);
	if (is_expandable)
		line = expand_vars(line);
	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
	free(line);
	return (FAILURE);
}