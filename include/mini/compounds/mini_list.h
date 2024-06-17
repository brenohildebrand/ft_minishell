/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:00:54 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/17 13:57:02 by bhildebr         ###   ########.fr       */
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
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_HEREDOC,
	REDIR_APPEND,
	DOUBLE_QUOTES,
	SINGLE_QUOTES,
	WORD,
	END
};

t_mini_list	mini_list_create(t_mini mini);
t_none		mini_list_destroy(t_mini mini, t_mini_list *list);

t_none	mini_list_append(
			t_mini mini,
			t_mini_list *list,
			t_cstring token,
			t_i32 type);
t_none	mini_list_clear(t_mini mini, t_mini_list *list);
t_none	mini_list_print(t_mini mini);

#endif