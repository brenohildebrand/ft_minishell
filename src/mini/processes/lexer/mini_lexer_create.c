/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lexer_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 00:20:02 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/11 00:49:25 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_none	next2(t_mini mini)
{
	mini->lexer->table[6][0] = 105;
	mini->lexer->table[6][1] = 105;
	mini->lexer->table[6][2] = 105;
	mini->lexer->table[6][3] = 105;
	mini->lexer->table[6][4] = 105;
	mini->lexer->table[6][5] = 105;
	mini->lexer->table[6][6] = 105;
	mini->lexer->table[6][7] = 200;
}

static t_none	next1(t_mini mini)
{
	mini->lexer->table[3][0] = 103;
	mini->lexer->table[3][1] = 103;
	mini->lexer->table[3][2] = 104;
	mini->lexer->table[3][3] = 103;
	mini->lexer->table[3][4] = 103;
	mini->lexer->table[3][5] = 103;
	mini->lexer->table[3][6] = 103;
	mini->lexer->table[3][7] = 103;
	mini->lexer->table[4][0] = 4;
	mini->lexer->table[4][1] = 4;
	mini->lexer->table[4][2] = 4;
	mini->lexer->table[4][3] = 1;
	mini->lexer->table[4][4] = 4;
	mini->lexer->table[4][5] = 4;
	mini->lexer->table[4][6] = 4;
	mini->lexer->table[4][7] = 200;
	mini->lexer->table[5][0] = 5;
	mini->lexer->table[5][1] = 5;
	mini->lexer->table[5][2] = 5;
	mini->lexer->table[5][3] = 5;
	mini->lexer->table[5][4] = 1;
	mini->lexer->table[5][5] = 5;
	mini->lexer->table[5][6] = 5;
	mini->lexer->table[5][7] = 200;
	next2(mini);
}

static t_none	next0(t_mini mini)
{
	mini->lexer->table[0][0] = 1;
	mini->lexer->table[0][1] = 2;
	mini->lexer->table[0][2] = 3;
	mini->lexer->table[0][3] = 4;
	mini->lexer->table[0][4] = 5;
	mini->lexer->table[0][5] = 6;
	mini->lexer->table[0][6] = 0;
	mini->lexer->table[0][7] = 108;
	mini->lexer->table[1][0] = 1;
	mini->lexer->table[1][1] = 100;
	mini->lexer->table[1][2] = 100;
	mini->lexer->table[1][3] = 4;
	mini->lexer->table[1][4] = 5;
	mini->lexer->table[1][5] = 100;
	mini->lexer->table[1][6] = 100;
	mini->lexer->table[1][7] = 100;
	mini->lexer->table[2][0] = 101;
	mini->lexer->table[2][1] = 102;
	mini->lexer->table[2][2] = 101;
	mini->lexer->table[2][3] = 101;
	mini->lexer->table[2][4] = 101;
	mini->lexer->table[2][5] = 101;
	mini->lexer->table[2][6] = 101;
	mini->lexer->table[2][7] = 101;
	next1(mini);
}

t_none	mini_lexer_create(t_mini mini)
{
	mini->lexer = mini_alloc(mini, sizeof(struct s_lexer_process));
	mini->lexer->tokens = NULL;
	mini->lexer->cursor = NULL;
	mini->lexer->start = 0;
	mini->lexer->end = 0;
	mini->lexer->state = 0;
	next0(mini);
}
