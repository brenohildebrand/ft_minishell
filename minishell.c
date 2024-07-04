/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:18:27 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/04 18:12:00 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shared	*shared_create(int argc, char **argv, char **envp)
{
	t_shared	*shared;

	shared = ft_malloc(sizeof(struct s_shared));
	shared->argc = argc;
	shared->argv = argv;
	shared->envp = envp;
	shared->is_statement_complete = FALSE;
	return (shared);
}

t_reader	*reader_create(void)
{
	t_reader	*reader;

	reader = ft_malloc(sizeof(struct s_reader));
	reader->line = NULL;
	reader->statement = NULL;
	return (reader);
}

void	automaton_create_table_2(t_automaton *automaton)
{
	automaton->table[5][7] = 200;
	automaton->table[6][0] = 105;
	automaton->table[6][1] = 105;
	automaton->table[6][2] = 105;
	automaton->table[6][3] = 105;
	automaton->table[6][4] = 105;
	automaton->table[6][5] = 105;
	automaton->table[6][6] = 105;
	automaton->table[6][7] = 105;
}

void	automaton_create_table_1(t_automaton *automaton)
{
	automaton->table[3][0] = 103;
	automaton->table[3][1] = 103;
	automaton->table[3][2] = 104;
	automaton->table[3][3] = 103;
	automaton->table[3][4] = 103;
	automaton->table[3][5] = 103;
	automaton->table[3][6] = 103;
	automaton->table[3][7] = 103;
	automaton->table[4][0] = 4;
	automaton->table[4][1] = 4;
	automaton->table[4][2] = 4;
	automaton->table[4][3] = 1;
	automaton->table[4][4] = 4;
	automaton->table[4][5] = 4;
	automaton->table[4][6] = 4;
	automaton->table[4][7] = 200;
	automaton->table[5][0] = 5;
	automaton->table[5][1] = 5;
	automaton->table[5][2] = 5;
	automaton->table[5][3] = 5;
	automaton->table[5][4] = 1;
	automaton->table[5][5] = 5;
	automaton->table[5][6] = 5;
	automaton_create_table_2(automaton);
}

void	automaton_create_table_0(t_automaton *automaton)
{
	automaton->table[0][0] = 1;
	automaton->table[0][1] = 2;
	automaton->table[0][2] = 3;
	automaton->table[0][3] = 4;
	automaton->table[0][4] = 5;
	automaton->table[0][5] = 6;
	automaton->table[0][6] = 0;
	automaton->table[0][7] = 108;
	automaton->table[1][0] = 1;
	automaton->table[1][1] = 100;
	automaton->table[1][2] = 100;
	automaton->table[1][3] = 4;
	automaton->table[1][4] = 5;
	automaton->table[1][5] = 100;
	automaton->table[1][6] = 100;
	automaton->table[1][7] = 100;
	automaton->table[2][0] = 101;
	automaton->table[2][1] = 102;
	automaton->table[2][2] = 101;
	automaton->table[2][3] = 101;
	automaton->table[2][4] = 101;
	automaton->table[2][5] = 101;
	automaton->table[2][6] = 101;
	automaton->table[2][7] = 101;
	automaton_create_table_1(automaton);
}

t_automaton	*automaton_create(void)
{
	t_automaton	*automaton;

	automaton = ft_malloc(sizeof(struct s_automaton));
	automaton->end = 0;
	automaton->list = NULL;
	automaton->state = 0;
	automaton->start = 0;
	automaton->status = SUCCESS;
	automaton->cursor = NULL;
	automaton_create_table_0(automaton);
}

t_lexer	*lexer_create(void)
{
	t_lexer	*lexer;

	lexer = ft_malloc(sizeof(struct s_lexer));
	lexer->automaton = automaton_create();
	return (lexer);

}

t_mini	*mini_create(int argc, char **argv, char **envp)
{
	t_mini	*mini;

	mini = ft_malloc(sizeof(struct s_mini));
	mini->shared = shared_create(argc, argv, envp);
	mini->reader = reader_create();
	mini->lexer = lexer_create();
}

char	*get_prompt(t_reader *reader)
{
	if (reader->statement == NULL)
		return (PROMPT);
	else
		return (MULTILINE_PROMPT);
}

void	read_line(t_reader *reader)
{
	reader->line = readline(get_prompt(reader));
}

int	is_eof(t_reader *reader)
{
	if (reader->line == NULL)
		return (TRUE);
	return (FALSE);
}

void	update_statement(t_reader *reader)
{
	char	*tmp;

	if (reader->statement)
		tmp = ft_strjoin(reader->statement, "\n");
	else
		tmp = ft_strjoin(reader->statement, reader->line);
	ft_free(reader->statement);
	reader->statement = tmp;
}

int	automaton_is_final_state(t_automaton *automaton)
{
	return (automaton->state >= 100);
}

int	automaton_should_consider_last_character(t_automaton *automaton)
{
	if (automaton->state == REDIR_APPEND_FS)
		return (TRUE);
	else if (automaton->state == REDIR_HEREDOC_FS)
		return (TRUE);
	return (FALSE);
}

int	automaton_typefy(t_automaton *automaton)
{
	if (automaton->state == WORD_FS)
		return (WORD);
	else if (automaton->state == REDIR_OUT_FS)
		return (REDIR_OUT);
	else if (automaton->state == REDIR_APPEND_FS)
		return (REDIR_APPEND);
	else if (automaton->state == REDIR_IN_FS)
		return (REDIR_IN);
	else if (automaton->state == REDIR_HEREDOC_FS)
		return (REDIR_HEREDOC);
	else if (automaton->state == PIPE_FS)
		return (PIPE);
	ft_putstr_fd("mini: automaton: fatal error\n", STDERR_FILENO);
	ft_exit(1);
	return (0);
}

t_token	*token_new(char *str, int type)
{
	t_token	*token;

	token = ft_malloc(sizeof(struct s_token));
	token->token = str;
	token->type = type;
	return (token);
}

void	token_del(void *content)
{
	t_token	*token;

	token = (t_token *)content;
	ft_free(token->token);
	ft_free(token);
}

void	automaton_reset(t_automaton *automaton, char *statement)
{
	automaton->end = 0;
	automaton->state = 0;
	automaton->start = 0;
	automaton->status = SUCCESS;
	automaton->cursor = statement;
	ft_lstclear(&automaton->list, token_del);
}

void	automaton_delimit_with_last_char(t_automaton *automaton)
{
	ssize_t	len;
	char	*str;
	int		type;

	len = automaton->end - automaton->start + 1;
	str = ft_strndup(automaton->cursor + automaton->start, len);
	type = automaton_typefy(automaton);
	ft_lstadd_back(&automaton->list, ft_lstnew(token_new(str, type)));
	automaton->end += 1;
	automaton->start = automaton->end;
	automaton->state = 0;
}

void	automaton_delimit_without_last_char(t_automaton *automaton)
{
	ssize_t	len;
	char	*str;
	int		type;

	len = automaton->end - automaton->start;
	str = ft_strndup(automaton->cursor + automaton->start, len);
	type = automaton_typefy(automaton);
	ft_lstadd_back(&automaton->list, ft_lstnew(token_new(str, type)));
	automaton->start = automaton->end;
	automaton->state = 0;
}

void	automaton_delimit(t_automaton *automaton)
{
	if (automaton->state == EMPTY_FS)
		return ;
	if (automaton_should_consider_last_character(automaton))
		automaton_delimit_with_last_char(automaton);
	else
		automaton_delimit_without_last_char(automaton);
}

void	automaton_exit(t_automaton *automaton)
{
	while (*automaton->cursor != '\0')
		automaton->cursor++;
}

void	automaton_eval_final_state(t_automaton *automaton)
{
	if (automaton->state == INCOMPLETE_FS)
	{
		automaton->status = FAILURE;
		automaton_exit(automaton);
	}
	else
	{
		automaton_delimit(automaton);
	}
}

void	automaton_eval_state(t_automaton *automaton)
{
	if (automaton_is_final_state(automaton))
		automaton_eval_final_state(automaton);
	else
	{
		if (automaton->state == WHITESPACE_S)
			automaton->start += 1;
		automaton->end += 1;
	}
}

void	automaton_next_state(t_automaton *automaton)
{
	const char	c = automaton->cursor[automaton->end];

	if (c == '>')
		automaton->state = automaton->table[automaton->state][1];
	else if (c == '<')
		automaton->state = automaton->table[automaton->state][2];
	else if (c == '"')
		automaton->state = automaton->table[automaton->state][3];
	else if (c == '\'')
		automaton->state = automaton->table[automaton->state][4];
	else if (c == '|')
		automaton->state = automaton->table[automaton->state][5];
	else if (c == ' ' || (c >= '\t' && c <= '\r'))
		automaton->state = automaton->table[automaton->state][6];
	else if (c == '\0')
		automaton->state = automaton->table[automaton->state][7];
	else
		automaton->state = automaton->table[automaton->state][0];
}

void	automaton_subprocess(t_automaton *automaton, char *statement)
{
	automaton_reset(automaton, statement);
	while (*automaton->cursor != '\0' && automaton->state != INCOMPLETE_FS)
	{
		automaton_next_state(automaton);
		automaton_eval_state(automaton);
	}
}

void	lexer_process(t_mini *mini)
{
	automaton_subprocess(mini->lexer->automaton, mini->reader->statement);
	if (mini->lexer->automaton->status == FAILURE)
		mini->shared->is_statement_complete = FALSE;
}

void	expansion_process(t_mini *mini)
{
	// ft_lstiter(mini->lexer->tokens, expansion_env);
	// ft_lstiter(mini->lexer->tokens, expansion_rm_quotes);
}

void	parser_process(t_mini *mini)
{
	(void)mini;
}

void	reader_process(t_mini *mini)
{
	read_line(mini->reader);
	if (is_eof(mini->reader))
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		ft_exit(mini->shared->status);
	}
	update_statement(mini->reader);
}

void	read_statement(t_mini *mini)
{
	while (42)
	{
		mini->shared->is_statement_complete = TRUE;
		if (mini->shared->is_statement_complete)
			reader_process(mini);
		if (mini->shared->is_statement_complete)
			lexer_process(mini);
		if (mini->shared->is_statement_complete)
			expansion_process(mini);
		if (mini->shared->is_statement_complete)
			parser_process(mini);
		if (mini->shared->is_statement_complete)
			break	;
	}
}

void	eval_statement(t_mini *mini)
{
	// heredoc_process(mini);
	// redirect_process(mini);
	// evaluation_process(mini);
}

void	shared_reset(t_shared *shared)
{
	(void)shared;
}

void	mini_reset(t_mini *mini)
{
	shared_reset(mini->shared);
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	*mini;

	mini = mini_create(argc, argv, envp);
	while (42)
	{
		read_statement(mini);
		eval_statement(mini);
		mini_reset(mini);
	}
}
