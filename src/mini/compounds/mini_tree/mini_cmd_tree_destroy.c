/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cmd_tree_destroy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:10:37 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/10 18:13:13 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_cmd_tree_destroy(t_mini mini, t_mini_cmd_tree tree)
{
	mini_list_destroy(mini, tree->words);
	mini_list_destroy(mini, tree->redirs);
	mini_free(tree);
}
