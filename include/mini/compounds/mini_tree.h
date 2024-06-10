/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tree.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:36:54 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/10 15:10:24 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TREE_H
# define MINI_TREE_H

# include "minishell.h"

typedef struct s_mini_tree	*t_mini_tree;

struct s_mini_tree {
	t_mini_tree	parent;
	t_mini_tree	*children;
	t_i32		size;
	t_any		data;
	t_i32		type;
};

enum e_mini_tree_type {
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_HEREDOC,
	REDIR_APPEND,
	FILENAME,
	COMMAND,
};

t_mini_tree	mini_tree_create(t_mini mini);
t_none		mini_tree_destroy(t_mini mini, t_mini_tree tree);

#endif