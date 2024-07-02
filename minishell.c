/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:18:27 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/02 19:11:48 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32	ft_strlen(t_cstring cstr)
{
	t_i32	len;

	len = 0;
	while (cstr[len] != '\0')
	{
		len++;
	}
	return (len);
}

t_mini	print_to_stderr(t_cstring cstr)
{
	write(STDERR_FILENO, cstr, ft_strlen(cstr));
}

t_none	signals_create(t_mini mini)
{

}

t_none	create_internal_structures(
	t_mini mini, 
	t_i32 argc, 
	t_i8 **argv, 
	t_i8 **envp
){
	signals_create(mini);
	// create_signals(mini);
	// create_reader(mini);
	// create_lexer(mini);
	// create_expansion(mini);
	// create_parser(mini);
	// create_heredoc(mini);
	// create_eval(mini);
}

t_mini	mini_create(t_i32 argc, t_i8 **argv, t_i8 **envp)
{
	t_mini	mini;

	mini = malloc(sizeof(struct s_mini));
	if (mini == NULL)
	{
		print_to_stderr("Error: Failed to allocate memory for mini\n");
		exit(MINI_ERROR);
	}
	create_internal_structures(mini, argc, argv, envp);
	return (mini);
}

t_i32	main(t_i32 argc, t_i8 **argv, t_i8 **envp)
{
	t_mini	mini;

	printf("This is MINI! I'm going to finish this!\n");
	mini = mini_create(argc, argv, envp);
	// while (42)
	// {
	// 	while (mini_is_complete(mini))
	// 	{
	// 		mini_read(mini);
	// 		mini_tokenize(mini);
	// 		mini_expand(mini);
	// 		mini_parse(mini);
	// 	}
	// 	mini_handle_heredoc(mini);
	// 	mini_eval(mini);
	// 	mini_reset(mini);
	// }
}
