/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:49:24 by eduardocoel       #+#    #+#             */
/*   Updated: 2024/06/14 18:35:02 by eduardocoel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32   mini_eval_unset(t_mini mini, t_i32 argc, t_i8 **argv)
{
    t_i32 i;
    t_i32 status;
    t_i32 unset_status;
 
    status = 0;
    if (argc < 2)
        return 1;
    i = 1;
    while(i < argc) 
    {
        unset_status = restore_env_value(&(mini->eval->env), argv[i]);
        if (unset_status != 0)
            status = unset_status;
        i++;
    }

    return status;
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
