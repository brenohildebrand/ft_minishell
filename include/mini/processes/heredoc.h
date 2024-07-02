/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:38:33 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:49:32 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "minishell.h"

typedef struct s_heredoc_process	*t_heredoc_process;
typedef t_heredoc_process			t_heredoc;

struct s_heredoc_process {
	t_mini_list				redirs;
	t_cstring				buffer;
	t_i32					counter;
};

t_none	heredoc_create(t_mini mini);
t_none	heredoc_reset(t_mini mini);

t_none	mini_handle_heredoc(t_mini mini);
t_none	heredoc_read(t_mini mini);
t_none	heredoc_write(t_mini mini);
t_none	heredoc_update_tree(t_mini mini);

#endif