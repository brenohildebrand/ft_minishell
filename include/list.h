/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:52:48 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/20 20:18:19 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "minishell.h"

typedef struct s_list		*t_list;
typedef struct s_list_node	*t_list_node;

struct s_list {
	t_list	head;
	t_list	tail;
};

struct s_list_node {
	t_list_node	next;
	t_list_node	previous;	
	t_any		value;
};

#endif