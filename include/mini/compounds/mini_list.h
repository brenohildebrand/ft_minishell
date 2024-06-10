/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:00:54 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/10 17:59:43 by bhildebr         ###   ########.fr       */
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

enum e_mini_list_type {
	MINI_LIST_PIPE,
	MINI_LIST_REDIR_IN,
	MINI_LIST_REDIR_OUT,
	MINI_LIST_REDIR_HEREDOC,
	MINI_LIST_REDIR_APPEND,
	MINI_LIST_DOUBLE_QUOTES,
	MINI_LIST_SINGLE_QUOTES,
	MINI_LIST_WORD,
	MINI_LIST_END
};

t_mini_list	mini_list_create(t_mini mini);
t_none		mini_list_destroy(t_mini mini, t_mini_list list);

t_none	mini_list_append(
			t_mini mini,
			t_mini_list *list,
			t_cstring token,
			t_i32 type);
t_none	mini_list_clear(t_mini mini, t_mini_list *list);

#endif