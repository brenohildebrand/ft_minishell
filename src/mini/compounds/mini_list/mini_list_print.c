/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_list_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:02:42 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/16 18:03:12 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_list_print(t_mini mini)
{
	t_mini_list	list;

	list = mini->lexer->tokens;
	while (list)
	{
		printf("%s", list->token);
		if (list->next)
			printf(", ");
		list = list->next;
	}
	printf("\n");
}
