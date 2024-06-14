/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_env_val.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:08:51 by eduardocoel       #+#    #+#             */
/*   Updated: 2024/06/13 21:17:26 by eduardocoel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32	key_val(t_cstring *argv)
{
	t_i32	i;

	i = 0;
	if (!argv || ft_isdigit(argv[0]) || ft_isalnum(argv[0]) == 0)
		return (1);
	while (argv[i] && argv[i] != '=')
	{
		if (ft_isalnum(argv[i]) == 0 && argv[i] != '_')
			return (i);
		i++;
	}
	return (0);
}

t_i32	add_env_variable(t_i8 ***env, t_cstring variable_w_value)
{
	t_cstring_array	**new_env;
	t_i32			i;
	t_cstring		*variable_name;

	i = 0;
	if (!ft_strlen(variable_w_value) || !ft_strchr(variable_w_value, '=')
		|| ft_strchr(variable_w_value, '=') == variable_w_value)
		return (1);
	variable_name = ft_substr(variable_w_value, 0, (ft_strchr(variable_w_value,
				'=') - variable_w_value));
	if (!variable_name)
		return (2);
	i = find_env_var_index(*env, variable_name);
	free(variable_name);
	if ((*env)[i])
		update_env_var(*env, variable_w_value, i);
	else
	{
		new_env = append_new_env_var(*env, variable_w_value);
		if (!new_env)
			return (2);
		*env = new_env;
	}
	return (0);
}

t_i32	find_env_var_index(t_i8 **env, t_cstring var_name)
{
	t_i32	index;

	index = 0;
	while (env[index])
	{
		if (ft_strnstr(env[index], var_name, ft_strlen(var_name)))
			return (index);
		index++;
	}
	return (index);
}

static t_i32	update_env_var(t_i8 **env, t_cstring variable_w_value,
		t_i32 indexValue)
{
	t_cstring	newVariableEntry;

	newVariableEntry = ft_strdup(variable_w_value);
	if (!newVariableEntry)
		return (2);
	free(env[indexValue]);
	env[indexValue] = newVariableEntry;
	return (0);
}

static t_i8	**append_new_env_var(t_i8 **old_env, t_cstring *variable_w_value)
{
	t_i32		env_size;
	t_i32		stringCounter;
	t_i8		**newEnvironment;
	t_cstring	newVariableEntry;

	env_size = 0;
	stringCounter = 0;
	while (old_env[env_size])
		env_size++;
	newVariableEntry = ft_strdup(variable_w_value);
	newEnvironment = mini_alloc(env_size + 2, sizeof(*old_env));
	if (!newEnvironment || !newVariableEntry)
		return (NULL);
	while (stringCounter < env_size)
	{
		newEnvironment[stringCounter] = old_env[stringCounter];
		stringCounter++;
	}
	newEnvironment[stringCounter] = newVariableEntry;
	free(old_env);
	return (newEnvironment);
}

t_i32	restore_env_value(t_i8 ***env, t_cstring variable)
{
	t_cstring_array	new_env;
	t_i32			old_env_size;
	t_i32			variable_index;
	t_i32	i;
	
	i = 0;
	old_env_size = 0;
	variable_index = env_get_value_index(*env, variable);
	if (!(*env)[variable_index])
		return (0);
	while ((*env)[old_env_size])
		old_env_size++;
	new_env = mini_alloc(old_env_size, sizeof(*new_env));
	if (!new_env)
		return (2);
	while (i < old_env_size)
	{
		if (i != variable_index)
			new_env[i] = (*env)[i];
		i++;
	}
	free((*env)[variable_index]);
	free(*env);
	*env = new_env;
	return (0);
}
