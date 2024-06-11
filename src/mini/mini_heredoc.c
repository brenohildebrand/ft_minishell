/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:28:33 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/11 18:27:48 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_heredoc(t_mini mini)
{
	(void)mini;
	if (!mini->shared->is_heredoc_complete)
	{
		printf("TODO: implement mini_heredoc. Aborting.\n");
		mini_quit(mini, 0);
		
		// percorre os redir de cada comando na orderm q aparece
		// se for heredoc 
		// 	le as linhas e vai salvando num buffer
		//	ate achar delimiter\n
		//	escreve o resultado num arquivo temporario
		//  substitui o delimiter com o nome do arquivo temporario
		// cabou
	}
}
