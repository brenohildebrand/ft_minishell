/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:22:01 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/12 21:03:30 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>

# include "libft.h"

# define PROMPT "mini> "
# define MULTILINE_PROMPT "> "

# define TRUE 1
# define FALSE 0

# define SUCCESS 0
# define FAILURE 1
# define INCOMPLETE 2

# define WHITESPACE_S 0
# define WORD_S 1
# define REDIR_OUT_S 2
# define REDIR_IN_S 3
# define DOUBLE_QUOTES_S 4
# define SINGLE_QUOTES_S 5
# define PIPE_S 6

# define WORD_FS 100
# define REDIR_OUT_FS 101
# define REDIR_APPEND_FS 102
# define REDIR_IN_FS 103
# define REDIR_HEREDOC_FS 104
# define PIPE_FS 105
# define EMPTY_FS 108
# define INCOMPLETE_FS 200

# define WORD 1
# define REDIR_APPEND 2
# define REDIR_HEREDOC 3
# define REDIR_IN 4
# define REDIR_OUT 5
# define DOUBLE_QUOTES 6
# define SINGLE_QUOTES 7
# define PIPE 8

typedef struct s_shared		t_shared;

typedef struct s_reader		t_reader;

typedef struct s_lexer		t_lexer;
typedef struct s_automaton	t_automaton;
typedef struct s_token		t_token;

typedef struct s_parser		t_parser;
typedef struct s_rdp		t_rdp;
typedef struct s_command	t_command;
typedef struct s_redirect	t_redirect;

typedef struct s_heredoc	t_heredoc;

typedef struct s_eval		t_eval;

typedef struct s_mini		t_mini;

struct s_shared {
	int		argc;
	char	**argv;
	char	**envp;
	int		is_statement_complete;
	int		does_statement_contain_heredoc;
	t_list	*tokens;
	t_list	*commands;
	t_table	*env;
	int		status;
};

struct s_reader {
	char	*line;
	char	*statement;
};

struct s_lexer {
	t_automaton	*automaton;
};

struct s_automaton {
	int		start;
	int		end;
	int		state;
	int		status;
	t_list	*tokens;
	char	*cursor;
	int		table[7][8];
};

struct s_token {
	char	*str;
	int		type;
};

struct s_parser {
	t_list	*cmds;
	t_rdp	*rdp;
};

struct s_rdp {
	t_list	*node;
	char	*token;
	int		status;
};

struct s_command {
	t_list	*rdrcts;
	t_list	*argv;
};

struct s_redirect {
	int		type;
	char	*file;
};

struct s_heredoc {
	char	*delimiter;
	char	*heredoc;
	int		counter;
};

struct s_eval {
	int		pipe_fd[2];
	char	**paths;
	int		*pipes;
	int		redirs[2];
};

struct s_mini {
	t_shared	*shared;
	t_reader	*reader;
	t_lexer		*lexer;
	t_parser	*parser;
	t_heredoc	*heredoc;
	t_eval		*eval;
};

/* minishell.c */
t_table *shared_create_env(char **envp);
t_shared *shared_create(int argc, char **argv, char **envp);
t_reader *reader_create(void);
void automaton_create_table_2(t_automaton *automaton);
void automaton_create_table_1(t_automaton *automaton);
void automaton_create_table_0(t_automaton *automaton);
t_automaton *automaton_create(void);
t_lexer *lexer_create(void);
t_rdp *rdp_create(void);
t_parser *parser_create(void);
t_heredoc *heredoc_create(void);
t_mini *mini_create(int argc, char **argv, char **envp);
char *get_prompt(t_reader *reader);
void read_line(t_reader *reader);
int is_eof(t_reader *reader);
void update_statement(t_reader *reader);
int automaton_is_final_state(t_automaton *automaton);
int automaton_should_consider_last_character(t_automaton *automaton);
int automaton_typefy(t_automaton *automaton);
t_token *token_new(char *str, int type);
void token_del(void *content);
void automaton_reset(t_automaton *automaton, char *statement);
void automaton_delimit_with_last_char(t_automaton *automaton);
void automaton_delimit_without_last_char(t_automaton *automaton);
void automaton_delimit(t_automaton *automaton);
void automaton_exit(t_automaton *automaton);
void automaton_eval_final_state(t_automaton *automaton);
void automaton_eval_state(t_automaton *automaton);
void automaton_next_state(t_automaton *automaton);
void automaton_subprocess(t_automaton *automaton, char *statement);
void lexer_process(t_mini *mini);
int expansion_sub_env_get_end(t_token *token, int i);
char *mini_getenv(t_mini *mini, char *key);
char *expansion_sub_env_get_env(t_mini *mini, t_token *token, int start, int end);
void expansion_sub_env(t_mini *mini, t_token *token);
void expansion_rm_sq(t_token *token, int i, int *is_in_sq, int *is_in_dq);
void expansion_rm_dq(t_token *token, int i, int *is_in_sq, int *is_in_dq);
void expansion_rm_quotes(t_token *token);
void expansion_process(t_mini *mini);
int rdp_command(t_mini *mini, t_rdp *rdp);
int rdp_pipe_sequence(t_mini *mini, t_rdp *rdp);
void rdp_subprocess(t_mini *mini);
void cmds_build_command(t_mini *mini, t_list **node);
void cmds_subprocess(t_mini *mini);
void parser_process(t_mini *mini);
void heredoc_write(t_mini *mini, t_redirect *redir);
void heredoc_read(t_mini *mini, t_redirect *redir);
void heredoc_process(t_mini *mini);
void reader_process(t_mini *mini);
void read_statement(t_mini *mini);
int eval_is_special_builtin(t_command *cmd);
void eval_special_builtin(t_mini *mini, int argc, char **argv, char **envp);
void eval_builtin(t_mini *mini, int argc, char **argv, char **envp);
void eval_executable(t_mini *mini, int argc, char **argv, char **envp);
int eval_get_argc(t_command *cmd);
char **eval_get_argv(t_command *cmd);
char **eval_get_envp(t_mini *mini);
void eval_special_builtin_redirects(t_mini *mini, t_command *cmd);
void eval_redirects(t_mini *mini, t_command *cmd);
void eval_in_current_process(t_mini *mini, t_command *cmd);
void eval_in_new_process(t_mini *mini, t_command *cmd);
void eval_create_pipes(t_mini *mini);
void eval_close_pipes(t_mini *mini);
void eval_statement(t_mini *mini);
void eval_reset(t_eval *eval);
void heredoc_reset(t_heredoc *heredoc);
void parser_reset(t_parser *parser);
void lexer_reset(t_lexer *lexer);
void reader_reset(t_reader *reader);
void shared_reset(t_shared *shared);
void mini_reset(t_mini *mini);
int main(int argc, char **argv, char **envp);
int	rdp_is_word(t_rdp *rdp);
int	rdp_is_redir(t_rdp *rdp);
int	rdp_is_pipe(t_rdp *rdp);
void rdp_next_token(t_rdp *rdp);
void	rdp_reset(t_rdp *rdp);
void	rdp_print_syntax_error(t_rdp *rdp);

#endif