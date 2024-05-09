/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:28:52 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/09 16:36:19 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32	syntax_error(char *token)
{
	// write_to_stdout(2, "minishell: syntax error near unexpected token '%s'\n" + token);
	return (set_exit_status(SYNTAX_ERROR));
}
