/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tree.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:36:54 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/10 18:15:50 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TREE_H
# define MINI_TREE_H

# include "minishell.h"

typedef struct s_mini_pipe_sequence_tree	*t_mini_pipe_sequence_tree;
typedef t_mini_pipe_sequence_tree			t_mini_pipe_tree;

typedef struct s_mini_command_tree			*t_mini_command_tree;
typedef t_mini_command_tree					t_mini_cmd_tree;

struct s_mini_pipe_sequence_tree {
	t_mini_command_tree	*commands;
};

struct s_mini_command_tree {
	t_mini_list	words;
	t_mini_list	redirs;
};

t_mini_pipe_tree	mini_pipe_tree_create(t_mini mini);
t_none				mini_pipe_tree_destroy(t_mini mini, t_mini_pipe_tree tree);
t_none				mini_pipe_tree_append_command(
						t_mini mini,
						t_mini_pipe_tree tree,
						t_mini_cmd_tree command);

t_mini_cmd_tree		mini_cmd_tree_create(t_mini mini);
t_none				mini_cmd_tree_destroy(t_mini mini, t_mini_cmd_tree tree);

#endif