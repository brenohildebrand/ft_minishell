/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:00:54 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 22:19:26 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_LIST_H
# define MINI_LIST_H

typedef struct s_mini_list	*t_mini_list;

struct s_mini_list {
	t_mini_list	next;
	t_mini_list	previous;
	t_cstring	token;
	t_i32		type;
};

enum e_mini_token_type {
	REDIR_IN,
	REDIR_OUT,
	REDIR_HEREDOC,
	REDIR_APPEND,
	PIPE,
	DOUBLE_QUOTES,
	SINGLE_QUOTES,
	WORD,
};

t_none	mini_list_append(
			t_mini mini,
			t_mini_list *list,
			t_cstring token,
			t_i32 type);
t_none	mini_list_clear(t_mini mini, t_mini_list *list);

#endif