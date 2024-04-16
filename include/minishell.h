/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:26:22 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/16 16:16:16 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "cstring.h"

# define PROMPT "minishell> "

typedef struct s_minishell_state	*t_minishell_state;

struct s_minishell_state {
	// t_memory_tree	memory_tree;
	t_cstring		command_line;
};


t_minishell_state	create_minishell_state(void);
t_minishell_state	allocate_minishell_state(void);
void				initialize_minishell_state(t_minishell_state minishell_state);
void				destroy_minishell_state(t_minishell_state minishell_state);
void				prompt_and_wait_for_input(t_minishell_state minishell_state);

// void	*minishell_allocate(
// 			t_minishell_state minishell_state,
// 			unsigned int size);
// void	minishell_deallocate(
// 			t_minishell_state minishell_state, 
// 			void *memory_address);

#endif