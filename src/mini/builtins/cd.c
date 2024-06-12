#include "minishell.h"

static	int	arg_error(void)
{
	write(2, "cd: too many arguments\n", 23);
	return (1);
}

static t_cstring	get_env(t_cstring_array env, t_cstring key)
{
	t_i32		i;
	t_i32		j;
	t_cstring	value;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] == key[j] && env[i][j] != '=')
			j++;
		if (env[i][j] == '=' && key[j] == '\0')
		{
			value = ft_strdup(env[i] + j + 1);
			return (value);
		}
		i++;
	}
	return (NULL);
}

t_i32	mini_eval_cd(t_mini mini, t_i32 argc, t_i8 **argv)
{
	t_cstring	path;

	(void)argc;
	path = NULL;
	if (argv[1] && argv[2])
		return (arg_error());
	if (argv[1] == NULL)
	{
		path = get_env((mini)->eval->env, "HOME");
		if (path == NULL)
		{
			write(1, "cd: HOME not set", 27);
			return (1);
		}
	}
	else
		path = ft_strdup(argv[1]);
	if (chdir(path) != 0)
	{
		write(2, " ", 1);
		write(2, strerror(errno), 1);
		write(2, "\n", 1);
		return (free(path), 1);
	}

	return (free(path), 0);
}
