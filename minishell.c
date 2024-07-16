/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:18:27 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/13 01:24:23 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_table	*shared_create_env(char **envp)
{
	t_table	*env;
	char	**split;
	int		i;

	env = ft_tblnew();
	i = 0;
	while (envp[i])
	{
		split = ft_split(envp[i], '=');
		ft_tblset(env, split[0], split[1]);
		ft_free(split);
		i++;
	}
	return (env);
}

t_shared	*shared_create(int argc, char **argv, char **envp)
{
	t_shared	*shared;

	shared = ft_malloc(sizeof(struct s_shared));
	shared->argc = argc;
	shared->argv = argv;
	shared->envp = envp;
	shared->env = shared_create_env(envp);
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
	automaton->tokens = NULL;
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

t_rdp	*rdp_create(void)
{
	t_rdp	*rdp;

	rdp = ft_malloc(sizeof(struct s_rdp));
	rdp->node = NULL;
	rdp->token = NULL;
	rdp->status = SUCCESS;
	return (rdp);
}

t_parser	*parser_create(void)
{
	t_parser	*parser;

	parser = ft_malloc(sizeof(struct s_parser));
	parser->cmds = NULL;
	parser->rdp = rdp_create();
	return (parser);
}

t_heredoc	*heredoc_create(void)
{
	t_heredoc	*heredoc;

	heredoc = ft_malloc(sizeof(struct s_heredoc));
	heredoc->delimiter = NULL;
	heredoc->heredoc = NULL;
	heredoc->counter = 0;
	return (heredoc);
}

t_mini	*mini_create(int argc, char **argv, char **envp)
{
	t_mini	*mini;

	mini = ft_malloc(sizeof(struct s_mini));
	mini->shared = shared_create(argc, argv, envp);
	mini->reader = reader_create();
	mini->lexer = lexer_create();
	mini->parser = parser_create();
	mini->heredoc = heredoc_create();
	return (mini);
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
	token->str = str;
	token->type = type;
	return (token);
}

void	token_del(void *content)
{
	t_token	*token;

	token = (t_token *)content;
	ft_free(token->str);
	ft_free(token);
}

void	automaton_reset(t_automaton *automaton, char *statement)
{
	automaton->end = 0;
	automaton->state = 0;
	automaton->start = 0;
	automaton->status = SUCCESS;
	automaton->cursor = statement;
	ft_lstclear(&automaton->tokens, token_del);
}

void	automaton_delimit_with_last_char(t_automaton *automaton)
{
	ssize_t	len;
	char	*str;
	int		type;

	len = automaton->end - automaton->start + 1;
	str = ft_strndup(automaton->cursor + automaton->start, len);
	type = automaton_typefy(automaton);
	ft_lstadd_back(&automaton->tokens, ft_lstnew(token_new(str, type)));
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
	ft_lstadd_back(&automaton->tokens, ft_lstnew(token_new(str, type)));
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
	while (automaton->cursor[automaton->end] != '\0')
		automaton->end++;
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

int	automaton_is_end_of_statement(t_automaton *automaton)
{
	if (automaton->cursor[automaton->end] == '\0')
		return (TRUE);
	if (automaton->state == INCOMPLETE_FS)
		return (TRUE);
	return (FALSE);
}

void	automaton_subprocess(t_automaton *automaton, char *statement)
{
	automaton_reset(automaton, statement);
	while (!automaton_is_end_of_statement(automaton))
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

int	expansion_sub_env_get_end(t_token *token, int i)
{
	int	end;
	
	end = (ft_strpbrk(token->str + i, "><\"'| \t\n\v\f\r\0") - token->str) - 1;
	return (end);
}

char	*mini_getenv(t_mini *mini, char *key)
{
	if (ft_strcmp(key, "?") == 0)
		return (ft_itoa(mini->shared->status));
	return (ft_strdup(ft_tblget(mini->shared->env, key)));
}

char	*expansion_sub_env_get_env(
	t_mini *mini,
	t_token *token,
	int start,
	int end
){
	char	*tmp;
	char	*env;

	tmp = ft_strndup(token->str + start + 1, end - start);
	env = mini_getenv(mini, tmp);
	ft_free(tmp);
	return (env);
}

void	expansion_sub_env(t_mini *mini, t_token *token)
{
	int			start;
	int			end;
	char		*env;
	char		*new_str;
	int			i;

	i = 0;
	while (token->str[i])
	{
		if (token->str[i] == '$')
		{
			start = i;
			end = expansion_sub_env_get_end(token, i);
			env = expansion_sub_env_get_env(mini, token, start, end);
			new_str = ft_strrep(token->str, env, start, end);
			token->str = new_str;
			ft_free(new_str);
			i = start + ft_strlen(env);
			ft_free(env);
		}
		i++;
	}
}

void	expansion_rm_sq(t_token *token, int i, int *is_in_sq, int *is_in_dq)
{
	char	*new_str;

	if ((*is_in_sq) || !(*is_in_dq))
	{
		*is_in_sq = !(*is_in_sq);
		new_str = ft_strrep(token->str, "", i, i);
		ft_free(token->str);
		token->str = new_str;
	}
}

void	expansion_rm_dq(t_token *token, int i, int *is_in_sq, int *is_in_dq)
{
	char	*new_str;

	if ((*is_in_dq) || !(*is_in_sq))
	{
		*is_in_dq = !(*is_in_dq);
		new_str = ft_strrep(token->str, "", i, i);
		ft_free(token->str);
		token->str = new_str;
	}
}

void	expansion_rm_quotes(t_token *token)
{
	int		is_in_sq;
	int		is_in_dq;
	int		i;
	char	*new_str;

	is_in_sq = FALSE;
	is_in_dq = FALSE;
	i = 0;
	while (token->str[i])
	{
		if (token->str[i] == '\'')
			expansion_rm_sq(token, i, &is_in_sq, &is_in_dq);
		if (token->str[i] == '"')
			expansion_rm_dq(token, i, &is_in_sq, &is_in_dq);
		i++;
	}
}

void	expansion_process(t_mini *mini)
{
	t_list	*node;
	t_token	*token;

	node = mini->lexer->automaton->tokens;
	while (node)
	{
		token = (t_token *)node->content;
		if (token->type == WORD)
		{
			expansion_sub_env(mini, token);
			expansion_rm_quotes(token);		
		}
		node = node->next;
	}
}

int	rdp_is_word(t_rdp *rdp)
{
	t_token	*token;

	token = (t_token *)rdp->node->content;
	if (token->type == WORD)
		return (TRUE);
	else if (token->type == DOUBLE_QUOTES)
		return (TRUE);
	else if (token->type == SINGLE_QUOTES)
		return (TRUE);
	return (FALSE);
}

int	rdp_is_redir(t_rdp *rdp)
{
	t_token	*token;

	token = (t_token *)rdp->node->content;
	if (token->type == REDIR_OUT)
		return (TRUE);
	else if (token->type == REDIR_APPEND)
		return (TRUE);
	else if (token->type == REDIR_IN)
		return (TRUE);
	else if (token->type == REDIR_HEREDOC)
		return (TRUE);
	return (FALSE);
}

int	rdp_is_pipe(t_rdp *rdp)
{
	t_token	*token;

	token = (t_token *)rdp->node->content;
	if (token->type == PIPE)
		return (TRUE);
	return (FALSE);
}

void	rdp_next_token(t_rdp *rdp)
{
	rdp->node = rdp->node->next;
}

int	rdp_command(t_mini *mini, t_rdp *rdp)
{
	while (rdp_is_word(rdp) || rdp_is_redir(rdp))
		rdp_next_token(rdp);
	return (SUCCESS);
}

int	rdp_pipe_sequence(t_mini *mini, t_rdp *rdp)
{
	if (rdp_command(mini, rdp) == SUCCESS)
	{
		while(rdp_is_pipe(rdp))
		{
			rdp_next_token(rdp);
			if (rdp->token == NULL)
				return (INCOMPLETE);
			if (rdp_command(mini, rdp) == FAILURE)
				return (FAILURE);
		}
		if (rdp->token == NULL)
			return (SUCCESS);
		else
			return (FAILURE);
	}
	else
		return (FAILURE);
}

void	rdp_reset(t_rdp *rdp)
{
	(void)rdp;
}

void	rdp_print_syntax_error(t_rdp *rdp)
{
	(void)rdp;
}

void	rdp_subprocess(t_mini *mini)
{
	t_rdp *const	rdp = mini->parser->rdp;

	rdp_reset(rdp);
	rdp->status = rdp_pipe_sequence(mini, rdp);
	if (rdp->status == SUCCESS)
		return ;
	else if (rdp->status == INCOMPLETE)
	{
		mini->shared->is_statement_complete = FALSE;
	}
	else if (rdp->status == FAILURE)
	{
		rdp_print_syntax_error(rdp);
		mini_reset(mini);
	}
}

void	cmds_build_command(t_mini *mini, t_list **node)
{
	t_command	*cmd;
	t_token		*token;
	t_redirect	*rdrct;

	token = (t_token *)((*node)->content);
	while (token->type >= WORD && token->type <= REDIR_OUT)
	{
		if (token->type == WORD)
			ft_lstadd_back(&cmd->argv, ft_lstnew(ft_strdup(token->str)));
		else
		{
			rdrct = ft_malloc(sizeof(struct s_redirect));
			rdrct->type = token->type;
			*node = (*node)->next;
			token = (t_token *)((*node)->content);
			rdrct->file = ft_strdup(token->str);
			ft_lstadd_back(&cmd->rdrcts, ft_lstnew(rdrct));
		}
		*node = (*node)->next;
		token = (t_token *)((*node)->content);
	}
	ft_lstadd_back(&mini->parser->cmds, ft_lstnew(cmd));
}

void	cmds_subprocess(t_mini *mini)
{
	t_list	*node;

	node = mini->lexer->automaton->tokens;
	while (node)
	{
		cmds_build_command(mini, &node);
		node = node->next;
	}
}

/**
 * @brief Applies a recursive descent parser (rdp) algorithm to validate the
 * syntax. If it is successful, it will break the statement into commands.
 */
void	parser_process(t_mini *mini)
{
	rdp_subprocess(mini);
	if (mini->parser->rdp->status == SUCCESS)
		cmds_subprocess(mini);
}

void	heredoc_write(t_mini *mini, t_redirect *redir)
{
	int		fd;

	fd = ft_open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd, mini->heredoc->heredoc, ft_strlen(mini->heredoc->heredoc));
	ft_close(fd);
}

void	heredoc_read(t_mini *mini, t_redirect *redir)
{
	char	*line;
	char	*delimiter;

	delimiter = redir->file;
	while (42)
	{
		line = readline(MULTILINE_PROMPT);
		mini->heredoc->heredoc = ft_strjoin(mini->heredoc->heredoc, line);
		if (ft_strcmp(line, delimiter) == 0)
			break ;
	}
	ft_free(redir->file);
	redir->file = ft_strjoin("/tmp/.mini.", ft_itoa(mini->heredoc->counter++));
}

void	heredoc_process(t_mini *mini)
{
	t_list		*node;
	t_redirect	*redir;

	node->next = mini->parser->cmds;
	while (node)
	{
		redir = (t_redirect *)node->content;
		heredoc_read(mini, redir);
		heredoc_write(mini, redir);
		node = node->next;
	}
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
		{
			if(mini->shared->does_statement_contain_heredoc)
				heredoc_process(mini);
			break ;
		}
	}
}

int	eval_cd(t_mini *mini, int argc, char **argv, char **envp)
{

}

int	eval_echo(t_mini *mini, int argc, char **argv, char **envp)
{

}

int	eval_env(t_mini *mini, int argc, char **argv, char **envp)
{

}

int	eval_exit(t_mini *mini, int argc, char **argv, char **envp)
{

}

int	eval_export(t_mini *mini, int argc, char **argv, char **envp)
{

}

int	eval_pwd(t_mini *mini, int argc, char **argv, char **envp)
{

}

int	eval_unset(t_mini *mini, int argc, char **argv, char **envp)
{

}

int	eval_is_special_builtin(t_command *cmd)
{
	char	*cmd_name;

	cmd_name = cmd->argv->content;
	if (ft_strcmp(cmd_name, "cd") == 0)
		return (TRUE);
	else if (ft_strcmp(cmd_name, "export") == 0)
		return (TRUE);
	else if (ft_strcmp(cmd_name, "unset") == 0)
		return (TRUE);
	else if (ft_strcmp(cmd_name, "exit") == 0)
		return (TRUE);
	else
		return (FALSE);
}

int	eval_is_builtin(t_command *cmd)
{
	char	*cmd_name;

	cmd_name = cmd->argv->content;
	if (ft_strcmp(cmd_name, "cd") == 0)
		return (TRUE);
	else if (ft_strcmp(cmd_name, "echo") == 0)
		return (TRUE);
	else if (ft_strcmp(cmd_name, "env") == 0)
		return (TRUE);
	else if (ft_strcmp(cmd_name, "exit") == 0)
		return (TRUE);
	else if (ft_strcmp(cmd_name, "export") == 0)
		return (TRUE);
	else if (ft_strcmp(cmd_name, "pwd") == 0)
		return (TRUE);
	else if (ft_strcmp(cmd_name, "unset") == 0)
		return (TRUE);
	else
		return (FALSE);

}

void	eval_special_builtin(t_mini *mini, int argc, char **argv, char **envp)
{
	if (ft_strcmp(argv[0], "cd") == 0)
		eval_cd(mini, argc, argv, envp);
	else if (ft_strcmp(argv[0], "export") == 0)
		eval_export(mini, argc, argv, envp);
	else if (ft_strcmp(argv[0], "unset") == 0)
		eval_unset(mini, argc, argv, envp);
	else if (ft_strcmp(argv[0], "exit") == 0)
		eval_exit(mini, argc, argv, envp);
}

void	eval_builtin(t_mini *mini, int argc, char **argv, char **envp)
{
	if (ft_strcmp(argv[0], "cd") == 0)
		eval_cd(mini, argc, argv, envp);
	else if (ft_strcmp(argv[0], "echo") == 0)
		eval_echo(mini, argc, argv, envp);
	else if (ft_strcmp(argv[0], "env") == 0)
		eval_env(mini, argc, argv, envp);
	else if (ft_strcmp(argv[0], "exit") == 0)
		eval_exit(mini, argc, argv, envp);
	else if (ft_strcmp(argv[0], "export") == 0)
		eval_export(mini, argc, argv, envp);
	else if (ft_strcmp(argv[0], "pwd") == 0)
		eval_pwd(mini, argc, argv, envp);
	else if (ft_strcmp(argv[0], "unset") == 0)
		eval_unset(mini, argc, argv, envp);
}

void	eval_executable(t_mini *mini, int argc, char **argv, char **envp)
{
	int		status;

	status = execve(argv[0], argv, envp);
	if (status == -1)
	{
		ft_putstr_fd("mini: command not found: ", STDERR_FILENO);
		ft_putstr_fd(argv[0], STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
}

int	eval_get_argc(t_command *cmd)
{
	return (ft_lstsize(cmd->argv));
}

char	**eval_get_argv(t_command *cmd)
{
	char	**argv;
	int		len;
	int		i;

	len = ft_lstsize(cmd->argv);
	argv = ft_calloc(len + 1, sizeof(char *));
	i = 0;
	while (i < len)
	{
		argv[i] = cmd->argv->content;
		i++;
	}
	return (argv);
}

char	**eval_get_envp(t_mini *mini)
{
	char	**envp;
	char	*tmp;
	int		len;
	int		i;

	len = mini->shared->env->length;
	envp = ft_calloc(len, sizeof(char *));
	i = 0;
	while (i < len)
	{
		tmp = ft_strjoin(mini->shared->env->entries[i].key, "=");
		envp[i] = ft_strjoin(tmp, mini->shared->env->entries[i].value);		
		ft_free(tmp);
		i++;
	}
	return (envp);
}

void	eval_special_builtin_redirects(t_mini *mini, t_command *cmd)
{
	(void)mini;
	(void)cmd;
	printf("TODO: eval_special_builtin_redirects\n");
}

void	eval_redirects(t_mini *mini, t_command *cmd)
{
	(void)mini;
	(void)cmd;
	printf("TODO: eval_redirects\n");
}

void	eval_in_current_process(t_mini *mini, t_command *cmd)
{
	int		argc;
	char	**argv;
	char	**envp;

	eval_special_builtin_redirects(mini, cmd);
	argc = eval_get_argc(cmd);
	argv = eval_get_argv(cmd);
	envp = eval_get_envp(mini);
	eval_special_builtin(mini, argc, argv, envp);
}

void	eval_in_new_process(t_mini *mini, t_command *cmd)
{
	int 	pid;
	int		argc;
	char	**argv;
	char	**envp;

	pid = ft_fork();
	if (pid == 0)
	{
		eval_redirects(mini, cmd);
		argc = eval_get_argc(cmd);
		argv = eval_get_argv(cmd);
		envp = eval_get_envp(mini);
		if (eval_is_builtin(cmd))
			eval_builtin(mini, argc, argv, envp);
		else
			eval_executable(mini, argc, argv, envp);
		ft_free(argv);
		ft_free(envp);
	}
	else
	{
		wait(&mini->shared->status);
	}
}

void	eval_create_pipes(t_mini *mini)
{
	int	i;
	int	len;

	len = ft_lstsize(mini->parser->cmds);
	mini->eval->pipes = ft_calloc(len - 1, sizeof(int));
	i = 0;
	while (i < len - 1)
	{
		ft_pipe(mini->eval->pipes + (2 * i));
		i++;
	}
}

void	eval_close_pipes(t_mini *mini)
{
	int	i;
	int	len;

	len = ft_lstsize(mini->parser->cmds);
	i = 0;
	while (i < len -1)
	{
		ft_close(mini->eval->pipes[i * 2]);
		ft_close(mini->eval->pipes[(i * 2) + 1]);
		i++;
	}
}

void	eval_statement(t_mini *mini)
{
	t_list		*node;
	t_command	*cmd;
	
	eval_create_pipes(mini);
	node = mini->parser->cmds;
	while (node)
	{
		cmd = (t_command *)node->content;
		if (eval_is_special_builtin(cmd))
			eval_in_current_process(mini, cmd);
		else
			eval_in_new_process(mini, cmd);
		node = node->next;
	}
	eval_close_pipes(mini);
}

void	eval_reset(t_eval *eval)
{
	(void)eval;
}

void	heredoc_reset(t_heredoc *heredoc)
{
	(void)heredoc;
}

void	parser_reset(t_parser *parser)
{
	(void)parser;
}

void	lexer_reset(t_lexer *lexer)
{
	(void)lexer;
}

void	reader_reset(t_reader *reader)
{
	(void)reader;
}

void	shared_reset(t_shared *shared)
{
	(void)shared;
}

void	mini_reset(t_mini *mini)
{
	shared_reset(mini->shared);
	reader_reset(mini->reader);
	lexer_reset(mini->lexer);
	parser_reset(mini->parser);
	heredoc_reset(mini->heredoc);
	eval_reset(mini->eval);
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
