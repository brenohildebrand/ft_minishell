/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_linked_list_node.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:05:22 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/16 19:08:22 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "linked_list.h"
#include "token.h"

void	destroy_linked_list_node(t_minishell mini, t_linked_list_node node)
{
	destroy_token(mini, node->value);
	mini_free(mini, node);
}
